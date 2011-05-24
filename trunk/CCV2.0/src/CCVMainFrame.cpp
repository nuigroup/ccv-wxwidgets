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
    Disconnect(newEVT_MOVIDPROCESS_NEWIMAGE, wxCommandEventHandler(CCVMainFrame::onMovidImage));
    Connect(newEVT_MOVIDPROCESS_NEWIMAGE, wxCommandEventHandler(CCVMainFrame::onMovidImage));
}

void CCVMainFrame::onMovidImage(wxCommandEvent &command)
{
    drawCameraImage();
}

void CCVMainFrame::OnInputViewerPaint(wxPaintEvent& event)
{
    drawCameraImage();
}

void CCVMainFrame::drawCameraImage() {
    wxPanel* drawRec = m_panel_inputViewer;
    wxPaintDC dc(drawRec);

    if(! dc.Ok())
        return;

    int x,y,w,h;
    dc.GetClippingBox( &x, &y, &w, &h );
    unsigned char *rawData = movidProcess->getOutRaw();
    if ( rawData == NULL )
        return;
    CvSize *roi = movidProcess->getRoi();

    // FIXME when clipping box is w,h == 0,0, so nothing is displayer...
    if ( w == 0 ) {
        dc.SetClippingRegion(0, 0, roi->width, roi->height);
        dc.GetClippingBox( &x, &y, &w, &h );
    }

    wxImage pWxImg = wxImage(roi->width, roi->height, rawData, TRUE);
    wxBitmap bmp = wxBitmap(pWxImg.Scale(w, h));
    dc.DrawBitmap(bmp, x, y);
}
