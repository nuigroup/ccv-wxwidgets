/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVMainFrame.cpp
// Purpose:     Provide the global things.
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#ifndef _CCV_COMMON_H
#define _CCV_COMMON_H

#ifdef WIN32
#include "msw/wx/setup.h"
#include "msw/wx/msw/rcdefs.h"
#endif // WIN32

#include<vector>
#include<string>

enum CCV_ERROR_ID
{
    CCV_SUCCESS,
    CCV_ERROR_LOCKED,
    CCV_ERROR_ITEM_CANNOT_ADDED,
    CCV_ERROR_ITEM_NOT_EXISTS
};

typedef std::vector<std::string> Strings;

#endif // _CCV_COMMON_H
