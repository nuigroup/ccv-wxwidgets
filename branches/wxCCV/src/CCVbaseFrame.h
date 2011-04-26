///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __CCVbaseFrame__
#define __CCVbaseFrame__

#include <wx/sizer.h>
#include <wx/gdicmn.h>
#include <wx/string.h>
#include <wx/checkbox.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statbox.h>
#include <wx/radiobox.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class CCVbaseFrame
///////////////////////////////////////////////////////////////////////////////
class CCVbaseFrame : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel_control;
		wxCheckBox* m_checkBox_filpV;
		wxCheckBox* m_checkBox_filpH;
		wxCheckBox* m_checkBox_gpu;
		wxRadioBox* m_radioBox_ctrl_commu;
		wxButton* m_button_camera_setting;
		wxButton* m_button_calibr;
		wxButton* m_button_savesetting;
		
		
		wxStaticText* m_staticText_about;
	
	public:
		
		CCVbaseFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Community Core Visision"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 950,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~CCVbaseFrame();
	
};

#endif //__CCVbaseFrame__
