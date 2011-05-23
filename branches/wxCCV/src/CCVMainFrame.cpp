/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVMainFrame.cpp
// Purpose:     Provide the main frame and callback functions
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#include <wx/dcclient.h>
#include <wx/image.h>
#include "CCVMainFrame.h"

void CCVMainFrame::SetMovid(CCVMovidProcess *movidProc)
{
    movidProcess = movidProc;
}

void CCVMainFrame::OnInputViewerPaint(wxPaintEvent& event)
{
    wxWindow* drawRec = m_panel_inputViewer;
    wxPaintDC dc(drawRec);
    
    if(! dc.Ok())
        return;
        
    int x,y,w,h;
    dc.GetClippingBox( &x, &y, &w, &h );

    unsigned char *rawData = movidProcess->getOutRaw();
	CvSize *roi = movidProcess->getRoi();
	
    wxImage pWxImg = wxImage(roi->width, roi->height, rawData, TRUE);
	wxBitmap bmp = wxBitmap(pWxImg.Scale(w, h));
    dc.DrawBitmap(bmp, x, y);
}
