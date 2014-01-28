#!/usr/bin/python -B

from string import Template, upper, replace

from ApiUtil import outputCode
from ApiUtil import typeIsVoid

from ApiCodeGen import *

from RegalContextInfo import cond

from RegalDispatchShared import dispatchSourceTemplate, apiDispatchFuncInitCode
from RegalDispatchShared import apiDispatchLayerConstructor

##############################################################################################

# CodeGen for API error checking function definition.

def apiErrorFuncDefineCode(apis, args):
  categoryPrev = None
  code = ''

  for api in apis:

    code += '\n'
    if api.name in cond:
      code += '#if %s\n' % cond[api.name]

    for function in api.functions:
      if not function.needsContext:
        continue
      if getattr(function,'regalOnly',False)==True:
        continue

      name   = function.name
      params = paramsDefaultCode(function.parameters, True, "Layer *_layer")
      callParams = paramsNameCode(function.parameters, "self->next")
      rType  = typeCode(function.ret.type)
      category  = getattr(function, 'category', None)
      version   = getattr(function, 'version', None)

      if category:
        category = category.replace('_DEPRECATED', '')
      elif version:
        category = version.replace('.', '_')
        category = 'GL_VERSION_' + category

      # Close prev category block.
      if categoryPrev and not (category == categoryPrev):
        code += '\n'

      # Begin new category block.
      if category and not (category == categoryPrev):
        code += '// %s\n\n' % category

      categoryPrev = category

      code += 'static %sREGAL_CALL %s%s(%s) \n{\n' % (rType, 'error_', name, params)
      code += '  Err * self = static_cast<Err *>( _layer );\n'
      if name != 'glGetError':
        code += '  GLenum _error = GL_NO_ERROR;\n'
        code += '  if (!self->inBeginEnd)\n'
        code += '    _error = RglGetError( self->next );\n'
        code += '  RegalAssert(_error==GL_NO_ERROR);\n'
        code += '  '
        if name == 'glBegin':
          code += 'self->inBeginEnd = true;\n'
        if not typeIsVoid(rType):
          code += '%s ret = ' % rType
        code += 'R%s(%s);\n' % ( name, callParams )
        if name == 'glEnd':
          code += 'self->inBeginEnd = false;\n'
        code += '  if (!self->inBeginEnd) {\n'
        code += '    _error = RglGetError( self->next );\n'
        code += '    if (_error!=GL_NO_ERROR) {\n'
        code += '      Error("%s : ",Token::GLerrorToString(_error));\n'%(name)
        code += '      #if REGAL_BREAK\n'
        code += '      Break::ErrorCB(_error);\n'
        code += '      #endif\n'
        code += '      if (self->callback)\n'
        code += '        self->callback( _error );\n'
        code += '    }\n'
        code += '  }\n'
        if not typeIsVoid(rType):
          code += 'return ret;\n'
      else:
        code += '  GLenum error = RglGetError( self->next );\n'
        code += '  return error;\n'
      code += '}\n\n'

    if api.name in cond:
      code += '#endif // %s\n' % cond[api.name]
    code += '\n'

  # Close pending if block.
  if categoryPrev:
    code += '\n'

  return code

localInclude = '''
#include "RegalContext.h"
#include "Error.h"
'''

localCode = '''

void InitDispatchError( Layer * layer, Dispatch::GL & tbl );

bool Err::Initialize( const std::string & instanceInfo ) {
  ResetInterception();
  return true;
}

void Err::ResetInterception() {
  RegalContext * ctx = GetContext();
  next = ctx->dispatchGL;
  InitDispatchError( this, ctx->dispatchGL );
}

'''

def generateErrorSource(apis, args):

  funcDefine = apiErrorFuncDefineCode( apis, args )
  funcInit   = apiDispatchFuncInitCode( apis, args, 'error' )

  substitute = {}
  substitute['LICENSE']         = args.license
  substitute['AUTOGENERATED']   = args.generated
  substitute['COPYRIGHT']       = args.copyright
  substitute['DISPATCH_NAME'] = 'Error'
  substitute['CONSTRUCTOR' ] = apiDispatchLayerConstructor( 'Err' )
  substitute['LOCAL_INCLUDE'] = localInclude
  substitute['LOCAL_CODE']    = localCode
  substitute['API_DISPATCH_FUNC_DEFINE'] = funcDefine
  substitute['API_DISPATCH_FUNC_INIT'] = funcInit
  substitute['API_DISPATCH_GLOBAL_FUNC_INIT'] = ''
  substitute['IFDEF'] = '#if REGAL_ERROR\n\n'
  substitute['ENDIF'] = '#endif\n'
  outputCode( '%s/layer/error/ErrorProcs.cpp' % args.srcdir, dispatchSourceTemplate.substitute(substitute))
