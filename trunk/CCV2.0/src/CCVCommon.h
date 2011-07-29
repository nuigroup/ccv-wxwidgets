/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVMainFrame.cpp
// Purpose:     Provide the global things.
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#ifndef _CCV_COMMON_H
#define _CCV_COMMON_H

#ifdef WIN32
#include "wx/msw/setup.h"
#include "wx/msw/msvcrt.h"      // redefines the new() operator to detect memory leak
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
    CCV_ERROR_BUSY,
    CCV_ERROR_UNSUPPORTED
};

enum SourceType
{
    CAMERA,
    VIDEO
};

typedef std::vector<std::string> Strings;

struct CCVGlobalParam
{
    std::string videoFileName;
    wxLog *logger;

    int initThreshold;
    int initMinBlob;
    int initMaxBlob;
    int initHighpassBlur;
    int initHighpasSize;
    int initAmplify;
    int initSmooth;
    
    SourceType input_source;

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
        initHighpassBlur = 0;
        initHighpasSize = 0;
        initAmplify = 0;
        initSmooth = 0;
        backgroundsub_enabled = false;
        amplify_enabled = false;
        highpass_enabled = false;
        smooth_enabled = false;
        input_source = VIDEO;
    }
};

#endif // _CCV_COMMON_H
