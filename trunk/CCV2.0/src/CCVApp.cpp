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
#include "CCVCommon.h"
#include "CCVWorkerEngine.h"
#include "CCVMainFrame.h"
#include "CCVMiniFrame.h"

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
};

IMPLEMENT_APP(CCVApp)

/**
   The entrance of the application. Set mainframe and miniframe.
*/
bool CCVApp::OnInit()
{
    movidthread = new CCVWorkerEngine;
    
    // Set the initial pipeline
    movidthread->procGraph->AddModule("input_source", "Camera");
    movidthread->procGraph->AddModule("output_leftviewer", "Stream", true);
    movidthread->procGraph->AddModule("invert", "Invert");
    movidthread->procGraph->AddModule("output_rightviewer", "Stream", true);
    movidthread->procGraph->ConnectModules("input_source", "output_leftviewer");
    movidthread->procGraph->ConnectModules("input_source", "invert");
    movidthread->procGraph->ConnectModules("invert", "output_rightviewer");
    movidthread->procGraph->start();
    
    if (movidthread->Create() != wxTHREAD_NO_ERROR ) {
        wxLogMessage(wxT("movidthread->Create() != wxTHREAD_NO_ERROR"));
        return false;
    }
    if (movidthread->Run() != wxTHREAD_NO_ERROR) {
        wxLogMessage(wxT("movidthread->Run() != wxTHREAD_NO_ERROR"));
        return false;
    }

    use_Mainframe = true;

    mainframe = new CCVMainFrame(movidthread);
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
    if (movidthread->Pause() != wxTHREAD_NO_ERROR) {
        wxLogMessage(wxT("movidthread->Pause() != wxTHREAD_NO_ERROR"));
    }
    if (movidthread->Delete() != wxTHREAD_NO_ERROR) {
        wxLogMessage(wxT("movidthread->Delete() != wxTHREAD_NO_ERROR"));
    }

    return 0;
}
