/*
    Copyright (c) 2007 SIEGE Development Team
    All rights reserved.

    This file is part of libSIEGE.

    This software is copyrighted work licensed under the terms of the
    2-clause BSD license. Please consult the file "license.txt" for
    details.

    If you did not recieve the file with this program, please email
    Tim Chas <darkuranium@gmail.com>.
*/

#define SG_BUILD_LIBRARY
#include <siege/graphics/texture.h>
#include <siege/core/window.h>
#include <siege/modules/graphics.h>

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

SGTexture* SG_EXPORT sgTextureCreateFile(const char* fname)
{
    SGuint width;
    SGuint height;
    SGuint bpp;
    void* data;

    SGuint ret;
    if(psgmGraphicsLoadFile != NULL)
        ret = psgmGraphicsLoadFile(fname, &width, &height, &bpp, &data);
    if((psgmGraphicsLoadFile == NULL) || (ret != SG_OK))
        fprintf(stderr, "Could not load image %s\n", fname);

    SGTexture* texture = sgTextureCreateData(width, height, bpp, data);
    if(psgmGraphicsLoadFreeData != NULL)
        psgmGraphicsLoadFreeData(data);
    return texture;
}
SGTexture* SG_EXPORT sgTextureCreateData(SGuint width, SGuint height, SGenum bpp, void* data)
{
    SGTexture* texture = malloc(sizeof(SGTexture));
    if(texture == NULL)
        return NULL;

    if(psgmGraphicsTextureCreate != NULL)
        psgmGraphicsTextureCreate(&texture->handle, _sg_gfxHandle);
    if(psgmGraphicsTextureSetData != NULL)
        psgmGraphicsTextureSetData(texture->handle, width, height, bpp, data);

    return texture;
}
SGTexture* SG_EXPORT sgTextureCreate(SGuint width, SGuint height, SGenum bpp)
{
    return sgTextureCreateData(width, height, bpp, NULL);
}
void SG_EXPORT sgTextureDestroy(SGTexture* texture)
{
    if(!texture)
        return;

    if(psgmGraphicsTextureDestroy != NULL)
        psgmGraphicsTextureDestroy(texture->handle);
    free(texture);
}

