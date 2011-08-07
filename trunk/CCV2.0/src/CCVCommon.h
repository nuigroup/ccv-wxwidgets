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
#include "msw/wx/msw/rcdefs.h"
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"comctl32.lib")
// #include "../msvc/vld.h"   // for detecting memory leak
#endif // WIN32

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <wx/log.h>

#define CONFIGFILE "config.xml"

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
    int initHighpassSize;
    int initHighpassAmp;
    int initAmplify;
    int initSmooth;
    
    SourceType input_source;

    int backgroundsub_enabled;
    int amplify_enabled;
    int highpass_enabled;
    int smooth_enabled;

    int tuio_enabled;

    std::string output_ipAddress;
    int output_port;

    void *videoModule;
    void *cameraModule;
    
    CCVGlobalParam()
    {
        logger = NULL;
        initThreshold = 0;
        initMinBlob = 0;
        initMaxBlob = 0;
        initHighpassBlur = 0;
        initHighpassSize = 0;
        initAmplify = 0;
        initSmooth = 0;
        backgroundsub_enabled = 0;
        amplify_enabled = 0;
        highpass_enabled = 0;
        smooth_enabled = 0;
        tuio_enabled = 0;
        input_source = VIDEO;
        output_port = 9999;
    }
};

#endif // _CCV_COMMON_H
