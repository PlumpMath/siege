#define SG_BUILD_LIBRARY
#include <siege/util/ivector.h>
#include <siege/util/vector.h>

#include <stdlib.h>
#include <math.h>

static SGint wrapInt(SGint a, SGint min, SGint max)
{
    a -= min;
    max -= min;

    return min + (a < 0 ? fmod(max - fmod(-a, max), max) : fmod(a, max));
}
static void swapInt(SGint* x, SGint* y)
{
    SGint tmp = *x;
    *x = *y;
    *y = tmp;
}
static void sortInt(SGint* x, SGint* y)
{
    if(*y < *x) swapInt(x, y);
}

SGIVec2 SG_CALL sgIVec2i(SGint x, SGint y)
{
    SGIVec2 vec;
    vec.x = x; vec.y = y;
    return vec;
}
SGIVec2 SG_CALL sgIVec2ip(const SGint* xy)
{
    return sgIVec2i(xy[0], xy[1]);
}
SGIVec2 SG_CALL sgIVec2fv(SGVec2 vec)
{
    return sgIVec2i((SGint)vec.x, (SGint)vec.y);
}

float SG_CALL sgIVec2Length(SGIVec2 vec)
{
    return sqrt(sgIVec2Length2(vec));
}
SGint SG_CALL sgIVec2Length2(SGIVec2 vec)
{
    return sgIVec2Dot(vec, vec);
}

SGIVec2 SG_CALL sgIVec2Neg(SGIVec2 a)
{
    return sgIVec2i(-a.x, -a.y);
}
SGIVec2 SG_CALL sgIVec2Add(SGIVec2 a, SGIVec2 b)
{
    return sgIVec2i(a.x + b.x, a.y + b.y);
}
SGIVec2 SG_CALL sgIVec2Sub(SGIVec2 a, SGIVec2 b)
{
    return sgIVec2i(a.x - b.x, a.y - b.y);
}
SGIVec2 SG_CALL sgIVec2Mul(SGIVec2 a, SGIVec2 b)
{
    return sgIVec2i(a.x * b.x, a.y * b.y);
}
SGIVec2 SG_CALL sgIVec2Div(SGIVec2 a, SGIVec2 b)
{
    return sgIVec2i(a.x / b.x, a.y / b.y);
}

SGIVec2 SG_CALL sgIVec2Addi(SGIVec2 a, SGint i)
{
    return sgIVec2Add(a, sgIVec2i(i, i));
}
SGIVec2 SG_CALL sgIVec2Subi(SGIVec2 a, SGint i)
{
    return sgIVec2Sub(a, sgIVec2i(i, i));
}
SGIVec2 SG_CALL sgIVec2Muli(SGIVec2 a, SGint i)
{
    return sgIVec2Mul(a, sgIVec2i(i, i));
}
SGIVec2 SG_CALL sgIVec2Divi(SGIVec2 a, SGint i)
{
    return sgIVec2Div(a, sgIVec2i(i, i));
}

float SG_CALL sgIVec2Distance(SGIVec2 a, SGIVec2 b)
{
    return sgIVec2Length(sgIVec2Sub(a, b));
}
SGint SG_CALL sgIVec2Distance2(SGIVec2 a, SGIVec2 b)
{
    return sgIVec2Length2(sgIVec2Sub(a, b));
}

SGIVec2 SG_CALL sgIVec2Min(SGIVec2 a, SGIVec2 b)
{
    return sgIVec2i(SG_MIN(a.x, b.x), SG_MIN(a.y, b.y));
}
SGIVec2 SG_CALL sgIVec2Max(SGIVec2 a, SGIVec2 b)
{
    return sgIVec2i(SG_MAX(a.x, b.x), SG_MAX(a.y, b.y));
}
SGIVec2 SG_CALL sgIVec2Abs(SGIVec2 a)
{
    return sgIVec2i(SG_ABS(a.x), SG_ABS(a.y));
}
SGIVec2 SG_CALL sgIVec2Wrap(SGIVec2 a, SGIVec2 min, SGIVec2 max)
{
    return sgIVec2i(wrapInt(a.x, min.x, max.x), wrapInt(a.y, min.y, max.y));
}
SGIVec2 SG_CALL sgIVec2Clamp(SGIVec2 a, SGIVec2 min, SGIVec2 max)
{
    return sgIVec2Min(sgIVec2Max(a, min), max);
}
SGIVec2 SG_CALL sgIVec2XWrap(SGIVec2 a, SGIVec2 min, SGIVec2 max)
{
    sortInt(&min.x, &max.x);
    sortInt(&min.y, &max.y);
    return sgIVec2Wrap(a, min, max);
}
SGIVec2 SG_CALL sgIVec2XClamp(SGIVec2 a, SGIVec2 min, SGIVec2 max)
{
    sortInt(&min.x, &max.x);
    sortInt(&min.y, &max.y);
    return sgIVec2Clamp(a, min, max);
}

