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
#include "ofxXmlSettings.h"

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
    m_slider_blur->SetValue(paramHook->initHighpassBlur);
    m_slider_noise->SetValue(paramHook->initHighpassSize);
    m_slider_highpassamp->SetValue(paramHook->initHighpassAmp);
    m_slider_amp->SetValue(paramHook->initAmplify);
    m_slider_smooth->SetValue(paramHook->initSmooth);

    m_checkBox_background->SetValue(paramHook->backgroundsub_enabled);    
    m_checkBox_amp->SetValue(paramHook->amplify_enabled);     
    m_checkBox_highpass->SetValue(paramHook->highpass_enabled);
    m_checkBox_smooth->SetValue(paramHook->smooth_enabled);
    m_checkBox_tuio->SetValue(paramHook->tuio_enabled);

    SetWorkerEngine(movidProc);

    UpdateDebugViewers();
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
    wxLogMessage(wxT("BEGIN CCVMainFrame::OnMovidImage()"));
    CCVWorkerEngineResQueue *resQueue = movidProcess->getResQueue();
    wxLogMessage(wxT("MSG Resource queue size: %d)"), resQueue->size());
    OutImagesMap rawImages = resQueue->front()->outImages;
    DrawCameraImage(rawImages["output_leftviewer"], m_panel_inputViewer);
    DrawCameraImage(rawImages["output_rightviewer"], m_panel_outputViewer);
    DrawCameraImage(rawImages["output_background"], m_panel_background_viewer);
    DrawCameraImage(rawImages["output_amplify"], m_panel_amp_viewer);
    DrawCameraImage(rawImages["output_highpass"], m_panel_highpass_viewer);
    DrawCameraImage(rawImages["output_smooth"], m_panel_smooth_viewer);
    delete resQueue->front();
    resQueue->pop();
}

void CCVMainFrame::DrawCameraImage(OutRGBImage *rawImage, wxWindow *drawRec)
{
    wxClientDC dc(drawRec);

    if(! dc.Ok() || rawImage==NULL)
        return;

    unsigned char *rawData = rawImage->data;
    if (rawData == NULL)
        return;
    CvSize *roi = rawImage->outRoi;
    if (roi == NULL)
        return;
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
    movidProcess->procGraph->getModuleById("threshold")->property("threshold").set(newVaule);
}

void CCVMainFrame::m_slider_minBlobOnScrollThumbRelease( wxScrollEvent& event )
{
    int newVaule = m_slider_minBlob->GetValue();
    movidProcess->procGraph->getModuleById("blobfinder")->property("min_size").set(newVaule);
}

void CCVMainFrame::m_slider_maxBlobOnScrollThumbRelease( wxScrollEvent& event )
{
    int newVaule = m_slider_maxBlob->GetValue();
    movidProcess->procGraph->getModuleById("blobfinder")->property("max_size").set(newVaule);
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
    int newVaule = m_checkBox_recapture->GetValue();
    bool enable = (newVaule > 0);
    movidProcess->procGraph->getModuleById("bgSubtract")->property("recapture").set(enable);
}

void CCVMainFrame::m_checkBox_toggleOnCheckBox( wxCommandEvent& event )
{
    int newVaule = m_checkBox_toggle->GetValue();
    bool enable = (newVaule > 0);
    movidProcess->procGraph->getModuleById("bgSubtract")->property("toggle").set(enable);
}

void CCVMainFrame::m_checkBox_absoluteOnCheckBox( wxCommandEvent& event )
{
    int newVaule = m_checkBox_absolute->GetValue();
    bool enable = (newVaule > 0);
    movidProcess->procGraph->getModuleById("bgSubtract")->property("absolute").set(enable);
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
    double newVaule = m_slider_amp->GetValue() / 100.0;
    movidProcess->procGraph->getModuleById("amplify")->property("amplification").set(newVaule);
}

void CCVMainFrame::m_checkBox_highpassOnCheckBox( wxCommandEvent& event )
{
    int enable = m_checkBox_highpass->GetValue();
    std::string ampModule = paramHook->amplify_enabled ? "amplify" : "amplify_dummy";
    std::string hpassModule = enable ? "highpass" : "highpass_dummy";
    std::string smoothModule = paramHook->smooth_enabled ? "smooth" : "smooth_dummy";    
    
    movidProcess->procGraph->ConnectModules(ampModule, hpassModule);
    movidProcess->procGraph->ConnectModules(hpassModule, "highpass_amplify");
    movidProcess->procGraph->ConnectModules("highpass_amplify", smoothModule);
    movidProcess->procGraph->ConnectModules("highpass_amplify", "output_highpass");

    paramHook->highpass_enabled = enable;
}

