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
#include "CCVUtil.h"

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
#ifdef WIN32
    wxClientDC dc(drawRec);
#else
    wxPaintDC dc(drawRec);
#endif

    if(! dc.Ok() || rawImage==NULL)
        return;

    unsigned char *rawData = rawImage->data;
    if ( rawData == NULL )
        return;
    CvSize *roi = rawImage->outRoi;
	if (roi->width==0 || roi->height==0) {
        return;
    }

    wxCoord x,y,w,h;
#ifdef WIN32
	x = 0;
	y = 0;
	dc.GetSize( &w, &h );
#else
    dc.GetClippingBox( &x, &y, &w, &h );
#endif // WIN32
    if (w==0 || h==0) {
        return;
    }

    wxImage pWxImg = wxImage(roi->width, roi->height, rawData, true);
    wxBitmap bmp = wxBitmap(pWxImg.Scale(w, h));
    dc.DrawBitmap(bmp, x, y);
}