SGint SG_CALL sgIVec2Dot(SGIVec2 a, SGIVec2 b)
{
    return a.x * b.x + a.y * b.y;
}
SGint SG_CALL sgIVec2PDot(SGIVec2 a, SGIVec2 b)
{
    return a.x * b.y - a.y * b.x;
}
SGIVec2 SG_CALL sgIVec2Cross(SGIVec2 a)
{
    return sgIVec2i(a.y, -a.x);
}

SGIVec2 SG_CALL sgIVec2QMul2(SGIVec2 a, SGIVec2 b)
{
    // (ax + ay I) * (bx + by I)
    SGIVec2 ret;
    ret.x = a.x * b.x - a.y * b.y;
    ret.y = a.x * b.y + a.y * b.x;
    return ret;
}


SGIVec3 SG_CALL sgIVec3i(SGint x, SGint y, SGint z)
{
    SGIVec3 vec;
    vec.x = x; vec.y = y; vec.z = z;
    return vec;
}
SGIVec3 SG_CALL sgIVec3ip(const SGint* xyz)
{
    return sgIVec3i(xyz[0], xyz[1], xyz[2]);
}
SGIVec3 SG_CALL sgIVec3fv(SGVec3 vec)
{
    return sgIVec3i((SGint)vec.x, (SGint)vec.y, (SGint)vec.z);
}

float SG_CALL sgIVec3Length(SGIVec3 vec)
{
    return sqrt(sgIVec3Length2(vec));
}
SGint SG_CALL sgIVec3Length2(SGIVec3 vec)
{
    return sgIVec3Dot(vec, vec);
}

SGIVec3 SG_CALL sgIVec3Neg(SGIVec3 a)
{
    return sgIVec3i(-a.x, -a.y, -a.z);
}
SGIVec3 SG_CALL sgIVec3Add(SGIVec3 a, SGIVec3 b)
{
    return sgIVec3i(a.x + b.x, a.y + b.y, a.z + b.z);
}
SGIVec3 SG_CALL sgIVec3Sub(SGIVec3 a, SGIVec3 b)
{
    return sgIVec3i(a.x - b.x, a.y - b.y, a.z - b.z);
}
SGIVec3 SG_CALL sgIVec3Mul(SGIVec3 a, SGIVec3 b)
{
    return sgIVec3i(a.x * b.x, a.y * b.y, a.z * b.z);
}
SGIVec3 SG_CALL sgIVec3Div(SGIVec3 a, SGIVec3 b)
{
    return sgIVec3i(a.x / b.x, a.y / b.y, a.z / b.z);
}

SGIVec3 SG_CALL sgIVec3Addi(SGIVec3 a, SGint i)
{
    return sgIVec3Add(a, sgIVec3i(i, i, i));
}
SGIVec3 SG_CALL sgIVec3Subi(SGIVec3 a, SGint i)
{
    return sgIVec3Sub(a, sgIVec3i(i, i, i));
}
SGIVec3 SG_CALL sgIVec3Muli(SGIVec3 a, SGint i)
{
    return sgIVec3Mul(a, sgIVec3i(i, i, i));
}
SGIVec3 SG_CALL sgIVec3Divi(SGIVec3 a, SGint i)
{
    return sgIVec3Div(a, sgIVec3i(i, i, i));
}

