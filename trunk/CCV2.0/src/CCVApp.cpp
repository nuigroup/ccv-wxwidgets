/////////////////////////////////////////////////////////////////////////////
// Name:        src/main.cpp
// Purpose:     Provide the entrance of the application
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

/*! \mainpage Introduction
 *
 * Community Core Vision, CCV for short (aka tbeta), is a open
 * source/cross-platform solution for computer vision and machine sensing.
 * It takes an video input stream and outputs tracking data (e.g. coordinates
 * and blob size) and events (e.g. finger down, moved and released) that are
 * used in building multi-touch applications. CCV can interface with various
 * web cameras and video devices as well as connect to various TUIO/OSC/XML
 * enabled applications and supports many multi-touch lighting techniques
 * including: FTIR, DI, DSI, and LLP with expansion planned for the future
 * vision applications (custom modules/filters).
 *
 * This version of CCV is based on OpenCV, Movid and wxWidgets.
 */

#include <wx/wx.h>
#include <wx/thread.h>
#include <wx/app.h>
#include <cstdio>
#include "CCVCommon.h"
#include "CCVWorkerEngine.h"
#include "CCVMainFrame.h"
#include "CCVMiniFrame.h"
#include "tinyxml.h"
#include "ofxXmlSettings.h"

//
// CCVApp is the class that provides the main application.
//
class CCVApp : public wxApp
{
    virtual bool OnInit();
    virtual int OnExit();
    int FilterEvent(wxEvent& event);

private:
    bool use_Mainframe;
    CCVMainFrame *mainframe;
    CCVMiniFrame *miniframe;
    CCVWorkerEngine *movidthread;
    CCVGlobalParam *param;
    FILE* logFp;

    int LoadConfigXml(CCVGlobalParam *, std::string filename);
};

IMPLEMENT_APP(CCVApp)

/**
   The entrance of the application. Set mainframe and miniframe.
*/
bool CCVApp::OnInit()
{
    param = new CCVGlobalParam;
    LoadConfigXml(param, "config.xml");
    
    movidthread = new CCVWorkerEngine();
    
    // Set the initial pipeline
    movidthread->procGraph->AddModule("input_source", "Camera");

    movidthread->procGraph->AddModule("output_leftviewer", "Stream", true);
    movidthread->procGraph->ConnectModules("input_source", "output_leftviewer");

    movidthread->procGraph->AddModule("grayscale", "GrayScale");
    movidthread->procGraph->ConnectModules("input_source", "grayscale");

    movidthread->procGraph->AddModule("threshold", "Threshold")->property("threshold").set(param->initThreshold);
    movidthread->procGraph->ConnectModules("grayscale", "threshold");

    movidthread->procGraph->AddModule("blobfinder", "BlobFinder")->property("max_size").set(param->initMinBlob);
    movidthread->procGraph->getModuleById("blobfinder")->property("max_size").set(param->initMaxBlob);
    movidthread->procGraph->ConnectModules("threshold", "blobfinder");

    movidthread->procGraph->AddModule("output_rightviewer", "Stream", true);    
    movidthread->procGraph->ConnectModules("blobfinder", "output_rightviewer");
    movidthread->procGraph->start();
    
    if (movidthread->Create() != wxTHREAD_NO_ERROR ) {
        wxLogMessage(wxT("ERROR movidthread->Create() != wxTHREAD_NO_ERROR"));
        return false;
    }
    if (movidthread->Run() != wxTHREAD_NO_ERROR) {
        wxLogMessage(wxT("ERROR movidthread->Run() != wxTHREAD_NO_ERROR"));
        return false;
    }

    use_Mainframe = true;

    mainframe = new CCVMainFrame(movidthread, param);
    if (mainframe==NULL)
        return false;
    mainframe->Show(use_Mainframe);

    miniframe = new CCVMiniFrame(mainframe);
    if (miniframe==NULL)
        return false;
    miniframe->Show(!use_Mainframe);

    return true;
}

/**
   Switch between mainframe and miniframe when the spacebar was pressed.
*/
int CCVApp::FilterEvent(wxEvent& event)
{
    if (event.GetEventType()==wxEVT_KEY_DOWN && ((wxKeyEvent&)event).GetKeyCode()==WXK_SPACE) {
        use_Mainframe = !use_Mainframe;
        mainframe->Show(use_Mainframe);
        miniframe->Show(!use_Mainframe);
        return 0;
    }

    return -1;
}

int CCVApp::OnExit()
{
    fclose(logFp);
    if (movidthread->Pause() != wxTHREAD_NO_ERROR) {
        wxLogMessage(wxT("ERROR movidthread->Pause() != wxTHREAD_NO_ERROR"));
    }
    return 0;
}

int CCVApp::LoadConfigXml(CCVGlobalParam *in_param, std::string filename)
{
    // Not means CCV2 depends oF.
    // Just use ofxXml, as ofxXml is easier to use than tinyxml.
    ofxXmlSettings XML;
    if (! XML.loadFile("config.xml"))
        return CCV_ERROR_FILE_CANNOT_FOUND;

    in_param->initThreshold = XML.getValue("CONFIG:INIT:Threshold", 180);
    in_param->initMinBlob = XML.getValue("CONFIG:INIT:MinBlob", 50);
    in_param->initMaxBlob = XML.getValue("CONFIG:INIT:MaxBlob", 1000);
    
    in_param->videoFileName = XML.getValue("CONFIG:VIDEO:FILENAME", "RearDI.m4v");
    std::string logFileName = XML.getValue("CONFIG:LOG:FILENAME", "ccv2.log");
    logFp = fopen(logFileName.c_str(), "wt");
    in_param->logger = new wxLogStderr(logFp);
    wxLog::SetActiveTarget(in_param->logger);
    return CCV_SUCCESS;
}
