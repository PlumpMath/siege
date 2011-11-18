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

#ifndef __SIEGE_UTIL_RAND_H__
#define __SIEGE_UTIL_RAND_H__

#include "../common.h"

#include <time.h>

#define SG_RAND_USER    0
#define SG_RAND_MT19937 1

#define SG_RAND_MERSENNE32 SG_RAND_MT19937

struct SGRand;

typedef void SG_EXPORT (SGRandCreateFunction)(struct SGRand* rand);
typedef void SG_EXPORT (SGRandDestroyFunction)(struct SGRand* rand);
typedef void SG_EXPORT (SGRandSeedFunction)(struct SGRand* rand, SGulong seed, SGulong index);
typedef SGulong SG_EXPORT (SGRandGenFunction)(struct SGRand* rand);

typedef struct SGRandCallbacks
{
    SGRandCreateFunction* create;
    SGRandDestroyFunction* destroy;
    SGRandSeedFunction* seed;
    SGRandGenFunction* gen;
} SGRandCallbacks;

typedef struct SGRand
{
    SGenum type;
    time_t stime;
    SGubyte* data;
    SGRandCallbacks cbs;
} SGRand;

SGRand* SG_EXPORT sgRandCreate(SGenum type);
SGRand* SG_EXPORT sgRandCreateCB(SGRandCallbacks* cbs);
void SG_EXPORT sgRandDestroy(SGRand* rand);

void SG_EXPORT sgRandSeed(SGRand* rand, SGulong seed, SGulong index);

SGulong SG_EXPORT sgRandGen(SGRand* rand);

#endif // __SIEGE_UTIL_RAND_H__
