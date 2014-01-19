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
#include "RegalQuads.h"
#include "RegalEmuProcsQuads.h"

REGAL_GLOBAL_END

REGAL_NAMESPACE_BEGIN

static void REGAL_CALL emuProcInterceptQuads_glBindBuffer(RegalContext *_context, GLenum target, GLuint buffer)
{
  RegalAssert(_context);
  EmuProcsOriginateQuads & orig = _context->quads->orig;

  // prefix
  _context->quads->glBindBuffer( target, buffer );

  orig.glBindBuffer( _context, target, buffer );

}

static void REGAL_CALL emuProcInterceptQuads_glCullFace(RegalContext *_context, GLenum mode)
{
  RegalAssert(_context);
  EmuProcsOriginateQuads & orig = _context->quads->orig;

  // prefix
  _context->quads->glCullFace( mode );

  orig.glCullFace( _context, mode );

}

static void REGAL_CALL emuProcInterceptQuads_glDisable(RegalContext *_context, GLenum cap)
{
  RegalAssert(_context);
  EmuProcsOriginateQuads & orig = _context->quads->orig;

  // prefix
  _context->quads->glDisable( cap );

  orig.glDisable( _context, cap );

}

static void REGAL_CALL emuProcInterceptQuads_glDrawArrays(RegalContext *_context, GLenum mode, GLint first, GLsizei count)
{
  RegalAssert(_context);
  EmuProcsOriginateQuads & orig = _context->quads->orig;

  // impl

  if ( _context->quads->glDrawArrays( _context, mode, first, count ) ) {
    return;
  }

  orig.glDrawArrays( _context, mode, first, count );

}

static void REGAL_CALL emuProcInterceptQuads_glDrawArraysEXT(RegalContext *_context, GLenum mode, GLint first, GLsizei count)
{
  RegalAssert(_context);
  EmuProcsOriginateQuads & orig = _context->quads->orig;

  // impl

  if ( _context->quads->glDrawArrays( _context, mode, first, count ) ) {
    return;
  }

  orig.glDrawArraysEXT( _context, mode, first, count );

}

static void REGAL_CALL emuProcInterceptQuads_glEnable(RegalContext *_context, GLenum cap)
{
  RegalAssert(_context);
  EmuProcsOriginateQuads & orig = _context->quads->orig;

  // prefix
  _context->quads->glEnable( cap );

  orig.glEnable( _context, cap );

}

static void REGAL_CALL emuProcInterceptQuads_glFrontFace(RegalContext *_context, GLenum mode)
{
  RegalAssert(_context);
  EmuProcsOriginateQuads & orig = _context->quads->orig;

  // prefix
  _context->quads->glFrontFace( mode );

  orig.glFrontFace( _context, mode );

}

static void REGAL_CALL emuProcInterceptQuads_glPolygonMode(RegalContext *_context, GLenum face, GLenum mode)
{
  RegalAssert(_context);
  EmuProcsOriginateQuads & orig = _context->quads->orig;

  // prefix
  _context->quads->glPolygonMode( face, mode );

  orig.glPolygonMode( _context, face, mode );

}

static void REGAL_CALL emuProcInterceptQuads_glProvokingVertex(RegalContext *_context, GLenum mode)
{
  RegalAssert(_context);
  EmuProcsOriginateQuads & orig = _context->quads->orig;

  // prefix
  _context->quads->glProvokingVertex( mode );

  orig.glProvokingVertex( _context, mode );

}

static void REGAL_CALL emuProcInterceptQuads_glProvokingVertexEXT(RegalContext *_context, GLenum mode)
{
  RegalAssert(_context);
  EmuProcsOriginateQuads & orig = _context->quads->orig;

  // prefix
  _context->quads->glProvokingVertex( mode );

  orig.glProvokingVertexEXT( _context, mode );

}

static void REGAL_CALL emuProcInterceptQuads_glShadeModel(RegalContext *_context, GLenum mode)
{
  RegalAssert(_context);
  EmuProcsOriginateQuads & orig = _context->quads->orig;

  // prefix
  _context->quads->glShadeModel( mode );

  orig.glShadeModel( _context, mode );

}

void EmuProcsInterceptQuads( Dispatch::GL & dt ) {
  dt.glBindBuffer         = emuProcInterceptQuads_glBindBuffer;
  dt.glCullFace           = emuProcInterceptQuads_glCullFace;
  dt.glDisable            = emuProcInterceptQuads_glDisable;
  dt.glDrawArrays         = emuProcInterceptQuads_glDrawArrays;
  dt.glDrawArraysEXT      = emuProcInterceptQuads_glDrawArraysEXT;
  dt.glEnable             = emuProcInterceptQuads_glEnable;
  dt.glFrontFace          = emuProcInterceptQuads_glFrontFace;
  dt.glPolygonMode        = emuProcInterceptQuads_glPolygonMode;
  dt.glProvokingVertex    = emuProcInterceptQuads_glProvokingVertex;
  dt.glProvokingVertexEXT = emuProcInterceptQuads_glProvokingVertexEXT;
  dt.glShadeModel         = emuProcInterceptQuads_glShadeModel;
}

REGAL_NAMESPACE_END

#endif // REGAL_EMULATION
