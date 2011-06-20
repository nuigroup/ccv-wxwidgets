/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVUtil.h
// Purpose:     Provide misc utilities.
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#ifndef _CCV_UTIL_H
#define _CCV_UTIL_H

class CCVUtil
{
public:
    static int WriteBMP(unsigned char *image, int xsize, int ysize, const char *filename);
};

#endif // _CCV_UTIL_H
