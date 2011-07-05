/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVMainFrame.h
// Purpose:     Provide the main frame and callback functions
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#ifndef _CCV_FRAME_H
#define _CCV_FRAME_H

#include <wx/wx.h>
#include "CCVCommon.h"
#include "CCVbaseFrame.h"
#include "CCVWorkerEngine.h"

/**
    CCVbaseMainFrame is generated automatically by wxFormBuilder, CCVMainFrame
    extends CCVbaseMainFrame to implement the event handling functions.
*/
class CCVMainFrame : public CCVbaseMainFrame
{
public:
    CCVMainFrame();
    CCVMainFrame(CCVWorkerEngine *);
    void SetWorkerEngine(CCVWorkerEngine *);
    void SetGlobalParam(CCVGlobalParam *);
   
private:
    CCVWorkerEngine *movidProcess;    
    CCVGlobalParam *paramHook;
    void DrawCameraImage(OutRGBImage *, wxWindow *);
    void OnMovidImage(wxCommandEvent&);
    void m_radioBox_selectInputOnRadioBox( wxCommandEvent& event );
    void m_slider_imageThreOnScroll( wxScrollEvent& event );

    int curThreshold;
};

enum CCV_SOURCE_ID
{
    CCV_SOURCE_CAMERA,
    CCV_SOURCE_FILE,
};

#endif