void SG_EXPORT sgTextureDrawRads3f2f2f1f(SGTexture* texture, float x, float y, float z, float xscale, float yscale, float xoffset, float yoffset, float angle)
{
    if(psgmGraphicsTextureDraw != NULL)
        psgmGraphicsTextureDraw(texture->handle, x, y, z, xscale, yscale, xoffset, yoffset, angle);
}
void SG_EXPORT sgTextureDrawDegs3f2f2f1f(SGTexture* texture, float x, float y, float z, float xscale, float yscale, float xoffset, float yoffset, float angle)
{
    sgTextureDrawRads3f2f2f1f(texture, x, y, z, xscale, yscale, xoffset, yoffset, angle * SG_PI / 180.0);
}
void SG_EXPORT sgTextureDrawRads2f2f2f1f(SGTexture* texture, float x, float y, float xscale, float yscale, float xoffset, float yoffset, float angle)
{
    sgTextureDrawRads3f2f2f1f(texture, x, y, 0.0, xscale, yscale, xoffset, yoffset, angle);
}
void SG_EXPORT sgTextureDrawDegs2f2f2f1f(SGTexture* texture, float x, float y, float xscale, float yscale, float xoffset, float yoffset, float angle)
{
    sgTextureDrawDegs3f2f2f1f(texture, x, y, 0.0, xscale, yscale, xoffset, yoffset, angle);
}
void SG_EXPORT sgTextureDrawRads3f2f1f(SGTexture* texture, float x, float y, float z, float xscale, float yscale, float angle)
{
    sgTextureDrawRads3f2f2f1f(texture, x, y, z, xscale, yscale, 0.0, 0.0, angle);
}
void SG_EXPORT sgTextureDrawDegs3f2f1f(SGTexture* texture, float x, float y, float z, float xscale, float yscale, float angle)
{
    sgTextureDrawDegs3f2f2f1f(texture, x, y, z, xscale, yscale, 0.0, 0.0, angle);
}
void SG_EXPORT sgTextureDrawRads2f2f1f(SGTexture* texture, float x, float y, float xscale, float yscale, float angle)
{
    sgTextureDrawRads3f2f2f1f(texture, x, y, 0.0, xscale, yscale, 0.0, 0.0, angle);
}
void SG_EXPORT sgTextureDrawDegs2f2f1f(SGTexture* texture, float x, float y, float xscale, float yscale, float angle)
{
    sgTextureDrawDegs3f2f2f1f(texture, x, y, 0.0, xscale, yscale, 0.0, 0.0, angle);
}
void SG_EXPORT sgTextureDrawRads3f1f(SGTexture* texture, float x, float y, float z, float angle)
{
    sgTextureDrawRads3f2f2f1f(texture, x, y, z, 1.0, 1.0, 0.0, 0.0, angle);
}
void SG_EXPORT sgTextureDrawDegs3f1f(SGTexture* texture, float x, float y, float z, float angle)
{
    sgTextureDrawDegs3f2f2f1f(texture, x, y, z, 1.0, 1.0, 0.0, 0.0, angle);
}
void SG_EXPORT sgTextureDrawRads2f1f(SGTexture* texture, float x, float y, float angle)
{
    sgTextureDrawRads3f2f2f1f(texture, x, y, 0.0, 1.0, 1.0, 0.0, 0.0, angle);
}
void SG_EXPORT sgTextureDrawDegs2f1f(SGTexture* texture, float x, float y, float angle)
{
    sgTextureDrawDegs3f2f2f1f(texture, x, y, 0.0, 1.0, 1.0, 0.0, 0.0, angle);
}
void SG_EXPORT sgTextureDraw3f2f2f(SGTexture* texture, float x, float y, float z, float xscale, float yscale, float xoffset, float yoffset)
{
    sgTextureDrawRads3f2f2f1f(texture, x, y, z, xscale, yscale, xoffset, yoffset, 0.0);
}
void SG_EXPORT sgTextureDraw2f2f2f(SGTexture* texture, float x, float y, float xscale, float yscale, float xoffset, float yoffset)
{
    sgTextureDrawRads3f2f2f1f(texture, x, y, 0.0, xscale, yscale, xoffset, yoffset, 0.0);
}
void SG_EXPORT sgTextureDraw3f2f(SGTexture* texture, float x, float y, float z, float xscale, float yscale)
{
    sgTextureDrawRads3f2f2f1f(texture, x, y, z, xscale, yscale, 0.0, 0.0, 0.0);
}
void SG_EXPORT sgTextureDraw2f2f(SGTexture* texture, float x, float y, float xscale, float yscale)
{
    sgTextureDrawRads3f2f2f1f(texture, x, y, 0.0, xscale, yscale, 0.0, 0.0, 0.0);
}
void SG_EXPORT sgTextureDraw3f(SGTexture* texture, float x, float y, float z)
{
    sgTextureDrawRads3f2f2f1f(texture, x, y, z, 1.0, 1.0, 0.0, 0.0, 0.0);
}
void SG_EXPORT sgTextureDraw2f(SGTexture* texture, float x, float y)
{
    sgTextureDrawRads3f2f2f1f(texture, x, y, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0);
}
void SG_EXPORT sgTextureDraw(SGTexture* texture)
{
    sgTextureDrawRads3f2f2f1f(texture, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f);
}

void SG_EXPORT sgTextureSetWrap(SGTexture* texture, SGenum swrap, SGenum twrap)
{
    if(psgmGraphicsTextureSetWrap)
        psgmGraphicsTextureSetWrap(texture->handle, swrap, twrap);
}

void SG_EXPORT sgTextureGetSize(SGTexture* texture, SGuint* width, SGuint* height)
{
    if((width == NULL) && (height == NULL))
        return;
    SGuint tmp;

    // make sure we don't pass any nulls
    if(width == NULL)
        width = &tmp;
    if(height == NULL)
        height = &tmp;

    if(psgmGraphicsTextureGetSize != NULL)
        psgmGraphicsTextureGetSize(texture->handle, width, height);
}
SGuint SG_EXPORT sgTextureGetWidth(SGTexture* texture)
{
    SGuint width;
    SGuint height;
    if(psgmGraphicsTextureGetSize != NULL)
        psgmGraphicsTextureGetSize(texture->handle, &width, &height);
    return width;
}
SGuint SG_EXPORT sgTextureGetHeight(SGTexture* texture)
{
    SGuint width;
    SGuint height;
    if(psgmGraphicsTextureGetSize != NULL)
        psgmGraphicsTextureGetSize(texture->handle, &width, &height);
    return height;
}
