#define SG_BUILD_LIBRARY
#include <siege/util/string.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* sgPrintf(char* format, ...)
{
    va_list args;
    va_start(args, format);
    char* str = sgPrintfv(format, args);
    va_end(args);
    return str;
}
char* sgPrintfv(char* format, va_list args)
{
    int buflen = 0;
    int ret = 0;
    char* buf = NULL;

    do
    {
        buflen += 256;
        buf = realloc(buf, buflen);
        ret = vsnprintf(buf, buflen, format, args);
    }
    while(ret >= buflen);

    if(ret < 0)
    {
        free(buf);
        return NULL;
    }

    return realloc(buf, ret + 1);
}

char* sgLineEnd(char* text)
{
    if(text == NULL)
        return NULL;

    char* cr = strchr(text, '\r');
    char* lf = strchr(text, '\n');
    if(cr == NULL)
    {
        if(lf == NULL)
            return text + strlen(text);
        else
            return lf;
    }
    else if(lf == NULL) // cr != NULL
        return cr;
    else
        return (lf > cr) ? lf : cr;
}
SGuint sgLineLength(char* text)
{
    return sgLineEnd(text) - text;
}
char* sgNextLine(char* text)
{
    char* ptr = text;

    if(ptr != NULL)
    {
        char* crlf = strstr(ptr, "\r\n");
        char* cr = strchr(ptr, '\r');
        char* lf = strchr(ptr, '\n');
        if((crlf != NULL) && (crlf == cr) && (crlf == lf - 1)) // found a CRLF, and it was the first newline
            ptr = crlf + 2;
        else if((cr != NULL) && ((cr < lf) || (lf == NULL))) // found a CR, and it was the first newline
            ptr = cr + 1;
        else if(lf != NULL) // found a LF, and it was the first newline
            ptr = lf + 1;
        else // found nothing
            ptr = NULL;
        return ptr;
    }
    return NULL;
}
SGuint sgNumLines(char* text)
{
    SGuint numlines = 0;

    char* ptr = text;
    while(ptr != NULL)
    {
        ptr = sgNextLine(ptr);
        numlines++;
    }
    return numlines;
}
/// \todo TODO
void sgCharToUTF32(char* text, SGuint textlen, SGdchar* str)
{
    size_t i;
    for(i = 0; i < textlen; i++)
        str[i] = text[i];
}
