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
    movidProcess->setEventHandler(this);
    Disconnect(newEVT_MOVIDPROCESS_NEWIMAGE, wxCommandEventHandler(CCVMainFrame::OnMovidImage));
    Connect(newEVT_MOVIDPROCESS_NEWIMAGE, wxCommandEventHandler(CCVMainFrame::OnMovidImage));
}

void CCVMainFrame::OnMovidImage(wxCommandEvent &command)
{
    DrawCameraImage();
}

void CCVMainFrame::DrawCameraImage() {
    wxPanel* drawRec = m_panel_inputViewer;
    wxPaintDC dc(drawRec);

    if(! dc.Ok())
        return;

    int x,y,w,h;
    dc.GetClippingBox( &x, &y, &w, &h );
    unsigned char *rawData = movidProcess->getOutRGBRaw();
    if ( rawData == NULL )
        return;
    CvSize *roi = movidProcess->getRoi();

    // FIXME when clipping box is w,h == 0,0, so nothing is displayer...
    if (w==0 || h==0 || roi->width==0 || roi->height==0) {
        return;
        dc.SetClippingRegion(0, 0, roi->width, roi->height);
        dc.GetClippingBox( &x, &y, &w, &h );
    }

    wxImage pWxImg = wxImage(roi->width, roi->height, rawData, TRUE);
    wxBitmap bmp = wxBitmap(pWxImg.Scale(w, h));
    dc.DrawBitmap(bmp, x, y);
}
