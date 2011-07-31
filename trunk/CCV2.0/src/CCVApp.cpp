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
    int SetInitPipeline();
};

IMPLEMENT_APP(CCVApp)

/**
   The entrance of the application. Set mainframe and miniframe.
*/
bool CCVApp::OnInit()
{
    param = new CCVGlobalParam;
    LoadConfigXml(param, "config.xml");

    param->logger = new wxLogStderr(logFp);
    wxLog::SetActiveTarget(param->logger);
    
    movidthread = new CCVWorkerEngine();
    
    if (SetInitPipeline()==CCV_SUCCESS) {
        movidthread->procGraph->start();
    }
    else {
        wxLogMessage(wxT("ERROR SetInitPipeline()!=CCV_SUCCESS"));
        return false;
    }
    
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
    if (! XML.loadFile(CONFIGFILE)) {
        logFp = fopen("ccv2.log", "wt");
        return CCV_ERROR_FILE_CANNOT_FOUND;
    }

    in_param->backgroundsub_enabled = XML.getValue("CONFIG:INIT:EnableSubBackground", 1);
    in_param->amplify_enabled = XML.getValue("CONFIG:INIT:EnableAmplify", 1);
    in_param->highpass_enabled = XML.getValue("CONFIG:INIT:EnableHighpass", 1);
    in_param->smooth_enabled = XML.getValue("CONFIG:INIT:EnableSmooth", 1);

    in_param->initThreshold = XML.getValue("CONFIG:INIT:Threshold", 45);
    in_param->initMinBlob = XML.getValue("CONFIG:INIT:MinBlob", 50);
    in_param->initMaxBlob = XML.getValue("CONFIG:INIT:MaxBlob", 1000);
    in_param->initHighpassBlur = XML.getValue("CONFIG:INIT:HighpassBlur", 100);
    in_param->initHighpassSize = XML.getValue("CONFIG:INIT:HighpassSize", 100);
    in_param->initHighpassAmp = XML.getValue("CONFIG:INIT:HighpassAmp", 20);
    in_param->initAmplify = XML.getValue("CONFIG:INIT:Amplify", 20);
    in_param->initSmooth = XML.getValue("CONFIG:INIT:Smooth", 10);

    in_param->output_ipAddress = XML.getValue("CONFIG:NETWORK:IP", "127.0.0.1");
    in_param->output_port = XML.getValue("CONFIG:NETWORK:PORT", 3333);
    
    in_param->videoFileName = XML.getValue("CONFIG:VIDEO:FILENAME", "RearDI.m4v");
    std::string logFileName = XML.getValue("CONFIG:LOG:FILENAME", "ccv2.log");
    logFp = fopen(logFileName.c_str(), "wt");

    return CCV_SUCCESS;
}

int CCVApp::SetInitPipeline()
{
    // Decide whether to use filters
    std::string bgModule = param->backgroundsub_enabled ? "bgSubtract" : "bgSubtract_dummy";
    std::string ampModule = param->amplify_enabled ? "amplify" : "amplify_dummy";
    std::string hpassModule = param->highpass_enabled ? "highpass" : "highpass_dummy";
    std::string smoothModule = param->smooth_enabled ? "smooth" : "smooth_dummy";
    
    // Input Source
    movidthread->procGraph->AddModule("input_source_video", "Video");
    movidthread->procGraph->getModuleById("input_source_video")->property("filename").set(param->videoFileName);
    param->input_source = VIDEO;
    
    // Background Subtract
    movidthread->procGraph->AddModule("bgSubtract", "BackgroundSubtract");
    movidthread->procGraph->AddModule("bgSubtract_dummy", "DoNothing");
    movidthread->procGraph->ConnectModules("input_source_video", bgModule);    
    
    // Amplify
    movidthread->procGraph->AddModule("amplify", "Amplify");
    movidthread->procGraph->getModuleById("amplify")->property("amplify").set(param->initAmplify / 100.0);
    movidthread->procGraph->AddModule("amplify_dummy", "DoNothing");
    movidthread->procGraph->ConnectModules(bgModule, ampModule);    
    
    // Highpass
    movidthread->procGraph->AddModule("highpass", "Highpass");
    movidthread->procGraph->getModuleById("highpass")->property("blur").set(param->initHighpassBlur / 10.0);
    movidthread->procGraph->getModuleById("highpass")->property("size").set(param->initHighpassSize / 10.0);
    movidthread->procGraph->AddModule("highpass_amplify", "Amplify");
    movidthread->procGraph->getModuleById("highpass_amplify")->property("highpass_amplify").set(param->initHighpassAmp / 100.0);
    movidthread->procGraph->AddModule("highpass_dummy", "DoNothing");
    movidthread->procGraph->ConnectModules(ampModule, hpassModule);
    movidthread->procGraph->ConnectModules(hpassModule, "highpass_amplify"); 
    
    // Smooth
    movidthread->procGraph->AddModule("smooth", "Smooth");
    movidthread->procGraph->AddModule("smooth_dummy", "DoNothing");
    movidthread->procGraph->ConnectModules("highpass_amplify", smoothModule); 
    
    // GrayScale
    movidthread->procGraph->AddModule("grayscale", "GrayScale");
    movidthread->procGraph->ConnectModules(smoothModule, "grayscale");    

    // Threshold
    movidthread->procGraph->AddModule("threshold", "Threshold");
    movidthread->procGraph->getModuleById("threshold")->property("threshold").set(param->initThreshold);
    movidthread->procGraph->ConnectModules("grayscale", "threshold");

    // BlobFinder
    movidthread->procGraph->AddModule("blobfinder", "BlobFinder");
    movidthread->procGraph->getModuleById("blobfinder")->property("min_size").set(param->initMinBlob);
    movidthread->procGraph->getModuleById("blobfinder")->property("max_size").set(param->initMaxBlob);
    movidthread->procGraph->ConnectModules("threshold", "blobfinder");    

    // BlobTracker
    movidthread->procGraph->AddModule("blobtracker", "GreedyBlobTracker");
    movidthread->procGraph->ConnectModules("blobfinder", "blobtracker", 1);

    // TUIO
    movidthread->procGraph->AddModule("tuio", "Tuio");
    movidthread->procGraph->getModuleById("tuio")->property("ip").set(param->output_ipAddress);
    movidthread->procGraph->getModuleById("tuio")->property("port").set(param->output_port);
    if (param->tuio_enabled) {
        movidthread->procGraph->ConnectModules("blobtracker", "tuio");
    }
    else {
        movidthread->procGraph->getModuleById("tuio")->setInput(NULL, 0);
    }
    
    // In & Out Monitors
    movidthread->procGraph->AddModule("output_leftviewer", "Stream", true);
    movidthread->procGraph->ConnectModules("input_source_video", "output_leftviewer");
    movidthread->procGraph->AddModule("output_rightviewer", "Stream", true);    
    movidthread->procGraph->ConnectModules("blobfinder", "output_rightviewer");    
    
    // Filter Monitors
    movidthread->procGraph->AddModule("output_background", "Stream", true);
    movidthread->procGraph->ConnectModules(bgModule, "output_background");
    movidthread->procGraph->AddModule("output_amplify", "Stream", true);    
    movidthread->procGraph->ConnectModules(ampModule, "output_amplify");
    movidthread->procGraph->AddModule("output_highpass", "Stream", true);
    movidthread->procGraph->ConnectModules("highpass_amplify", "output_highpass");
    movidthread->procGraph->AddModule("output_smooth", "Stream", true);    
    movidthread->procGraph->ConnectModules(smoothModule, "output_smooth");
    
    return CCV_SUCCESS;    
}
