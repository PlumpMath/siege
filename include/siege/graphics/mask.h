/*
 * Copyright (c) 2007 SIEGE Development Team
 * All rights reserved.
 *
 * This file is part of libSIEGE.
 *
 * This software is copyrighted work licensed under the terms of the
 * 2-clause BSD license. Please consult the file "license.txt" for
 * details.
 *
 * If you did not recieve the file with this program, please email
 * Tim Chas <darkuranium@gmail.com>.
 */
/**
 * \file siege/graphics/mask.h
 * \brief Collision masks
 */

#ifndef __SIEGE_GRAPHICS_MASK_H__
#define __SIEGE_GRAPHICS_MASK_H__

#include "../common.h"
#include "sprite.h"
#include "texture.h"
#include "../util/ivector.h"
#include "../util/vector.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/**
 * \todo Add a bounding box.
 */
typedef struct SGMask
{
    SGuint width;
    SGuint height;

    SGIVec2 offset;

    SGbool precise;
    SGbool** field;
} SGMask;

SGMask* SG_CALL sgMaskCreateSprite(SGSprite* sprite);
SGMask* SG_CALL sgMaskCreateTexture2i(SGTexture* texture, SGint xoffset, SGint yoffset);
SGMask* SG_CALL sgMaskCreateTexture2iv(SGTexture* texture, SGIVec2 offset);
SGMask* SG_CALL sgMaskCreateTexture(SGTexture* texture);
SGMask* SG_CALL sgMaskCreateFile2i(const char* fname, SGint xoffset, SGint yoffset);
SGMask* SG_CALL sgMaskCreateFile2iv(const char* fname, SGIVec2 offset);
SGMask* SG_CALL sgMaskCreateFile(const char* fname);
void SG_CALL sgMaskDestroy(SGMask* mask);

/**
 * \brief Check the collision between two masks
 *
 * \param m1 The first mask to test
 * \param x1 First mask's x position
 * \param y1 First mask's y position
 * \param m2 The second mask to test
 * \param x2 Second mask's x position
 * \param y2 Second mask's y position
 *
 * \return SG_TRUE if the masks collide, SG_FALSE otherwise.
 *
 * \todo Test whether this works or not
 * \todo Use the \c precise field
 * \todo Use bounding box info once BB's are added
 */
SGbool SG_CALL sgMaskCheckCollision2i(SGMask* m1, SGint x1, SGint y1, SGMask* m2, SGint x2, SGint y2);
SGbool SG_CALL sgMaskCheckCollision2iv(SGMask* m1, SGIVec2 p1, SGMask* m2, SGIVec2 p2);

SGIVec2 SG_CALL sgMaskGetSize2iv(SGMask* mask);
SGVec2 SG_CALL sgMaskGetSize2fv(SGMask* mask);
SGuint SG_CALL sgMaskGetWidth(SGMask* mask);
SGuint SG_CALL sgMaskGetHeight(SGMask* mask);

/**
 * \brief A function used for debugging the mask
 *
 * \warning This draws the mask pixel-for-pixel and is <em>slow</em>!
 * \warning This function may be removed in the future!
 *
 * \todo sg[Sprite|Texture|Surface]CreateMask(SGMask* mask)
 */
void SG_CALL sgMaskDrawDBG(SGMask* mask, SGint x, SGint y, SGbool transparent);

/* DEPRECATED */
SGbool SG_CALL SG_HINT_DEPRECATED sgMaskCheckCollision(SGMask* m1, SGint x1, SGint y1, SGMask* m2, SGint x2, SGint y2);
void SG_CALL SG_HINT_DEPRECATED sgMaskGetSize(SGMask* mask, SGuint* width, SGuint* height);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __SIEGE_GRAPHICS_MASK_H__
