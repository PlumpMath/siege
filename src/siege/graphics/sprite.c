#define SG_BUILD_LIBRARY
#include <siege/graphics/sprite.h>

#include <stdlib.h>
#include <math.h>

void SG_EXPORT _sgSpriteEvTick(SGEntity* client)
{
    SGSprite* sprite = client->data;
    sprite->image += sprite->speed;

    while((SGuint)sprite->image >= sprite->numimages)
        sprite->image -= sprite->numimages;
}

SGSprite* SG_EXPORT sgSpriteCreateTexture2f(SGTexture* texture, float xoffset, float yoffset)
{
    SGSprite* sprite = malloc(sizeof(SGSprite));
    if(sprite == NULL)
        return NULL;

    sprite->client = sgEntityCreate(0.0, SG_EVT_CORE);
    sprite->client->data = sprite;
    sprite->client->evTick = _sgSpriteEvTick;

    sprite->extimages = SG_TRUE;
    sprite->numimages = 1;
    sprite->subimages = malloc(sizeof(SGTexture*));
    sprite->subimages[0] = texture;

    if(xoffset != xoffset)
        xoffset = sgTextureGetWidth(texture) / 2.0;
    if(yoffset != yoffset)
        yoffset = sgTextureGetHeight(texture) / 2.0;
    sprite->xoffset = xoffset;
    sprite->yoffset = yoffset;

    sprite->image = 0.0;
    sprite->speed = 1.0;

    return sprite;
}
SGSprite* SG_EXPORT sgSpriteCreateTexture(SGTexture* texture)
{
    return sgSpriteCreateTexture2f(texture, SG_NAN, SG_NAN);
}
SGSprite* SG_EXPORT sgSpriteCreateFile2f(char* fname, float xoffset, float yoffset)
{
    SGTexture* texture = sgTextureCreateFile(fname);
    if(texture == NULL)
        return NULL;
    SGSprite* sprite = sgSpriteCreateTexture2f(texture, xoffset, yoffset);
    if(sprite == NULL)
    {
        sgTextureDestroy(texture);
        return NULL;
    }
    sprite->extimages = SG_FALSE;
    return sprite;
}
SGSprite* SG_EXPORT sgSpriteCreateFile(char* fname)
{
    return sgSpriteCreateFile2f(fname, SG_NAN, SG_NAN);
}
void SG_EXPORT sgSpriteDestroy(SGSprite* sprite)
{
    if(sprite == NULL)
        return;

    SGuint i;
    if(sprite->extimages)
    {
        for(i = 0; i < sprite->numimages; i++)
            sgTextureDestroy(sprite->subimages[i]);
    }
    free(sprite->subimages);
    free(sprite);
}

void SG_EXPORT sgSpriteDrawRads3f2f1f(SGSprite* sprite, float x, float y, float z, float xscale, float yscale, float angle)
{
    if(sprite == NULL)
        return;

    sgTextureDrawRads3f2f2f1f(sprite->subimages[(SGuint)sprite->image], x, y, z, xscale, yscale, sprite->xoffset, sprite->yoffset, angle);
}
void SG_EXPORT sgSpriteDrawRads2f2f1f(SGSprite* sprite, float x, float y, float xscale, float yscale, float angle)
{
    sgSpriteDrawRads3f2f1f(sprite, x, y, 0.0, xscale, yscale, angle);
}
void SG_EXPORT sgSpriteDrawRads3f1f(SGSprite* sprite, float x, float y, float z, float angle)
{
    sgSpriteDrawRads3f2f1f(sprite, x, y, z, 1.0, 1.0, angle);
}
void SG_EXPORT sgSpriteDrawRads2f1f(SGSprite* sprite, float x, float y, float angle)
{
    sgSpriteDrawRads3f2f1f(sprite, x, y, 0.0, 1.0, 1.0, angle);
}

void SG_EXPORT sgSpriteDrawDegs3f2f1f(SGSprite* sprite, float x, float y, float z, float xscale, float yscale, float angle)
{
    sgSpriteDrawRads3f2f1f(sprite, x, y, z, xscale, yscale, angle * M_PI / 180.0);
}
void SG_EXPORT sgSpriteDrawDegs2f2f1f(SGSprite* sprite, float x, float y, float xscale, float yscale, float angle)
{
    sgSpriteDrawRads3f2f1f(sprite, x, y, 0.0, xscale, yscale, angle * M_PI / 180.0);
}
void SG_EXPORT sgSpriteDrawDegs3f1f(SGSprite* sprite, float x, float y, float z, float angle)
{
    sgSpriteDrawRads3f2f1f(sprite, x, y, z, 1.0, 1.0, angle * M_PI / 180.0);
}
void SG_EXPORT sgSpriteDrawDegs2f1f(SGSprite* sprite, float x, float y, float angle)
{
    sgSpriteDrawRads3f2f1f(sprite, x, y, 0.0, 1.0, 1.0, angle * M_PI / 180.0);
}

void SG_EXPORT sgSpriteDraw3f2f(SGSprite* sprite, float x, float y, float z, float xscale, float yscale)
{
    sgSpriteDrawRads3f2f1f(sprite, x, y, z, xscale, yscale, 0.0);
}
void SG_EXPORT sgSpriteDraw2f2f(SGSprite* sprite, float x, float y, float xscale, float yscale)
{
    sgSpriteDrawRads3f2f1f(sprite, x, y, 0.0, xscale, yscale, 0.0);
}
void SG_EXPORT sgSpriteDraw3f(SGSprite* sprite, float x, float y, float z)
{
    sgSpriteDrawRads3f2f1f(sprite, x, y, z, 1.0, 1.0, 0.0);
}
void SG_EXPORT sgSpriteDraw2f(SGSprite* sprite, float x, float y)
{
    sgSpriteDrawRads3f2f1f(sprite, x, y, 0.0, 1.0, 1.0, 0.0);
}

void SG_EXPORT sgSpriteGetSize(SGSprite* sprite, SGuint* width, SGuint* height)
{
    if(sprite == NULL)
        return;

    sgTextureGetSize(sprite->subimages[0], width, height);
}
SGuint SG_EXPORT sgSpriteGetWidth(SGSprite* sprite)
{
    if(sprite == NULL)
        return 0;

    return sgTextureGetWidth(sprite->subimages[0]);
}
SGuint SG_EXPORT sgSpriteGetHeight(SGSprite* sprite)
{
    if(sprite == NULL)
        return 0;

    return sgTextureGetHeight(sprite->subimages[0]);
}