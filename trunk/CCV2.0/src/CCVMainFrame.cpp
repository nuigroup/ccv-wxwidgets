/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVMainFrame.cpp
// Purpose:     Provide the main frame and callback functions
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#include <wx/dcclient.h>
#include <wx/image.h>
#include "CCVMainFrame.h"
#include "CCVProcGraph.h"
#include "CCVWorkerEngine.h"

CCVMainFrame::CCVMainFrame() : CCVbaseMainFrame(NULL)
{
    movidProcess = NULL;
}

CCVMainFrame::CCVMainFrame(CCVWorkerEngine *movidProc) : CCVbaseMainFrame(NULL)
{
    SetWorkerEngine(movidProc);
}

void CCVMainFrame::SetWorkerEngine(CCVWorkerEngine *movidProc)
{
    movidProcess = movidProc;
    movidProcess->setEventHandler(this);
    Disconnect(newEVT_MOVIDPROCESS_NEWIMAGE, wxCommandEventHandler(CCVMainFrame::OnMovidImage));
    Connect(newEVT_MOVIDPROCESS_NEWIMAGE, wxCommandEventHandler(CCVMainFrame::OnMovidImage));
}

void CCVMainFrame::OnMovidImage(wxCommandEvent &command)
{
    OutImagesMap rawImages = movidProcess->getOutImages();   
    DrawCameraImage(rawImages["output_leftviewer"], m_panel_inputViewer);
    DrawCameraImage(rawImages["output_rightviewer"], m_panel_outputViewer);
}

void CCVMainFrame::DrawCameraImage(OutRGBImage *rawImage, wxWindow *drawRec) {
    wxPaintDC dc(drawRec);

    if(! dc.Ok() || rawImage==NULL)
        return;

    int x,y,w,h;
    dc.GetClippingBox( &x, &y, &w, &h );
     
    unsigned char *rawData = rawImage->data;
    if ( rawData == NULL )
        return;
    CvSize *roi = rawImage->outRoi;

    if (w==0 || h==0 || roi->width==0 || roi->height==0) {
        return;
    }

    wxImage pWxImg = wxImage(roi->width, roi->height, rawData, TRUE);
    wxBitmap bmp = wxBitmap(pWxImg.Scale(w, h));
    dc.DrawBitmap(bmp, x, y);
}
