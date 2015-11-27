#!/usr/bin/python -B

ppcFormulae = {
    'PushClientAttrib' : {
        'entries' : [ 'glPushClientAttrib' ],
        'impl' : [ 'rCtx->ppc->PushClientAttrib( rCtx, ${arg0plus} );', ],
    },
    'PopClientAttrib' : {
        'entries' : [ 'glPopClientAttrib' ],
        'impl' : [ 'rCtx->ppc->PopClientAttrib( rCtx );', ],
    },
    'PixelStore' : {
        'entries' : [ 'glPixelStore(i|f)' ],
        'prefix' : [ 'rCtx->ppc->PixelStore( rCtx, ${arg0plus} );' ],
    },
    'InterleavedArrays' : {
        'entries' : [ 'glInterleavedArrays' ],
        'prefix' : [ 'rCtx->ppc->InterleavedArrays( rCtx, ${arg0plus} );' ],
    },
    'EnableDisable' : {
        'entries' : [ 'gl(Enable|Disable)' ],
        'prefix' : [ 'rCtx->ppc->${m1}( rCtx, ${arg0} );' ],
    },
    'EnableDisableClientState' : {
        'entries' : [ 'gl(Enable|Disable)ClientState' ],
        'prefix' : [ 'rCtx->ppc->${m1}ClientState( rCtx, ${arg0} );' ],
    },
    'EnableDisableVertexAttribArray' : {
        'entries' : [ 'gl(Enable|Disable)VertexAttribArray(ARB|)' ],
        'prefix' : [ 'rCtx->ppc->${m1}VertexAttribArray( rCtx, ${arg0} );' ],
    },
    'ClientActiveTexture' : {
        'entries' : [ 'glClientActiveTexture(ARB|)' ],
        'prefix' : [ 'rCtx->ppc->ClientActiveTexture( rCtx, ${arg0} );' ],
    },
    'Pointer4' : {
        'entries' : [ 'gl(Color|SecondaryColor|TexCoord|Vertex)Pointer' ],
        'prefix' : [ 'rCtx->ppc->${m1}Pointer( rCtx, ${arg0}, ${arg1}, ${arg2}, ${arg3} );' ],
    },
    'Pointer3' : {
        'entries' : [ 'gl(FogCoord|Index|Normal)Pointer' ],
        'prefix' : [ 'rCtx->ppc->${m1}Pointer( rCtx, ${arg0}, ${arg1}, ${arg2} );' ],
    },
    'Pointer2' : {
        'entries' : [ 'glEdgeFlagPointer' ],
        'prefix' : [ 'rCtx->ppc->EdgeFlagPointer( rCtx, ${arg0}, ${arg1} );' ],
    },
    'BindBuffer' : {
        'entries' : [ 'glBindBuffer(ARB|)' ],
        'prefix' : [ 'rCtx->ppc->BindBuffer( rCtx, ${arg0plus} );' ],
    },
    'DeleteBuffers' : {
        'entries' : [ 'glDeleteBuffers(ARB|)' ],
        'prefix' : [ 'rCtx->ppc->DeleteBuffers( rCtx, ${arg0plus} );' ],
    },
    'BindVertexArray' : {
        'entries' : [ 'glBindVertexArray(ARB|)' ],
        'impl' : [ 'rCtx->ppc->BindVertexArray( rCtx, ${arg0plus} );' ],
    },
    'DeleteVertexArrays' : {
        'entries' : [ 'glDeleteVertexArrays(ARB|)' ],
        'prefix' : [ 'rCtx->ppc->DeleteVertexArrays( rCtx, ${arg0plus} );' ],
    },
    'VertexAttribPointer' : {
        'entries' : [ 'glVertexAttribPointer(ARB|)' ],
        'prefix' : [ 'rCtx->ppc->VertexAttribPointer( rCtx, ${arg0plus} );' ],
    },
    'VertexAttribIPointer' : {
        'entries' : [ 'glVertexAttribIPointer(EXT|)' ],
        'prefix' : [ 'rCtx->ppc->VertexAttribIPointer( rCtx, ${arg0plus} );' ],
    },
    'VertexAttribDivisor' : {
        'entries' : [ 'glVertexAttribDivisor' ],
        'prefix' : [ 'rCtx->ppc->VertexAttribDivisor( rCtx, ${arg0plus} );' ],
    },
    'PrimitiveRestartIndex(' : {
        'entries' : [ 'glPrimitiveRestartIndex' ],
        'prefix' : [ 'rCtx->ppc->PrimitiveRestartIndex( rCtx, ${arg0plus} );' ],
    },
    'Get' : {
        'entries' : [ 'glGet(Boolean|Double|Float|Integer|Integer64)v' ],
        'impl' : [
            'if ( !rCtx->ppc->Get( ${arg0plus} ) ) {',
            '   orig.glGet${m1}v( _context, ${arg0plus} );',
            '}',
        ]
    },
    'GetIndexed' : {
        'entries' : [ 'glGet(Boolean|Double|Float|Integer|Integer64)i_v(EXT|)' ],
        'impl' : [
            'if ( !rCtx->ppc->GetIndexed( ${arg0plus} ) ) {',
            '   orig.glGet${m1}i_v( ${arg0plus} );',
            '}',
        ]
    },
    'GetPointerv' : {
        'entries' : [ 'glGetPointerv' ],
        'impl' : [
            'if ( !rCtx->ppc->GetPointerv( ${arg0plus} ) ) {',
            '   orig.glGetPointerv( _context, ${arg0plus} );',
            '}',
        ]
    },
    'IsEnabled' : {
        'entries' : [ 'glIsEnabled' ],
        'impl' : [
            '{',
            '    GLboolean enabled;',
            '    if ( !rCtx->ppc->IsEnabled( ${arg0plus}, enabled ) )',
            '        return orig.glIsEnabled( _context, ${arg0plus} );',
            '    return enabled;',
            '}',
        ]
    },
    'IsEnabledi' : {
        'entries' : [ 'glIsEnabledi' ],
        'impl' : [
            '//{',
            '    GLboolean enabled;',
            '    if ( !rCtx->ppc->IsEnabledIndexed( ${arg0plus}, enabled ) )',
            '        return orig.glIsEnabledi( _context, ${arg0plus} );',
            '    return enabled;',
            '//}',
        ]
    },
    'GetVertexAttribPointerv' : {
        'entries' : [ 'glGetVertexAttribPointerv(ARB|EXT|)' ],
        'impl' : [
            'if ( !rCtx->ppc->GetVertexAttribPointerv( ${arg0plus} ) ) {',
            '   orig.glGetVertexAttribPointerv${m1}( _context, ${arg0plus} );',
            '}',
        ]
    },
    'GetVertexAttribv' : {
        'entries' : [ 'glGetVertexAttrib(d|f|i)v(ARB|)' ],
        'impl' : [
            'if ( !rCtx->ppc->GetVertexAttribv( ${arg0plus} ) ) {',
            '   orig.glGetVertexAttrib${m1}v${m2}( _context, ${arg0plus} );',
            '}',
        ]
    },
}