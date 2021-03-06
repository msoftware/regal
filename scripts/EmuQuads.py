#!/usr/bin/python -B

quadsFormulae = {
  'EnableDisable' : {
    'entries' : [ 'gl(En|Dis)able' ],
    'prefix'  : [ '_context->quads->gl${m1}able( ${arg0plus} );', ],
  },
  'CullFrontFace' : {
    'entries'    : [ 'gl(Cull|Front)Face' ],
    'prefix'     : [ '_context->quads->gl${m1}Face( ${arg0plus} );', ],
  },
  'PolygonMode' : {
    'entries'    : [ 'glPolygonMode' ],
    'prefix'     : [ '_context->quads->glPolygonMode( ${arg0plus} );', ],
  },
  'ShadeModel' : {
    'entries'    : [ 'glShadeModel' ],
    'prefix'     : [ '_context->quads->glShadeModel( ${arg0plus} );', ],
  },
  'ProvokingVertex' : {
    'entries'    : [ 'glProvokingVertex(EXT|)' ],
    'prefix'     : [ '_context->quads->glProvokingVertex( ${arg0plus} );', ],
  },
  'BindBuffer' : {
    'entries'    : [ 'glBindBuffer(EXT|)' ],
    'prefix'     : [ '_context->quads->glBindBuffer( ${arg0plus} );', ],
  },
  'quads'       : {
    'entries' : [ 'glDrawArrays(EXT|)' ],
    'impl'    : [
'''
if ( ! _context->quads->glDrawArrays( _context, ${arg0plus} ) ) {
  _context->dispatcher.emulation.glDrawArrays( ${arg0plus} );
}
'''
    ],
  },
}
