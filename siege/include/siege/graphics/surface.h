#ifndef __SIEGE_GRAPHICS_SURFACE_H__
#define __SIEGE_GRAPHICS_SURFACE_H__

#include "../common.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

typedef struct SGSurface
{
    void* handle;
} SGSurface;

#ifdef SG_BUILD_LIBRARY
void* _sg_surfTarget;
#endif // SGC_BUILD_LIBRARY

SGbool SG_EXPORT _sgSurfaceInit();
SGbool SG_EXPORT _sgSurfaceDeinit();

SGSurface* SG_EXPORT sgSurfaceCreateFile(char* fname);
SGSurface* SG_EXPORT sgSurfaceCreateData(SGuint width, SGuint height, SGenum bpp, void* data);
SGSurface* SG_EXPORT sgSurfaceCreate(SGuint width, SGuint height, SGenum bpp);
void SG_EXPORT sgSurfaceDestroy(SGSurface* surface);

void SG_EXPORT sgSurfaceDrawRads3f2f2f1f(SGSurface* surface, float x, float y, float z, float xscale, float yscale, float xoffset, float yoffset, float angle);
void SG_EXPORT sgSurfaceDrawDegs3f2f2f1f(SGSurface* surface, float x, float y, float z, float xscale, float yscale, float xoffset, float yoffset, float angle);
void SG_EXPORT sgSurfaceDrawRads2f2f2f1f(SGSurface* surface, float x, float y, float xscale, float yscale, float xoffset, float yoffset, float angle);
void SG_EXPORT sgSurfaceDrawDegs2f2f2f1f(SGSurface* surface, float x, float y, float xscale, float yscale, float xoffset, float yoffset, float angle);
void SG_EXPORT sgSurfaceDrawRads3f2f1f(SGSurface* surface, float x, float y, float z, float xscale, float yscale, float angle);
void SG_EXPORT sgSurfaceDrawDegs3f2f1f(SGSurface* surface, float x, float y, float z, float xscale, float yscale, float angle);
void SG_EXPORT sgSurfaceDrawRads2f2f1f(SGSurface* surface, float x, float y, float xscale, float yscale, float angle);
void SG_EXPORT sgSurfaceDrawDegs2f2f1f(SGSurface* surface, float x, float y, float xscale, float yscale, float angle);
void SG_EXPORT sgSurfaceDrawRads3f1f(SGSurface* surface, float x, float y, float z, float angle);
void SG_EXPORT sgSurfaceDrawDegs3f1f(SGSurface* surface, float x, float y, float z, float angle);
void SG_EXPORT sgSurfaceDrawRads2f1f(SGSurface* surface, float x, float y, float angle);
void SG_EXPORT sgSurfaceDrawDegs2f1f(SGSurface* surface, float x, float y, float angle);
void SG_EXPORT sgSurfaceDraw3f2f2f(SGSurface* surface, float x, float y, float z, float xscale, float yscale, float xoffset, float yoffset);
void SG_EXPORT sgSurfaceDraw2f2f2f(SGSurface* surface, float x, float y, float xscale, float yscale, float xoffset, float yoffset);
void SG_EXPORT sgSurfaceDraw3f2f(SGSurface* surface, float x, float y, float z, float xscale, float yscale);
void SG_EXPORT sgSurfaceDraw2f2f(SGSurface* surface, float x, float y, float xscale, float yscale);
void SG_EXPORT sgSurfaceDraw3f(SGSurface* surface, float x, float y, float z);
void SG_EXPORT sgSurfaceDraw2f(SGSurface* surface, float x, float y);
void SG_EXPORT sgSurfaceDraw(SGSurface* surface);

void SG_EXPORT sgSurfaceTarget(SGSurface* surface);
void SG_EXPORT sgSurfaceUntarget(SGSurface* surface);
void SG_EXPORT sgSurfaceClear4f(SGSurface* surface, float r, float g, float b, float a);
void SG_EXPORT sgSurfaceClear3f(SGSurface* surface, float r, float g, float b);
void SG_EXPORT sgSurfaceClear2f(SGSurface* surface, float g, float a);
void SG_EXPORT sgSurfaceClear1f(SGSurface* surface, float g);
void SG_EXPORT sgSurfaceClear4ub(SGSurface* surface, SGubyte r, SGubyte g, SGubyte b, SGubyte a);
void SG_EXPORT sgSurfaceClear3ub(SGSurface* surface, SGubyte r, SGubyte g, SGubyte b);
void SG_EXPORT sgSurfaceClear2ub(SGSurface* surface, SGubyte g, SGubyte a);
void SG_EXPORT sgSurfaceClear1ub(SGSurface* surface, SGubyte g);
void SG_EXPORT sgSurfaceClear(SGSurface* surface);

void SG_EXPORT sgSurfaceGetSize(SGSurface* surface, SGuint* width, SGuint* height);
SGuint SG_EXPORT sgSurfaceGetWidth(SGSurface* surface);
SGuint SG_EXPORT sgSurfaceGetHeight(SGSurface* surface);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __SIEGE_GRAPHICS_SURFACE_H__