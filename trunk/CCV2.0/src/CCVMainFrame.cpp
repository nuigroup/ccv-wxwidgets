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
    paramHook = NULL;
}

CCVMainFrame::CCVMainFrame(CCVWorkerEngine *movidProc, CCVGlobalParam *_param) : CCVbaseMainFrame(NULL)
{
    CCVMainFrame();
    paramHook = _param;

    m_radioBox_selectInput->SetSelection(paramHook->input_source);
    m_slider_imageThre->SetValue(paramHook->initThreshold);
    m_slider_minBlob->SetValue(paramHook->initMinBlob);
    m_slider_maxBlob->SetValue(paramHook->initMaxBlob);
    m_checkBox_background->SetValue(paramHook->backgroundsub_enabled);    
    m_checkBox_amp->SetValue(paramHook->amplify_enabled);     
    m_checkBox_highpass->SetValue(paramHook->highpass_enabled);
    m_checkBox_smooth->SetValue(paramHook->smooth_enabled);

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
    DrawCameraImage(rawImages["output_background"], m_panel_background_viewer);
    DrawCameraImage(rawImages["output_amplify"], m_panel_amp_viewer);
    DrawCameraImage(rawImages["output_highpass"], m_panel_highpass_viewer);
    DrawCameraImage(rawImages["output_smooth"], m_panel_smooth_viewer);
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
    moModule *moOldInput = movidProcess->procGraph->getModuleById("input_source");
    moOldInput->property("id").set("tmp");
    moModule *moNewInput = NULL;
    if (moOldInput==NULL) {
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

    movidProcess->procGraph->ReplaceModule(moOldInput, moNewInput);
    movidProcess->procGraph->removeElement(moOldInput);
    movidProcess->procGraph->start();
    // wxLogMessage(wxT("AFTER movidProcess->procGraph->start();"));
    movidProcess->Resume();
    // wxLogMessage(wxT("AFTER movidProcess->procGraph->Resume();"));
}

void CCVMainFrame::m_slider_imageThreOnScroll( wxScrollEvent& event )
{
    int newVaule = m_slider_imageThre->GetValue();
    if (movidProcess->SafeSetProperty("threshold", "threshold", newVaule) == CCV_SUCCESS) {
        wxLogMessage(wxT("MESSAGE SafeSetProperty(threshold, threshold, %d)"), newVaule);
        paramHook->initThreshold = newVaule;
    }
    else {
        wxLogMessage(wxT("MESSAGE SafeSetProperty Returned without setting."));
        m_slider_imageThre->SetValue(paramHook->initThreshold);
        return;
    }
}

void CCVMainFrame::m_slider_minBlobOnScrollThumbRelease( wxScrollEvent& event )
{
    int newVaule = m_slider_minBlob->GetValue();
    if (movidProcess->SafeSetProperty("blobfinder", "min_size", newVaule) == CCV_SUCCESS) {
        wxLogMessage(wxT("MESSAGE movidProcess->SafeSetProperty(blobfinder, min_size, %d)"), newVaule);
        paramHook->initMinBlob = newVaule;
    }
    else {
        wxLogMessage(wxT("MESSAGE SafeSetProperty Returned without setting."));
        m_slider_minBlob->SetValue(paramHook->initMinBlob);
        return;
    }
}

void CCVMainFrame::m_slider_maxBlobOnScrollThumbRelease( wxScrollEvent& event )
{
    int newVaule = m_slider_maxBlob->GetValue();
    if (movidProcess->SafeSetProperty("blobfinder", "max_size", newVaule) == CCV_SUCCESS) {
        wxLogMessage(wxT("MESSAGE movidProcess->SafeSetProperty(blobfinder, max_size, %d)"), newVaule);
        paramHook->initMaxBlob = newVaule;
    }
    else {
        wxLogMessage(wxT("MESSAGE SafeSetProperty Returned without setting."));
        m_slider_maxBlob->SetValue(paramHook->initMaxBlob);
        return;
    }
}

void CCVMainFrame::m_checkBox_backgroundOnCheckBox( wxCommandEvent& event )
{
    int enable = m_checkBox_background->GetValue();
    std::string bgModule = enable ? "bgSubtract" : "bgSubtract_dummy";
    std::string ampModule = paramHook->amplify_enabled ? "amplify" : "amplify_dummy";
    std::string hpassModule = paramHook->highpass_enabled ? "highpass" : "highpass_dummy";
    std::string smoothModule = paramHook->smooth_enabled ? "smooth" : "smooth_dummy";
    
    movidProcess->procGraph->ConnectModules("input_source", bgModule);
    movidProcess->procGraph->ConnectModules(bgModule, ampModule);
    movidProcess->procGraph->ConnectModules(bgModule, "output_background");

    paramHook->backgroundsub_enabled = enable;
}

void CCVMainFrame::m_checkBox_recaptureOnCheckBox( wxCommandEvent& event )
{

}

void CCVMainFrame::m_checkBox_toggleOnCheckBox( wxCommandEvent& event )
{

}

void CCVMainFrame::m_checkBox_absoluteOnCheckBox( wxCommandEvent& event )
{

}

void CCVMainFrame::m_checkBox_ampOnCheckBox( wxCommandEvent& event )
{
    int enable = m_checkBox_amp->GetValue();
    std::string bgModule = paramHook->backgroundsub_enabled ? "bgSubtract" : "bgSubtract_dummy";
    std::string ampModule = enable ? "amplify" : "amplify_dummy";
    std::string hpassModule = paramHook->highpass_enabled ? "highpass" : "highpass_dummy";
    std::string smoothModule = paramHook->smooth_enabled ? "smooth" : "smooth_dummy";
    
    movidProcess->procGraph->ConnectModules(bgModule, ampModule);
    movidProcess->procGraph->ConnectModules(ampModule, hpassModule);
    movidProcess->procGraph->ConnectModules(ampModule, "output_amplify");

    paramHook->amplify_enabled = enable;
}

void CCVMainFrame::m_slider_ampOnScrollThumbRelease( wxScrollEvent& event )
{

}

void CCVMainFrame::m_checkBox_highpassOnCheckBox( wxCommandEvent& event )
{
    int enable = m_checkBox_highpass->GetValue();
    std::string bgModule = paramHook->backgroundsub_enabled ? "bgSubtract" : "bgSubtract_dummy";
    std::string ampModule = paramHook->amplify_enabled ? "amplify" : "amplify_dummy";
    std::string hpassModule = enable ? "highpass" : "highpass_dummy";
    std::string smoothModule = paramHook->smooth_enabled ? "smooth" : "smooth_dummy";    
    
    movidProcess->procGraph->ConnectModules(ampModule, hpassModule);
    movidProcess->procGraph->ConnectModules(hpassModule, smoothModule);
    movidProcess->procGraph->ConnectModules(hpassModule, "output_highpass");

    paramHook->highpass_enabled = enable;
}

void CCVMainFrame::m_slider_blurOnScrollThumbRelease( wxScrollEvent& event )
{

}

void CCVMainFrame::m_slider_noiseOnScrollThumbRelease( wxScrollEvent& event )
{

}

void CCVMainFrame::m_checkBox_smoothOnCheckBox( wxCommandEvent& event )
{
    int enable = m_checkBox_smooth->GetValue();
    std::string bgModule = paramHook->backgroundsub_enabled ? "bgSubtract" : "bgSubtract_dummy";
    std::string ampModule = paramHook->amplify_enabled ? "amplify" : "amplify_dummy";
    std::string hpassModule = paramHook->highpass_enabled ? "highpass" : "highpass_dummy";
    std::string smoothModule = enable ? "smooth" : "smooth_dummy";
    
    movidProcess->procGraph->ConnectModules(hpassModule, smoothModule);
    movidProcess->procGraph->ConnectModules(smoothModule, "grayscale");
    movidProcess->procGraph->ConnectModules(smoothModule, "output_smooth");

    paramHook->smooth_enabled = enable;
}

void CCVMainFrame::m_slider_smoothOnScrollThumbRelease( wxScrollEvent& event )
{

}

void CCVMainFrame::m_radioBox_smoothtypeOnRadioBox( wxCommandEvent& event )
{

}

