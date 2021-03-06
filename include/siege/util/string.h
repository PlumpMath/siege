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

#ifndef __SIEGE_UTIL_STRING_H__
#define __SIEGE_UTIL_STRING_H__

#include "../common.h"

#include <stdarg.h>

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#define SG_OCTDIGITS "01234567"
#define SG_DECDIGITS SG_OCTDIGITS "89"
#define SG_HEXDIGITS "ABCDEFabcdef" SG_DECDIGITS
#define SG_ALPHA     "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
#define SG_ALNUM     SG_ALPHA SG_DECDIGITS

char* _sgStringAppend(char** str, size_t* len, size_t* mem, const char* what);

size_t SG_CALL _sgStrbufAppend(size_t sz, size_t pos, void* out, size_t outlen, const void* in, size_t inlen);

// wprintf, locked with a mutex for thread-safety
size_t SG_CALL sgPrintfW(const wchar_t* format, ...);
size_t SG_CALL sgPrintfvW(const wchar_t* format, va_list args);

// printf, locked with a mutex for thread-safety
size_t SG_CALL SG_HINT_PRINTF(1, 2) sgPrintf(const char* format, ...);
size_t SG_CALL SG_HINT_PRINTF(1, 0) sgPrintfv(const char* format, va_list args);

size_t SG_CALL sgSPrintfW(wchar_t* buf, size_t buflen, const wchar_t* format, ...);
size_t SG_CALL sgSPrintfvW(wchar_t* buf, size_t buflen, const wchar_t* format, va_list args);

wchar_t* SG_CALL sgAPrintfW(const wchar_t* format, ...);
wchar_t* SG_CALL sgAPrintfvW(const wchar_t* format, va_list args);

size_t SG_CALL SG_HINT_PRINTF(3, 4) sgSPrintf(char* buf, size_t buflen, const char* format, ...);
size_t SG_CALL SG_HINT_PRINTF(3, 0) sgSPrintfv(char* buf, size_t buflen, const char* format, va_list args);

char* SG_CALL SG_HINT_PRINTF(1, 2) sgAPrintf(const char* format, ...);
char* SG_CALL SG_HINT_PRINTF(1, 0) sgAPrintfv(const char* format, va_list args);

void SG_CALL sgAPrintFree(void* str);

SGbool SG_CALL sgStartsWith(const char* text, const char* what);
char* SG_CALL sgSpaceEnd(const char* text);
char* SG_CALL sgLineEnd(const char* text);
SGuint SG_CALL sgLineLength(const char* text);
char* SG_CALL sgNextLine(const char* text);
SGuint SG_CALL sgNumLines(const char* text);

SGdchar* SG_CALL sgLineEndU32(const SGdchar* text);
SGuint SG_CALL sgLineLengthU32(const SGdchar* text);
SGdchar* SG_CALL sgNextLineU32(const SGdchar* text);
SGuint SG_CALL sgNumLinesU32(const SGdchar* text);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // __SIEGE_UTIL_STRING_H__
