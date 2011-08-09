/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVMainFrame.h
// Purpose:     Provide the main frame and callback functions
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#ifndef _CCV_FRAME_H
#define _CCV_FRAME_H

#include <wx/wx.h>
#include "CCVCommon.h"
#include "CCVbaseFrame.h"
#include "CCVWorkerEngine.h"

/**
    CCVbaseMainFrame is generated automatically by wxFormBuilder, CCVMainFrame
    extends CCVbaseMainFrame to implement the event handling functions.
*/
class CCVMainFrame : public CCVbaseMainFrame
{
public:
    CCVMainFrame();
    CCVMainFrame(CCVWorkerEngine *, CCVGlobalParam *);
   
private:
    CCVWorkerEngine *movidProcess;    
    CCVGlobalParam *paramHook;
    void SetWorkerEngine(CCVWorkerEngine *);
    void UpdateDebugViewers();
    void DrawCameraImage(OutRGBImage *, wxWindow *);
    void OnMovidImage(wxCommandEvent&);

    int curCameraIndex;
    void updateCameraSelectButtonsState();

    void m_radioBox_selectInputOnRadioBox( wxCommandEvent& event );
    void m_button_prevCameraOnButtonClick( wxCommandEvent& event );
	void m_button_nextCameraOnButtonClick( wxCommandEvent& event );
    void m_slider_imageThreOnScroll( wxScrollEvent& event );
    void m_slider_minBlobOnScrollThumbRelease( wxScrollEvent& event );
	void m_slider_maxBlobOnScrollThumbRelease( wxScrollEvent& event );
    void m_checkBox_backgroundOnCheckBox( wxCommandEvent& event );
    void m_checkBox_toggleOnCheckBox( wxCommandEvent& event );
    void m_checkBox_absoluteOnCheckBox( wxCommandEvent& event );
    void m_checkBox_ampOnCheckBox( wxCommandEvent& event );
    void m_slider_ampOnScrollThumbRelease( wxScrollEvent& event );
    void m_checkBox_highpassOnCheckBox( wxCommandEvent& event );
    void m_slider_blurOnScrollThumbRelease( wxScrollEvent& event );
    void m_slider_noiseOnScrollThumbRelease( wxScrollEvent& event );
    void m_checkBox_smoothOnCheckBox( wxCommandEvent& event );
    void m_slider_smoothOnScrollThumbRelease( wxScrollEvent& event );
    void m_radioBox_smoothtypeOnRadioBox( wxCommandEvent& event );
    void m_slider_highpassampOnScroll( wxScrollEvent& event );
    void m_button_savesettingOnButtonClick( wxCommandEvent& event );
    void m_checkBox_tuioOnCheckBox( wxCommandEvent& event );
    void m_button_subbg_recaptureOnButtonClick( wxCommandEvent& event );
};

enum CCV_SOURCE_ID
{
    CCV_SOURCE_CAMERA,
    CCV_SOURCE_FILE,
};

#endif
