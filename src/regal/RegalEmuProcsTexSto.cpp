/* NOTE: Do not edit this file, it is generated by a script:
   Export.py --api gl 4.4 --api wgl 4.4 --api glx 4.4 --api cgl 1.4 --api egl 1.0 --outdir .
*/

/*
  Copyright (c) 2011-2013 NVIDIA Corporation
  Copyright (c) 2011-2013 Cass Everitt
  Copyright (c) 2012-2013 Scott Nations
  Copyright (c) 2012 Mathias Schott
  Copyright (c) 2012-2013 Nigel Stewart
  Copyright (c) 2012-2013 Google Inc.
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification,
  are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.

    Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
  OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
  Intended formatting conventions:
  $ astyle --style=allman --indent=spaces=2 --indent-switches
*/

#include "RegalUtil.h"

#if REGAL_EMULATION

REGAL_GLOBAL_BEGIN

#include "RegalPrivate.h"
#include "RegalContext.h"
#include "RegalDispatch.h"
#include "RegalTexSto.h"
#include "RegalEmuProcsTexSto.h"

REGAL_GLOBAL_END

REGAL_NAMESPACE_BEGIN

static void REGAL_CALL emuProcInterceptTexSto_glDeleteTextures(RegalContext *_context, GLsizei n, const GLuint *textures)
{
  RegalAssert(_context);
  EmuProcsOriginateTexSto & orig = _context->texsto->orig;

  // prefix
  _context->texsto->DeleteTextures( _context, n, textures );

  orig.glDeleteTextures( _context, n, textures );

}

static void REGAL_CALL emuProcInterceptTexSto_glGetTexParameterIiv(RegalContext *_context, GLenum target, GLenum pname, GLint *params)
{
  RegalAssert(_context);
  EmuProcsOriginateTexSto & orig = _context->texsto->orig;

  // impl
  if ( _context->texsto->GetTexParameterv( _context, target, pname, params ) ) {
     return;
  }

  orig.glGetTexParameterIiv( _context, target, pname, params );

}

static void REGAL_CALL emuProcInterceptTexSto_glGetTexParameterIuiv(RegalContext *_context, GLenum target, GLenum pname, GLuint *params)
{
  RegalAssert(_context);
  EmuProcsOriginateTexSto & orig = _context->texsto->orig;

  // impl
  if ( _context->texsto->GetTexParameterv( _context, target, pname, params ) ) {
     return;
  }

  orig.glGetTexParameterIuiv( _context, target, pname, params );

}

static void REGAL_CALL emuProcInterceptTexSto_glGetTexParameterfv(RegalContext *_context, GLenum target, GLenum pname, GLfloat *params)
{
  RegalAssert(_context);
  EmuProcsOriginateTexSto & orig = _context->texsto->orig;

  // impl
  if ( _context->texsto->GetTexParameterv( _context, target, pname, params ) ) {
     return;
  }

  orig.glGetTexParameterfv( _context, target, pname, params );

}

static void REGAL_CALL emuProcInterceptTexSto_glGetTexParameteriv(RegalContext *_context, GLenum target, GLenum pname, GLint *params)
{
  RegalAssert(_context);
  EmuProcsOriginateTexSto & orig = _context->texsto->orig;

  // impl
  if ( _context->texsto->GetTexParameterv( _context, target, pname, params ) ) {
     return;
  }

  orig.glGetTexParameteriv( _context, target, pname, params );

}

static void REGAL_CALL emuProcInterceptTexSto_glTexStorage1D(RegalContext *_context, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width)
{
  RegalAssert(_context);
  EmuProcsOriginateTexSto & orig = _context->texsto->orig;

  // impl
  _context->texsto->TextureStorage( _context, target, levels, internalformat, width ); return;

  orig.glTexStorage1D( _context, target, levels, internalformat, width );

}

static void REGAL_CALL emuProcInterceptTexSto_glTexStorage1DEXT(RegalContext *_context, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width)
{
  RegalAssert(_context);
  EmuProcsOriginateTexSto & orig = _context->texsto->orig;

  // impl
  _context->texsto->TextureStorage( _context, target, levels, internalformat, width ); return;

  orig.glTexStorage1DEXT( _context, target, levels, internalformat, width );

}

static void REGAL_CALL emuProcInterceptTexSto_glTexStorage2D(RegalContext *_context, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
{
  RegalAssert(_context);
  EmuProcsOriginateTexSto & orig = _context->texsto->orig;

  // impl
  _context->texsto->TextureStorage( _context, target, levels, internalformat, width, height ); return;

  orig.glTexStorage2D( _context, target, levels, internalformat, width, height );

}

static void REGAL_CALL emuProcInterceptTexSto_glTexStorage2DEXT(RegalContext *_context, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
{
  RegalAssert(_context);
  EmuProcsOriginateTexSto & orig = _context->texsto->orig;

  // impl
  _context->texsto->TextureStorage( _context, target, levels, internalformat, width, height ); return;

  orig.glTexStorage2DEXT( _context, target, levels, internalformat, width, height );

}

static void REGAL_CALL emuProcInterceptTexSto_glTexStorage3D(RegalContext *_context, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
{
  RegalAssert(_context);
  EmuProcsOriginateTexSto & orig = _context->texsto->orig;

  // impl
  _context->texsto->TextureStorage( _context, target, levels, internalformat, width, height, depth ); return;

  orig.glTexStorage3D( _context, target, levels, internalformat, width, height, depth );

}

static void REGAL_CALL emuProcInterceptTexSto_glTexStorage3DEXT(RegalContext *_context, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
{
  RegalAssert(_context);
  EmuProcsOriginateTexSto & orig = _context->texsto->orig;

  // impl
  _context->texsto->TextureStorage( _context, target, levels, internalformat, width, height, depth ); return;

  orig.glTexStorage3DEXT( _context, target, levels, internalformat, width, height, depth );

}

void EmuProcsInterceptTexSto( Dispatch::GL & dt ) {
  dt.glDeleteTextures      = emuProcInterceptTexSto_glDeleteTextures;
  dt.glGetTexParameterIiv  = emuProcInterceptTexSto_glGetTexParameterIiv;
  dt.glGetTexParameterIuiv = emuProcInterceptTexSto_glGetTexParameterIuiv;
  dt.glGetTexParameterfv   = emuProcInterceptTexSto_glGetTexParameterfv;
  dt.glGetTexParameteriv   = emuProcInterceptTexSto_glGetTexParameteriv;
  dt.glTexStorage1D        = emuProcInterceptTexSto_glTexStorage1D;
  dt.glTexStorage1DEXT     = emuProcInterceptTexSto_glTexStorage1DEXT;
  dt.glTexStorage2D        = emuProcInterceptTexSto_glTexStorage2D;
  dt.glTexStorage2DEXT     = emuProcInterceptTexSto_glTexStorage2DEXT;
  dt.glTexStorage3D        = emuProcInterceptTexSto_glTexStorage3D;
  dt.glTexStorage3DEXT     = emuProcInterceptTexSto_glTexStorage3DEXT;
}

REGAL_NAMESPACE_END

#endif // REGAL_EMULATION
