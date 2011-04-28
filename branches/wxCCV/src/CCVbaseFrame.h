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
#include <wx/statbox.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class CCVbaseFrame
///////////////////////////////////////////////////////////////////////////////
class CCVbaseFrame : public wxFrame 
{
	private:
	
	protected:
		wxPanel* panelleft;
		wxStaticText* m_staticText_inputViewer;
		wxStaticText* m_staticText_outputViewer;
		wxPanel* m_panel_inputViewer;
		wxPanel* m_panel_outputViewer;
		wxPanel* m_panel_inputContrl;
		wxStaticText* m_staticText_title_inputctrl;
		
		wxCheckBox* m_checkBox_showoutline;
		wxCheckBox* m_checkBox_showid;
		
		wxRadioBox* m_radioBox_selectInput;
		
		wxButton* m_button_prevCamera;
		wxButton* m_button_nextCamera;
		wxPanel* m_panel_outputControl;
		wxStaticText* m_staticText_title_outputctrl;
		
		wxCheckBox* m_checkBox13;
		
		wxStaticText* m_staticText8;
		wxSlider* m_slider9;
		wxStaticText* m_staticText9;
		wxSlider* m_slider10;
		wxStaticText* m_staticText10;
		wxSlider* m_slider11;
		wxStaticText* m_staticText11;
		wxSlider* m_slider12;
		
		wxPanel* m_panel_background;
		wxPanel* m_panel_smooth;
		wxPanel* m_panel_highpass;
		wxPanel* m_panel_amplify;
		wxPanel* m_panel_background_ctrl;
		wxStaticText* m_staticText101;
		
		wxCheckBox* m_checkBox8;
		wxCheckBox* m_checkBox9;
		wxStaticText* m_staticText12;
		wxSlider* m_slider6;
		
		wxPanel* m_panel_smooth_ctrl;
		wxStaticText* m_staticText13;
		
		wxCheckBox* m_checkBox10;
		wxStaticText* m_staticText14;
		wxSlider* m_slider7;
		
		wxPanel* m_panel_highpass_ctrl;
		wxStaticText* m_staticText15;
		
		wxCheckBox* m_checkBox111;
		wxStaticText* m_staticText17;
		wxSlider* m_slider8;
		wxStaticText* m_staticText18;
		wxSlider* m_slider91;
		wxPanel* m_panel_amplify_ctrl;
		wxStaticText* m_staticText16;
		
		wxCheckBox* m_checkBox121;
		wxStaticText* m_staticText19;
		wxSlider* m_slider101;
		wxPanel* panelright;
		wxCheckBox* m_checkBox_filpV;
		wxCheckBox* m_checkBox_filpH;
		wxCheckBox* m_checkBox_gpu;
		wxRadioBox* m_radioBox_ctrl_commu;
		wxButton* m_button_camera_setting;
		wxButton* m_button_calibr;
		wxButton* m_button_savesetting;
		
		
		wxStaticText* m_staticText_about;
	
	public:
		
		CCVbaseFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Community Core Visision"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1024,731 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~CCVbaseFrame();
	
};

#endif //__CCVbaseFrame__
