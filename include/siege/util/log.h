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

#ifndef __SIEGE_UTIL_LOG_H__
#define __SIEGE_UTIL_LOG_H__

#include "../common.h"

#include <stdarg.h>

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#define SG_LOGL_DEBUG    0
#define SG_LOGL_INFO     1
#define SG_LOGL_INIT     2
#define SG_LOGL_WARNING  3
#define SG_LOGL_ERROR    4
#define SG_LOGL_FATAL    5

#define SG_LOGL_NUM (SG_LOGL_FATAL + 1)

#define SG_LOGL_DEFAULT SG_LOGL_INIT

/* TODO: Should these callbacks take the format/args pair directly? */
typedef void SG_CALL (SGLogCallback)(SGenum level, const char* msg, void* data);

void SG_CALL sgLogSetCallback(SGLogCallback* cb, void* data);

char* SG_CALL sgLogGetLevelString(SGenum level, SGbool upper);

void SG_CALL sgLogfv(SGenum level, const char* format, va_list args);
void SG_CALL sgLogf(SGenum level, const char* format, ...);
void SG_CALL sgLog(SGenum level, const char* msg);

#ifdef SG_DEBUG
#define SG_LDEBUGF(...) sgLogf(SG_LOGL_DEBUG, __VA_ARGS__)
#define SG_LDEBUG(...) sgLog(SG_LOGL_DEBUG, msg)
#else
#define SG_LDEBUGF(...)
#define SG_LDEBUG(msg)
#endif /* SG_DEBUG */

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __SIEGE_UTIL_LOG_H__