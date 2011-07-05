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
    paramHook = NULL;
}

CCVMainFrame::CCVMainFrame(CCVWorkerEngine *movidProc, CCVGlobalParam *_param) : CCVbaseMainFrame(NULL)
{
    CCVMainFrame();
    paramHook = _param;

    curThreshold = paramHook->initThreshold;
    m_slider_imageThre->SetValue(curThreshold);

    curMinBlob = paramHook->initMinBlob;
    m_slider_minBlob->SetValue(curMinBlob);

    curMaxBlob = paramHook->initMaxBlob;
    m_slider_maxBlob->SetValue(curMaxBlob);

    SetWorkerEngine(movidProc);
}

void CCVMainFrame::SetWorkerEngine(CCVWorkerEngine *movidProc)
{
    movidProcess = movidProc;
    movidProcess->setEventHandler(this);
    Disconnect(newEVT_MOVIDPROCESS_NEWIMAGE, wxCommandEventHandler(CCVMainFrame::OnMovidImage));
    Connect(newEVT_MOVIDPROCESS_NEWIMAGE, wxCommandEventHandler(CCVMainFrame::OnMovidImage));
    wxLogMessage(wxT("FINISH CCVMainFrame::SetWorkerEngine()"));
}

void CCVMainFrame::OnMovidImage(wxCommandEvent &command)
{
    OutImagesMap rawImages = movidProcess->getOutImages();   
    DrawCameraImage(rawImages["output_leftviewer"], m_panel_inputViewer);
    DrawCameraImage(rawImages["output_rightviewer"], m_panel_outputViewer);
}

void CCVMainFrame::DrawCameraImage(OutRGBImage *rawImage, wxWindow *drawRec)
{
    wxClientDC dc(drawRec);

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
    // pWxImg.SaveFile("debug.bmp", wxBITMAP_TYPE_BMP); // For debug only
    wxBitmap bmp = wxBitmap(pWxImg.Scale(w, h));    
    dc.DrawBitmap(bmp, x, y);    
}

void CCVMainFrame::m_radioBox_selectInputOnRadioBox( wxCommandEvent& event )
{
    wxLogMessage(wxT("BEGIN m_radioBox_selectInputOnRadioBox();"));
    int selectedId = m_radioBox_selectInput->GetSelection();
    if (movidProcess->procGraph->isBusy()) {
        wxLogMessage(wxT("MESSAGE movidProcess->procGraph->isBusy(). Return."));
        if (selectedId == CCV_SOURCE_CAMERA) {
            m_radioBox_selectInput->SetSelection(CCV_SOURCE_FILE);
        }
        else if (selectedId == CCV_SOURCE_FILE) {
            m_radioBox_selectInput->SetSelection(CCV_SOURCE_CAMERA);
        }
        return;
    }    
    movidProcess->Pause();
    movidProcess->procGraph->stop();
    // wxLogMessage(wxT("AFTER movidProcess->procGraph->stop();"));    
    moModule *moInput = movidProcess->procGraph->getModuleById("input_source");
    moInput->property("id").set("tmp");
    moModule *moNewInput = NULL;
    if (moInput==NULL) {
        wxLogMessage(wxT("ERROR procGraph->getModuleById==NULL"));
        return;
    }
    
    if (selectedId == CCV_SOURCE_CAMERA) {
        moNewInput = movidProcess->procGraph->AddModule("input_source", "Camera");
    }
    else if (selectedId == CCV_SOURCE_FILE) {
        moNewInput = movidProcess->procGraph->AddModule("input_source", "Video");
        moNewInput->property("filename").set(paramHook->videoFileName);        
    }        
    else 
        wxLogMessage( wxT("ERROR Unknown Input Source."));

    movidProcess->procGraph->ReplaceModule(moInput, moNewInput);
    movidProcess->procGraph->start();
    // wxLogMessage(wxT("AFTER movidProcess->procGraph->start();"));
    movidProcess->Resume();
    // wxLogMessage(wxT("AFTER movidProcess->procGraph->Resume();"));
}

void CCVMainFrame::m_slider_imageThreOnScroll( wxScrollEvent& event )
{
    int newVaule = m_slider_imageThre->GetValue();
    if (movidProcess->SafeSetProperty("threshold", "threshold", newVaule) == CCV_SUCCESS) {
        wxLogMessage(wxT("MSG SafeSetProperty Returned successfully."));
        curThreshold = newVaule;
    }
    else {
        wxLogMessage(wxT("MSG SafeSetProperty Returned without setting."));
        m_slider_imageThre->SetValue(curThreshold);
        return;
    }
}

void CCVMainFrame::m_slider_minBlobOnScrollThumbRelease( wxScrollEvent& event )
{
    int newVaule = m_slider_minBlob->GetValue();
    if (movidProcess->SafeSetProperty("blobfinder", "min_size", newVaule) == CCV_SUCCESS) {
        wxLogMessage(wxT("MSG SafeSetProperty Returned successfully."));
        curMinBlob = newVaule;
    }
    else {
        wxLogMessage(wxT("MSG SafeSetProperty Returned without setting."));
        m_slider_minBlob->SetValue(curMinBlob);
        return;
    }
}

void CCVMainFrame::m_slider_maxBlobOnScrollThumbRelease( wxScrollEvent& event )
{
    int newVaule = m_slider_maxBlob->GetValue();
    if (movidProcess->SafeSetProperty("blobfinder", "max_size", newVaule) == CCV_SUCCESS) {
        wxLogMessage(wxT("MSG SafeSetProperty Returned successfully."));
        curMaxBlob = newVaule;
    }
    else {
        wxLogMessage(wxT("MSG SafeSetProperty Returned without setting."));
        m_slider_maxBlob->SetValue(curMaxBlob);
        return;
    }
}