float SG_CALL sgIVec3Distance(SGIVec3 a, SGIVec3 b)
{
    return sgIVec3Length(sgIVec3Sub(a, b));
}
SGint SG_CALL sgIVec3Distance2(SGIVec3 a, SGIVec3 b)
{
    return sgIVec3Length2(sgIVec3Sub(a, b));
}

SGIVec3 SG_CALL sgIVec3Min(SGIVec3 a, SGIVec3 b)
{
    return sgIVec3i(SG_MIN(a.x, b.x), SG_MIN(a.y, b.y), SG_MIN(a.z, b.z));
}
SGIVec3 SG_CALL sgIVec3Max(SGIVec3 a, SGIVec3 b)
{
    return sgIVec3i(SG_MAX(a.x, b.x), SG_MAX(a.y, b.y), SG_MAX(a.z, b.z));
}
SGIVec3 SG_CALL sgIVec3Abs(SGIVec3 a)
{
    return sgIVec3i(SG_ABS(a.x), SG_ABS(a.y), SG_ABS(a.z));
}
SGIVec3 SG_CALL sgIVec3Wrap(SGIVec3 a, SGIVec3 min, SGIVec3 max)
{
    return sgIVec3i(wrapInt(a.x, min.x, max.x), wrapInt(a.y, min.y, max.y), wrapInt(a.z, min.z, max.z));
}
SGIVec3 SG_CALL sgIVec3Clamp(SGIVec3 a, SGIVec3 min, SGIVec3 max)
{
    return sgIVec3Min(sgIVec3Max(a, min), max);
}
SGIVec3 SG_CALL sgIVec3XWrap(SGIVec3 a, SGIVec3 min, SGIVec3 max)
{
    sortInt(&min.x, &max.x);
    sortInt(&min.y, &max.y);
    sortInt(&min.z, &max.z);
    return sgIVec3Wrap(a, min, max);
}
SGIVec3 SG_CALL sgIVec3XClamp(SGIVec3 a, SGIVec3 min, SGIVec3 max)
{
    sortInt(&min.x, &max.x);
    sortInt(&min.y, &max.y);
    sortInt(&min.z, &max.z);
    return sgIVec3Clamp(a, min, max);
}

