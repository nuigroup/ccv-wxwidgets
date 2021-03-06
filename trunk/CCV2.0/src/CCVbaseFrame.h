///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __CCVbaseFrame__
#define __CCVbaseFrame__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/checkbox.h>
#include <wx/radiobox.h>
#include <wx/button.h>
#include <wx/slider.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/statbox.h>
#include <wx/frame.h>
#include <wx/statline.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class CCVbaseMainFrame
///////////////////////////////////////////////////////////////////////////////
class CCVbaseMainFrame : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel_mainleft;
		wxStaticText* m_staticText_inputViewer;
		wxStaticText* m_staticText_outputViewer;
		wxPanel* m_panel_inputViewer;
		wxPanel* m_panel_outputViewer;
		wxPanel* m_panel_inputContrl;
		wxStaticText* m_staticText_title_inputctrl;
		
		wxCheckBox* m_checkBox_showoutline;
		wxCheckBox* m_checkBox_showid;
		
		wxRadioBox* m_radioBox_selectInput;
		wxPanel* m_panel22;
		wxButton* m_button_prevCamera;
		wxButton* m_button_nextCamera;
		wxPanel* m_panel_outputControl;
		wxNotebook* m_notebook_trackcontrol;
		wxPanel* m_panel_threshold;
		wxStaticText* m_staticText_imageThre;
		wxSlider* m_slider_imageThre;
		wxPanel* m_panel_blob;
		wxStaticText* m_staticText_minBlob;
		wxSlider* m_slider_minBlob;
		wxStaticText* m_staticText_maxBlob;
		wxSlider* m_slider_maxBlob;
		wxNotebook* m_notebook_filters;
		wxPanel* m_panel_background;
		wxPanel* m_panel_background_viewer;
		wxPanel* m_panel_background_ctrl;
		wxCheckBox* m_checkBox_background;
		
		wxCheckBox* m_checkBox_toggle;
		wxCheckBox* m_checkBox_absolute;
		wxButton* m_button_subbg_recapture;
		
		wxPanel* m_panel_amp;
		wxPanel* m_panel_amp_viewer;
		wxPanel* m_panel_amplify_ctrl;
		wxCheckBox* m_checkBox_amp;
		
		wxStaticText* m_staticText_ampctrl;
		wxSlider* m_slider_amp;
		
		wxPanel* m_panel_highpass;
		wxPanel* m_panel_highpass_viewer;
		wxPanel* m_panel_highpass_ctrl;
		wxCheckBox* m_checkBox_highpass;
		
		wxStaticText* m_staticText_highpass_blur;
		wxSlider* m_slider_blur;
		wxStaticText* m_staticText_highpass_size;
		wxSlider* m_slider_noise;
		wxStaticText* m_staticText_highpass_amp;
		wxSlider* m_slider_highpassamp;
		wxPanel* m_panel_smooth;
		wxPanel* m_panel_smooth_viewer;
		wxPanel* m_panel_smooth_ctrl;
		wxCheckBox* m_checkBox_smooth;
		
		wxStaticText* m_staticText_smoothctrl;
		wxSlider* m_slider_smooth;
		
		wxRadioBox* m_radioBox_smoothtype;
		wxPanel* m_panel_mainright;
		wxCheckBox* m_checkBox_filpV;
		wxCheckBox* m_checkBox_filpH;
		wxCheckBox* m_checkBox_gpu;
		wxCheckBox* m_checkBox_tuio;
		
		wxButton* m_button_camera_setting;
		wxButton* m_button_calibr;
		wxButton* m_button_savesetting;
		
		
		wxStaticText* m_staticText_sourceinfo;
		wxStaticText* m_staticText_out;
		wxStaticText* m_staticText_about;
		
		// Virtual event handlers, overide them in your derived class
		virtual void m_radioBox_selectInputOnRadioBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_button_prevCameraOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_button_nextCameraOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_slider_imageThreOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_slider_minBlobOnScrollThumbRelease( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_slider_maxBlobOnScrollThumbRelease( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_checkBox_backgroundOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox_toggleOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox_absoluteOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_button_subbg_recaptureOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox_ampOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_slider_ampOnScrollThumbRelease( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_checkBox_highpassOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_slider_blurOnScrollThumbRelease( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_slider_noiseOnScrollThumbRelease( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_slider_highpassampOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_checkBox_smoothOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_slider_smoothOnScrollThumbRelease( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_radioBox_smoothtypeOnRadioBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox_tuioOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_button_savesettingOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CCVbaseMainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Community Core Vision"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 950,650 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~CCVbaseMainFrame();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CCVbaseMiniFrame
///////////////////////////////////////////////////////////////////////////////
class CCVbaseMiniFrame : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel_mini_viewer;
		wxStaticLine* m_staticline_mini_row_1;
		wxStaticText* m_staticText_mini_row_1_left;
		
		wxStaticText* m_staticText_mini_row_1_right;
		wxStaticLine* m_staticline_mini_row_2;
		wxStaticText* m_staticText_mini_row_2_left;
		
		wxStaticText* m_staticText_mini_row_2_right;
		wxStaticLine* m_staticline_mini_row_3;
		wxStaticText* m_staticText_mini_row_3_left;
		
		wxStaticText* m_staticText_mini_row_3_right;
		wxStaticLine* m_staticline_mini_row_4;
		wxStaticText* m_staticText_mini_row_4_left;
		
		wxStaticText* m_staticText_mini_row_4_right;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		
	
	public:
		
		CCVbaseMiniFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("CCV - Mini"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 190,205 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~CCVbaseMiniFrame();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CCVAbout
///////////////////////////////////////////////////////////////////////////////
class CCVAbout : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_about_text;
	
	public:
		
		CCVAbout( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("About"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxCAPTION|wxDEFAULT_DIALOG_STYLE|wxSTAY_ON_TOP );
		~CCVAbout();
	
};

#endif //__CCVbaseFrame__
