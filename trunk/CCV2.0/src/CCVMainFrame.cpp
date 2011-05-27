/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVMainFrame.cpp
// Purpose:     Provide the main frame and callback functions
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#include <wx/dcclient.h>
#include <wx/image.h>
#include "CCVMainFrame.h"
#include "MovidGraph.h"

CCVMainFrame::CCVMainFrame() : CCVbaseMainFrame(NULL)
{
    movidProcess = NULL;
}

CCVMainFrame::CCVMainFrame(CCVMovidProcess *movidProc) : CCVbaseMainFrame(NULL)
{
    SetMovid(movidProc);
    //SetMovidPipe_test();
}

void CCVMainFrame::SetMovidPipe_test()
{
    if (movidProcess == NULL)
        return;

    MovidGraph graph;
    graph.AddModule("input_camera", "Camera");
    graph.AddModule("output_leftviewer", "Stream");
    graph.ConnectModules("input_camera", "output_leftviewer");
    
    movidProcess->SetPipeline(graph);
}

void CCVMainFrame::SetMovid(CCVMovidProcess *movidProc)
{
    movidProcess = movidProc;
    movidProcess->setEventHandler(this);
    Disconnect(newEVT_MOVIDPROCESS_NEWIMAGE, wxCommandEventHandler(CCVMainFrame::OnMovidImage));
    Connect(newEVT_MOVIDPROCESS_NEWIMAGE, wxCommandEventHandler(CCVMainFrame::OnMovidImage));
}

void CCVMainFrame::OnMovidImage(wxCommandEvent &command)
{
    DrawCameraImage(m_panel_inputViewer);
}

void CCVMainFrame::DrawCameraImage(wxWindow *drawRec) {
    wxPaintDC dc(drawRec);

    if(! dc.Ok())
        return;

    int x,y,w,h;
    dc.GetClippingBox( &x, &y, &w, &h );
    unsigned char *rawData = movidProcess->getOutRGBRaw();
    if ( rawData == NULL )
        return;
    CvSize *roi = movidProcess->getRoi();

    if (w==0 || h==0 || roi->width==0 || roi->height==0) {
        return;
    }

    wxImage pWxImg = wxImage(roi->width, roi->height, rawData, TRUE);
    wxBitmap bmp = wxBitmap(pWxImg.Scale(w, h));
    dc.DrawBitmap(bmp, x, y);
}
