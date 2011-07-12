/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVMainFrame.cpp
// Purpose:     Provide the global things.
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#ifndef _CCV_COMMON_H
#define _CCV_COMMON_H

#ifdef WIN32
#include "wx/setup.h"
#include "msw/wx/msw/rcdefs.h"
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"comctl32.lib")
#endif // WIN32

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <wx/log.h>

enum CCV_ERROR_ID
{
    CCV_SUCCESS,
    CCV_ERROR_LOCKED,
    CCV_ERROR_ITEM_CANNOT_ADDED,
    CCV_ERROR_ITEM_NOT_EXISTS,
    CCV_ERROR_FILE_CANNOT_FOUND,
    CCV_ERROR_BUSY
};

typedef std::vector<std::string> Strings;

struct CCVGlobalParam
{
    std::string videoFileName;
    wxLog *logger;

    int initThreshold;
    int initMinBlob;
    int initMaxBlob;
    
    bool backgroundsub_enabled;
    bool amplify_enabled;
    bool highpass_enabled;
    bool smooth_enabled;
    
    CCVGlobalParam()
    {
        logger = NULL;
        initThreshold = 0;
        initMinBlob = 0;
        initMaxBlob = 0;
        backgroundsub_enabled = false;
        amplify_enabled = false;
        highpass_enabled = false;
        smooth_enabled = false;
    }
};

#endif // _CCV_COMMON_H
