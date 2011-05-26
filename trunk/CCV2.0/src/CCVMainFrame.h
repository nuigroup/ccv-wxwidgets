/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVMainFrame.h
// Purpose:     Provide the main frame and callback functions
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#ifndef _CCV_FRAME_H
#define _CCV_FRAME_H

#include <wx/wx.h>
#include "CCVbaseFrame.h"
#include "CCVMovidProcess.h"

//
// CCVbaseMainFrame is generated automatically by wxFormBuilder, CCVMainFrame
// extends CCVbaseMainFrame to implement the event handling functions.
//
class CCVMainFrame : public CCVbaseMainFrame
{
public:
    CCVMainFrame();
    void SetMovid(CCVMovidProcess *);

private:
    CCVMovidProcess *movidProcess;
    void DrawCameraImage(wxWindow *);
    void OnMovidImage(wxCommandEvent&);
};

#endif