void CCVMainFrame::m_slider_blurOnScrollThumbRelease( wxScrollEvent& event )
{
    double newVaule = m_slider_blur->GetValue() / 10.0;
    movidProcess->procGraph->getModuleById("highpass")->property("blur").set(newVaule);
}

void CCVMainFrame::m_slider_noiseOnScrollThumbRelease( wxScrollEvent& event )
{
    double newVaule = m_slider_noise->GetValue() / 10.0;
    movidProcess->procGraph->getModuleById("highpass")->property("size").set(newVaule);
}

void CCVMainFrame::m_checkBox_smoothOnCheckBox( wxCommandEvent& event )
{
    int enable = m_checkBox_smooth->GetValue();
    std::string smoothModule = enable ? "smooth" : "smooth_dummy";
    
    movidProcess->procGraph->ConnectModules("highpass_amplify", smoothModule);
    movidProcess->procGraph->ConnectModules(smoothModule, "grayscale");
    movidProcess->procGraph->ConnectModules(smoothModule, "output_smooth");

    paramHook->smooth_enabled = enable;
}

void CCVMainFrame::m_slider_smoothOnScrollThumbRelease( wxScrollEvent& event )
{
    double newVaule = m_slider_smooth->GetValue() / 10.0;
    movidProcess->procGraph->getModuleById("smooth")->property("size").set(newVaule);
}

void CCVMainFrame::m_slider_highpassampOnScroll( wxScrollEvent& event )
{
    double newVaule = m_slider_highpassamp->GetValue() / 100.0;
    movidProcess->procGraph->getModuleById("amplify")->property("amplification").set(newVaule);
}

void CCVMainFrame::m_radioBox_smoothtypeOnRadioBox( wxCommandEvent& event )
{
    int sId = m_radioBox_selectInput->GetSelection();
    moModule *mo = movidProcess->procGraph->getModuleById("smooth");

    if (sId == 0) {
        mo->property("filter").set("median");
    }
    else if (sId == 1) {
        mo->property("filter").set("gaussian");
    }
    else if (sId == 2) {
        mo->property("filter").set("blur");
    }
    else if (sId == 3) {
        mo->property("filter").set("blur_no_scale");
    }
    else;
}

void CCVMainFrame::m_button_savesettingOnButtonClick( wxCommandEvent& event )
{
    ofxXmlSettings XML;
    if (! XML.loadFile(CONFIGFILE))
        return;

    XML.setValue("CONFIG:INIT:Threshold", m_slider_imageThre->GetValue());
    XML.setValue("CONFIG:INIT:MinBlob", m_slider_minBlob->GetValue());
    XML.setValue("CONFIG:INIT:MaxBlob", m_slider_maxBlob->GetValue());
    XML.setValue("CONFIG:INIT:HighpassBlur", m_slider_blur->GetValue());
    XML.setValue("CONFIG:INIT:HighpassSize", m_slider_noise->GetValue());
    XML.setValue("CONFIG:INIT:HighpassAmp", m_slider_highpassamp->GetValue());
    XML.setValue("CONFIG:INIT:Amplify", m_slider_amp->GetValue());
    XML.setValue("CONFIG:INIT:Smooth", m_slider_smooth->GetValue());

    XML.setValue("CONFIG:INIT:EnableSubBackground", paramHook->backgroundsub_enabled);
    XML.setValue("CONFIG:INIT:EnableAmplify", paramHook->amplify_enabled);
    XML.setValue("CONFIG:INIT:EnableHighpass", paramHook->highpass_enabled);
    XML.setValue("CONFIG:INIT:EnableSmooth", paramHook->smooth_enabled);

    XML.saveFile(CONFIGFILE);
    wxMessageBox(wxT("Settings have been saved successfully."));
}

void CCVMainFrame::m_checkBox_tuioOnCheckBox( wxCommandEvent& event )
{
    int enabled = m_checkBox_tuio->GetValue();
    if (enabled) {
        movidProcess->procGraph->ConnectModules("blobtracker", "tuio");
    }
    else {
        movidProcess->procGraph->getModuleById("tuio")->setInput(NULL, 0);
    }
    paramHook->tuio_enabled = enabled;
    UpdateDebugViewers();
}

void CCVMainFrame::UpdateDebugViewers()
{
    wxString msgText;
    if (m_checkBox_tuio->GetValue()) {
        msgText = wxString::Format("Senting messages on TUIO ..\nProtocol: UDP\nHost %s\nPort: %d\n", paramHook->output_ipAddress.c_str(), paramHook->output_port);
    }
    else {
        msgText = "No Communication.";
        
    }
    m_staticText_out->SetLabel(msgText);
}