SGint SG_CALL sgIVec3Dot(SGIVec3 a, SGIVec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
SGIVec3 SG_CALL sgIVec3Cross(SGIVec3 a, SGIVec3 b)
{
    return sgIVec3i(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}
SGint SG_CALL sgIVec3Triple(SGIVec3 a, SGIVec3 b, SGIVec3 c)
{
    return sgIVec3Dot(a, sgIVec3Cross(b, c));
}


SGIVec4 SG_CALL sgIVec4i(SGint x, SGint y, SGint z, SGint w)
{
    SGIVec4 vec;
    vec.x = x; vec.y = y; vec.z = z; vec.w = w;
    return vec;
}
SGIVec4 SG_CALL sgIVec4ip(const SGint* xyzw)
{
    return sgIVec4i(xyzw[0], xyzw[1], xyzw[2], xyzw[3]);
}
SGIVec4 SG_CALL sgIVec4fv(SGVec4 vec)
{
    return sgIVec4i((SGint)vec.x, (SGint)vec.y, (SGint)vec.z, (SGint)vec.w);
}

float SG_CALL sgIVec4Length(SGIVec4 vec)
{
    return sqrt(sgIVec4Length2(vec));
}
SGint SG_CALL sgIVec4Length2(SGIVec4 vec)
{
    return sgIVec4Dot(vec, vec);
}

SGIVec4 SG_CALL sgIVec4Neg(SGIVec4 a)
{
    return sgIVec4i(-a.x, -a.y, -a.z, -a.w);
}
SGIVec4 SG_CALL sgIVec4Add(SGIVec4 a, SGIVec4 b)
{
    return sgIVec4i(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}
SGIVec4 SG_CALL sgIVec4Sub(SGIVec4 a, SGIVec4 b)
{
    return sgIVec4i(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}
SGIVec4 SG_CALL sgIVec4Mul(SGIVec4 a, SGIVec4 b)
{
    return sgIVec4i(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}
SGIVec4 SG_CALL sgIVec4Div(SGIVec4 a, SGIVec4 b)
{
    return sgIVec4i(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
}

SGIVec4 SG_CALL sgIVec4Addi(SGIVec4 a, SGint i)
{
    return sgIVec4Add(a, sgIVec4i(i, i, i, i));
}
SGIVec4 SG_CALL sgIVec4Subi(SGIVec4 a, SGint i)
{
    return sgIVec4Sub(a, sgIVec4i(i, i, i, i));
}
SGIVec4 SG_CALL sgIVec4Muli(SGIVec4 a, SGint i)
{
    return sgIVec4Mul(a, sgIVec4i(i, i, i, i));
}
SGIVec4 SG_CALL sgIVec4Divi(SGIVec4 a, SGint i)
{
    return sgIVec4Div(a, sgIVec4i(i, i, i, i));
}

SGIVec4 SG_CALL sgIVec4QMul4(SGIVec4 a, SGIVec4 b)
{
    // (ax + ay I + az J + aw K) * (bx + by I + bz J + bw K)
    SGIVec4 ret;
    ret.x = a.x * b.x - a.y * b.y - a.z * b.z - a.w * b.w;
    ret.y = a.x * b.y + a.y * b.x + a.z * b.w - a.w * b.z;
    ret.z = a.x * b.z - a.y * b.w + a.z * b.x + a.w * b.y;
    ret.w = a.x * b.w + a.y * b.z - a.z * b.y + a.w * b.x;
    return ret;
}

float SG_CALL sgIVec4Distance(SGIVec4 a, SGIVec4 b)
{
    return sgIVec4Length(sgIVec4Sub(a, b));
}
SGint SG_CALL sgIVec4Distance2(SGIVec4 a, SGIVec4 b)
{
    return sgIVec4Length2(sgIVec4Sub(a, b));
}

SGIVec4 SG_CALL sgIVec4Min(SGIVec4 a, SGIVec4 b)
{
    return sgIVec4i(SG_MIN(a.x, b.x), SG_MIN(a.y, b.y), SG_MIN(a.z, b.z), SG_MIN(a.w, b.w));
}
SGIVec4 SG_CALL sgIVec4Max(SGIVec4 a, SGIVec4 b)
{
    return sgIVec4i(SG_MAX(a.x, b.x), SG_MAX(a.y, b.y), SG_MAX(a.z, b.z), SG_MAX(a.w, b.w));
}
SGIVec4 SG_CALL sgIVec4Abs(SGIVec4 a)
{
    return sgIVec4i(SG_ABS(a.x), SG_ABS(a.y), SG_ABS(a.z), SG_ABS(a.w));
}
SGIVec4 SG_CALL sgIVec4Wrap(SGIVec4 a, SGIVec4 min, SGIVec4 max)
{
    return sgIVec4i(wrapInt(a.x, min.x, max.x), wrapInt(a.y, min.y, max.y), wrapInt(a.z, min.z, max.z), wrapInt(a.w, min.w, max.w));
}
SGIVec4 SG_CALL sgIVec4Clamp(SGIVec4 a, SGIVec4 min, SGIVec4 max)
{
    return sgIVec4Min(sgIVec4Max(a, min), max);
}
SGIVec4 SG_CALL sgIVec4XWrap(SGIVec4 a, SGIVec4 min, SGIVec4 max)
{
    sortInt(&min.x, &max.x);
    sortInt(&min.y, &max.y);
    sortInt(&min.z, &max.z);
    sortInt(&min.w, &max.w);
    return sgIVec4Wrap(a, min, max);
}
SGIVec4 SG_CALL sgIVec4XClamp(SGIVec4 a, SGIVec4 min, SGIVec4 max)
{
    sortInt(&min.x, &max.x);
    sortInt(&min.y, &max.y);
    sortInt(&min.z, &max.z);
    sortInt(&min.w, &max.w);
    return sgIVec4Clamp(a, min, max);
}

SGint SG_CALL sgIVec4Dot(SGIVec4 a, SGIVec4 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}
//SGIVec4 SG_CALL sgIVec4Cross(SGIVec4 a, SGIVec4 b, SGIVec4 c);
