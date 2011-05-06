///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "CCVbaseFrame.h"

///////////////////////////////////////////////////////////////////////////

CCVbaseMainFrame::CCVbaseMainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 950,650 ), wxSize( 950,650 ) );
	
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxHORIZONTAL );
	
	panelleft = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	panelleft->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	wxBoxSizer* s_leftMain;
	s_leftMain = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* s_title;
	s_title = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText_inputViewer = new wxStaticText( panelleft, wxID_ANY, wxT("Source"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText_inputViewer->Wrap( -1 );
	m_staticText_inputViewer->SetFont( wxFont( 14, 74, 90, 90, false, wxT("Verdana") ) );
	m_staticText_inputViewer->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	
	s_title->Add( m_staticText_inputViewer, 1, wxEXPAND|wxALL, 10 );
	
	m_staticText_outputViewer = new wxStaticText( panelleft, wxID_ANY, wxT("Tracked"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText_outputViewer->Wrap( -1 );
	m_staticText_outputViewer->SetFont( wxFont( 14, 74, 90, 90, false, wxT("Verdana") ) );
	m_staticText_outputViewer->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	
	s_title->Add( m_staticText_outputViewer, 1, wxEXPAND|wxALL, 10 );
	
	s_leftMain->Add( s_title, 0, wxEXPAND, 5 );
	
	wxBoxSizer* s_input;
	s_input = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel_inputViewer = new wxPanel( panelleft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL );
	m_panel_inputViewer->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	s_input->Add( m_panel_inputViewer, 1, wxEXPAND|wxRIGHT|wxLEFT, 20 );
	
	m_panel_outputViewer = new wxPanel( panelleft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL );
	m_panel_outputViewer->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	s_input->Add( m_panel_outputViewer, 1, wxEXPAND|wxRIGHT|wxLEFT, 20 );
	
	s_leftMain->Add( s_input, 5, wxEXPAND, 5 );
	
	wxBoxSizer* s_inout_ctrl;
	s_inout_ctrl = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel_inputContrl = new wxPanel( panelleft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	m_panel_inputContrl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	wxBoxSizer* s_inputContrl;
	s_inputContrl = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* s_inputContrl_up;
	s_inputContrl_up = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText_title_inputctrl = new wxStaticText( m_panel_inputContrl, wxID_ANY, wxT("Source Image"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_title_inputctrl->Wrap( -1 );
	s_inputContrl_up->Add( m_staticText_title_inputctrl, 0, wxALL, 5 );
	
	
	s_inputContrl_up->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_checkBox_showoutline = new wxCheckBox( m_panel_inputContrl, wxID_ANY, wxT("Show Outlines"), wxDefaultPosition, wxDefaultSize, 0 );
	s_inputContrl_up->Add( m_checkBox_showoutline, 0, wxALL, 5 );
	
	m_checkBox_showid = new wxCheckBox( m_panel_inputContrl, wxID_ANY, wxT("Show IDs"), wxDefaultPosition, wxDefaultSize, 0 );
	s_inputContrl_up->Add( m_checkBox_showid, 0, wxALL, 5 );
	
	s_inputContrl->Add( s_inputContrl_up, 0, wxEXPAND, 5 );
	
	
	s_inputContrl->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_inputContrl_down;
	s_inputContrl_down = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_radioBox_selectInputChoices[] = { wxT("Use Camera"), wxT("Use Video") };
	int m_radioBox_selectInputNChoices = sizeof( m_radioBox_selectInputChoices ) / sizeof( wxString );
	m_radioBox_selectInput = new wxRadioBox( m_panel_inputContrl, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_radioBox_selectInputNChoices, m_radioBox_selectInputChoices, 1, wxRA_SPECIFY_COLS );
	m_radioBox_selectInput->SetSelection( 0 );
	s_inputContrl_down->Add( m_radioBox_selectInput, 0, wxALL, 5 );
	
	
	s_inputContrl_down->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer_camera_sel;
	bSizer_camera_sel = new wxBoxSizer( wxVERTICAL );
	
	m_button_prevCamera = new wxButton( m_panel_inputContrl, wxID_ANY, wxT("Prev Camera"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_prevCamera->Enable( false );
	
	bSizer_camera_sel->Add( m_button_prevCamera, 0, wxALIGN_CENTER|wxEXPAND|wxALL, 5 );
	
	m_button_nextCamera = new wxButton( m_panel_inputContrl, wxID_ANY, wxT("Next Camera"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_nextCamera->Enable( false );
	
	bSizer_camera_sel->Add( m_button_nextCamera, 0, wxALIGN_CENTER|wxEXPAND|wxALL, 5 );
	
	s_inputContrl_down->Add( bSizer_camera_sel, 2, wxEXPAND|wxRIGHT, 10 );
	
	s_inputContrl->Add( s_inputContrl_down, 0, wxEXPAND, 5 );
	
	m_panel_inputContrl->SetSizer( s_inputContrl );
	m_panel_inputContrl->Layout();
	s_inputContrl->Fit( m_panel_inputContrl );
	s_inout_ctrl->Add( m_panel_inputContrl, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 20 );
	
	m_panel_outputControl = new wxPanel( panelleft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	m_panel_outputControl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	wxBoxSizer* s_outputControl;
	s_outputControl = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* s_outputCtrl_up;
	s_outputCtrl_up = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText_title_outputctrl = new wxStaticText( m_panel_outputControl, wxID_ANY, wxT("Tracked Image"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_title_outputctrl->Wrap( -1 );
	s_outputCtrl_up->Add( m_staticText_title_outputctrl, 0, wxALL, 5 );
	
	
	s_outputCtrl_up->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_checkBox13 = new wxCheckBox( m_panel_outputControl, wxID_ANY, wxT("Inverse"), wxDefaultPosition, wxDefaultSize, 0 );
	s_outputCtrl_up->Add( m_checkBox13, 0, wxALL, 5 );
	
	s_outputControl->Add( s_outputCtrl_up, 0, wxEXPAND, 5 );
	
	
	s_outputControl->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxGridSizer* s_outputCtrl_down;
	s_outputCtrl_down = new wxGridSizer( 2, 2, 0, 0 );
	
	wxBoxSizer* s_imageThre;
	s_imageThre = new wxBoxSizer( wxVERTICAL );
	
	m_staticText_imageThre = new wxStaticText( m_panel_outputControl, wxID_ANY, wxT("Image Threshold"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_imageThre->Wrap( -1 );
	s_imageThre->Add( m_staticText_imageThre, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider_imageThre = new wxSlider( m_panel_outputControl, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	s_imageThre->Add( m_slider_imageThre, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	s_outputCtrl_down->Add( s_imageThre, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_moveFilter;
	s_moveFilter = new wxBoxSizer( wxVERTICAL );
	
	m_staticText_moveFilter = new wxStaticText( m_panel_outputControl, wxID_ANY, wxT("Movement Filter"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_moveFilter->Wrap( -1 );
	s_moveFilter->Add( m_staticText_moveFilter, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider_moveFilter = new wxSlider( m_panel_outputControl, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	s_moveFilter->Add( m_slider_moveFilter, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	s_outputCtrl_down->Add( s_moveFilter, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_minBlob;
	s_minBlob = new wxBoxSizer( wxVERTICAL );
	
	m_staticText_minBlob = new wxStaticText( m_panel_outputControl, wxID_ANY, wxT("Min Blob Size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_minBlob->Wrap( -1 );
	s_minBlob->Add( m_staticText_minBlob, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider_minBlob = new wxSlider( m_panel_outputControl, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	s_minBlob->Add( m_slider_minBlob, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	s_outputCtrl_down->Add( s_minBlob, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_maxBlob;
	s_maxBlob = new wxBoxSizer( wxVERTICAL );
	
	m_staticText_maxBlob = new wxStaticText( m_panel_outputControl, wxID_ANY, wxT("Max Blob Size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_maxBlob->Wrap( -1 );
	s_maxBlob->Add( m_staticText_maxBlob, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider_maxBlob = new wxSlider( m_panel_outputControl, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	s_maxBlob->Add( m_slider_maxBlob, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	s_outputCtrl_down->Add( s_maxBlob, 1, wxEXPAND, 5 );
	
	s_outputControl->Add( s_outputCtrl_down, 0, wxEXPAND, 5 );
	
	m_panel_outputControl->SetSizer( s_outputControl );
	m_panel_outputControl->Layout();
	s_outputControl->Fit( m_panel_outputControl );
	s_inout_ctrl->Add( m_panel_outputControl, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 20 );
	
	s_leftMain->Add( s_inout_ctrl, 0, wxEXPAND, 5 );
	
	m_notebook_filters = new wxNotebook( panelleft, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel_background = new wxPanel( m_notebook_filters, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* s_background;
	s_background = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel_background_viewer = new wxPanel( m_panel_background, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL );
	m_panel_background_viewer->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	s_background->Add( m_panel_background_viewer, 2, wxEXPAND | wxALL, 5 );
	
	m_panel_background_ctrl = new wxPanel( m_panel_background, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	m_panel_background_ctrl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	wxBoxSizer* s_background_ctrl_h;
	s_background_ctrl_h = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer_background_ctrl;
	bSizer_background_ctrl = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer_background_ctrl->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_checkBox_removeBG = new wxCheckBox( m_panel_background_ctrl, wxID_ANY, wxT("Remove BG"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_background_ctrl->Add( m_checkBox_removeBG, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_checkBox_dsubtract = new wxCheckBox( m_panel_background_ctrl, wxID_ANY, wxT("Dynamic Subtract"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_background_ctrl->Add( m_checkBox_dsubtract, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_staticText_learnspeed = new wxStaticText( m_panel_background_ctrl, wxID_ANY, wxT("Learn Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_learnspeed->Wrap( -1 );
	bSizer_background_ctrl->Add( m_staticText_learnspeed, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider_learnspeed = new wxSlider( m_panel_background_ctrl, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer_background_ctrl->Add( m_slider_learnspeed, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	s_background_ctrl_h->Add( bSizer_background_ctrl, 1, wxEXPAND, 5 );
	
	
	s_background_ctrl_h->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_panel_background_ctrl->SetSizer( s_background_ctrl_h );
	m_panel_background_ctrl->Layout();
	s_background_ctrl_h->Fit( m_panel_background_ctrl );
	s_background->Add( m_panel_background_ctrl, 6, wxALL|wxEXPAND, 5 );
	
	m_panel_background->SetSizer( s_background );
	m_panel_background->Layout();
	s_background->Fit( m_panel_background );
	m_notebook_filters->AddPage( m_panel_background, wxT("BackGround"), false );
	m_panel_smooth = new wxPanel( m_notebook_filters, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* s_smooth;
	s_smooth = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel_smooth_viewer = new wxPanel( m_panel_smooth, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL );
	m_panel_smooth_viewer->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	s_smooth->Add( m_panel_smooth_viewer, 2, wxEXPAND|wxALL, 5 );
	
	m_panel_smooth_ctrl = new wxPanel( m_panel_smooth, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	m_panel_smooth_ctrl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	wxBoxSizer* s_smooth_ctrl_h;
	s_smooth_ctrl_h = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* s_smooth_ctrl;
	s_smooth_ctrl = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* s_smooth_aligner;
	s_smooth_aligner = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBox_smooth = new wxCheckBox( m_panel_smooth_ctrl, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	s_smooth_aligner->Add( m_checkBox_smooth, 0, wxALL, 5 );
	
	s_smooth_ctrl->Add( s_smooth_aligner, 0, wxEXPAND, 5 );
	
	
	s_smooth_ctrl->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText_smoothctrl = new wxStaticText( m_panel_smooth_ctrl, wxID_ANY, wxT("Smooth Factor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_smoothctrl->Wrap( -1 );
	s_smooth_ctrl->Add( m_staticText_smoothctrl, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider_smooth = new wxSlider( m_panel_smooth_ctrl, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	s_smooth_ctrl->Add( m_slider_smooth, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	s_smooth_ctrl_h->Add( s_smooth_ctrl, 1, wxEXPAND, 5 );
	
	
	s_smooth_ctrl_h->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_panel_smooth_ctrl->SetSizer( s_smooth_ctrl_h );
	m_panel_smooth_ctrl->Layout();
	s_smooth_ctrl_h->Fit( m_panel_smooth_ctrl );
	s_smooth->Add( m_panel_smooth_ctrl, 6, wxEXPAND|wxALL, 5 );
	
	m_panel_smooth->SetSizer( s_smooth );
	m_panel_smooth->Layout();
	s_smooth->Fit( m_panel_smooth );
	m_notebook_filters->AddPage( m_panel_smooth, wxT("Smooth"), false );
	m_panel_highpass = new wxPanel( m_notebook_filters, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* s_highpass;
	s_highpass = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel_highpass_viewer = new wxPanel( m_panel_highpass, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL );
	m_panel_highpass_viewer->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	s_highpass->Add( m_panel_highpass_viewer, 2, wxEXPAND|wxALL, 5 );
	
	m_panel_highpass_ctrl = new wxPanel( m_panel_highpass, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	m_panel_highpass_ctrl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	wxBoxSizer* s_highpass_ctrl_h;
	s_highpass_ctrl_h = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* s_highpass_ctrl;
	s_highpass_ctrl = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* s_highpass_aligner;
	s_highpass_aligner = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBox_highpass = new wxCheckBox( m_panel_highpass_ctrl, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	s_highpass_aligner->Add( m_checkBox_highpass, 0, wxALL, 5 );
	
	s_highpass_ctrl->Add( s_highpass_aligner, 0, wxEXPAND, 5 );
	
	
	s_highpass_ctrl->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText_blur = new wxStaticText( m_panel_highpass_ctrl, wxID_ANY, wxT("Blur"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_blur->Wrap( -1 );
	s_highpass_ctrl->Add( m_staticText_blur, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider_blur = new wxSlider( m_panel_highpass_ctrl, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	s_highpass_ctrl->Add( m_slider_blur, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	m_staticText_nosie = new wxStaticText( m_panel_highpass_ctrl, wxID_ANY, wxT("Noise"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_nosie->Wrap( -1 );
	s_highpass_ctrl->Add( m_staticText_nosie, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider_noise = new wxSlider( m_panel_highpass_ctrl, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	s_highpass_ctrl->Add( m_slider_noise, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	s_highpass_ctrl_h->Add( s_highpass_ctrl, 1, wxEXPAND, 5 );
	
	
	s_highpass_ctrl_h->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_panel_highpass_ctrl->SetSizer( s_highpass_ctrl_h );
	m_panel_highpass_ctrl->Layout();
	s_highpass_ctrl_h->Fit( m_panel_highpass_ctrl );
	s_highpass->Add( m_panel_highpass_ctrl, 6, wxEXPAND|wxALL, 5 );
	
	m_panel_highpass->SetSizer( s_highpass );
	m_panel_highpass->Layout();
	s_highpass->Fit( m_panel_highpass );
	m_notebook_filters->AddPage( m_panel_highpass, wxT("Highpass"), false );
	m_panel_amp = new wxPanel( m_notebook_filters, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* s_amp;
	s_amp = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel_amp_viewer = new wxPanel( m_panel_amp, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL );
	m_panel_amp_viewer->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	s_amp->Add( m_panel_amp_viewer, 2, wxEXPAND|wxALL, 5 );
	
	m_panel_amplify_ctrl = new wxPanel( m_panel_amp, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	m_panel_amplify_ctrl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	wxBoxSizer* s_apmlify_ctrl_h;
	s_apmlify_ctrl_h = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* s_amp_ctrl;
	s_amp_ctrl = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* s_amp_aligner;
	s_amp_aligner = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBox_amp = new wxCheckBox( m_panel_amplify_ctrl, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	s_amp_aligner->Add( m_checkBox_amp, 0, wxALL, 5 );
	
	s_amp_ctrl->Add( s_amp_aligner, 0, wxEXPAND, 5 );
	
	
	s_amp_ctrl->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText_ampctrl = new wxStaticText( m_panel_amplify_ctrl, wxID_ANY, wxT("Amplify Factor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_ampctrl->Wrap( -1 );
	s_amp_ctrl->Add( m_staticText_ampctrl, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider_amp = new wxSlider( m_panel_amplify_ctrl, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	s_amp_ctrl->Add( m_slider_amp, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	s_apmlify_ctrl_h->Add( s_amp_ctrl, 1, wxEXPAND, 5 );
	
	
	s_apmlify_ctrl_h->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_panel_amplify_ctrl->SetSizer( s_apmlify_ctrl_h );
	m_panel_amplify_ctrl->Layout();
	s_apmlify_ctrl_h->Fit( m_panel_amplify_ctrl );
	s_amp->Add( m_panel_amplify_ctrl, 6, wxEXPAND|wxALL, 5 );
	
	m_panel_amp->SetSizer( s_amp );
	m_panel_amp->Layout();
	s_amp->Fit( m_panel_amp );
	m_notebook_filters->AddPage( m_panel_amp, wxT("Amplify"), false );
	
	s_leftMain->Add( m_notebook_filters, 0, wxEXPAND | wxALL, 20 );
	
	panelleft->SetSizer( s_leftMain );
	panelleft->Layout();
	s_leftMain->Fit( panelleft );
	mainSizer->Add( panelleft, 0, wxEXPAND, 5 );
	
	panelright = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	panelright->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );
	panelright->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNSHADOW ) );
	
	wxBoxSizer* s_contols;
	s_contols = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* s_ctrl_camera;
	s_ctrl_camera = new wxStaticBoxSizer( new wxStaticBox( panelright, wxID_ANY, wxT("Camera Properties") ), wxVERTICAL );
	
	m_checkBox_filpV = new wxCheckBox( panelright, wxID_ANY, wxT("Filp Vertical"), wxDefaultPosition, wxDefaultSize, 0 );
	s_ctrl_camera->Add( m_checkBox_filpV, 0, wxALL, 2 );
	
	m_checkBox_filpH = new wxCheckBox( panelright, wxID_ANY, wxT("Filp Horizontal"), wxDefaultPosition, wxDefaultSize, 0 );
	s_ctrl_camera->Add( m_checkBox_filpH, 0, wxALL, 2 );
	
	s_contols->Add( s_ctrl_camera, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* s_ctrl_Gpu;
	s_ctrl_Gpu = new wxStaticBoxSizer( new wxStaticBox( panelright, wxID_ANY, wxT("GPU Properties") ), wxVERTICAL );
	
	m_checkBox_gpu = new wxCheckBox( panelright, wxID_ANY, wxT("GPU Shaders"), wxDefaultPosition, wxDefaultSize, 0 );
	s_ctrl_Gpu->Add( m_checkBox_gpu, 0, wxALL, 2 );
	
	s_contols->Add( s_ctrl_Gpu, 0, wxALL|wxEXPAND, 5 );
	
	wxString m_radioBox_ctrl_commuChoices[] = { wxT("None"), wxT("TUIO UDP"), wxT("Flash XML"), wxT("Binary TCP") };
	int m_radioBox_ctrl_commuNChoices = sizeof( m_radioBox_ctrl_commuChoices ) / sizeof( wxString );
	m_radioBox_ctrl_commu = new wxRadioBox( panelright, wxID_ANY, wxT("Communication"), wxDefaultPosition, wxDefaultSize, m_radioBox_ctrl_commuNChoices, m_radioBox_ctrl_commuChoices, 1, wxRA_SPECIFY_COLS );
	m_radioBox_ctrl_commu->SetSelection( 0 );
	s_contols->Add( m_radioBox_ctrl_commu, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* s_ctrl_settings;
	s_ctrl_settings = new wxStaticBoxSizer( new wxStaticBox( panelright, wxID_ANY, wxT("Settings") ), wxHORIZONTAL );
	
	wxBoxSizer* bSizer_ctrl_setting_aligner;
	bSizer_ctrl_setting_aligner = new wxBoxSizer( wxVERTICAL );
	
	m_button_camera_setting = new wxButton( panelright, wxID_ANY, wxT("Camera Settings"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_ctrl_setting_aligner->Add( m_button_camera_setting, 0, wxALL|wxEXPAND, 2 );
	
	m_button_calibr = new wxButton( panelright, wxID_ANY, wxT("Enter Calibration"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_ctrl_setting_aligner->Add( m_button_calibr, 0, wxALL|wxEXPAND, 2 );
	
	m_button_savesetting = new wxButton( panelright, wxID_ANY, wxT("Save Settings"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_ctrl_setting_aligner->Add( m_button_savesetting, 0, wxALL|wxEXPAND, 2 );
	
	s_ctrl_settings->Add( bSizer_ctrl_setting_aligner, 3, wxEXPAND, 0 );
	
	
	s_ctrl_settings->Add( 0, 0, 1, wxEXPAND, 0 );
	
	s_contols->Add( s_ctrl_settings, 0, wxALL|wxEXPAND, 5 );
	
	
	s_contols->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* s_debuger;
	s_debuger = new wxStaticBoxSizer( new wxStaticBox( panelright, wxID_ANY, wxT("Output") ), wxVERTICAL );
	
	m_staticText_out = new wxStaticText( panelright, wxID_ANY, wxT("CCV is running ...\nPress spacebar for mini mode."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_out->Wrap( -1 );
	s_debuger->Add( m_staticText_out, 0, wxALL, 5 );
	
	s_contols->Add( s_debuger, 3, wxEXPAND|wxALL, 5 );
	
	m_staticText_about = new wxStaticText( panelright, wxID_ANY, wxT("ccv.nuigroup.com"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText_about->Wrap( -1 );
	m_staticText_about->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DDKSHADOW ) );
	m_staticText_about->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	s_contols->Add( m_staticText_about, 0, wxEXPAND, 5 );
	
	panelright->SetSizer( s_contols );
	panelright->Layout();
	s_contols->Fit( panelright );
	mainSizer->Add( panelright, 23, wxEXPAND, 5 );
	
	this->SetSizer( mainSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
}

CCVbaseMainFrame::~CCVbaseMainFrame()
{
}

CCVbaseMiniFrame::CCVbaseMiniFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 190,205 ), wxSize( 190,205 ) );
	
	wxBoxSizer* s_miniFrame;
	s_miniFrame = new wxBoxSizer( wxVERTICAL );
	
	m_panel_mini_viewer = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_mini_viewer->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	s_miniFrame->Add( m_panel_mini_viewer, 27, wxEXPAND, 5 );
	
	m_staticline_mini_row_1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	s_miniFrame->Add( m_staticline_mini_row_1, 0, wxEXPAND, 5 );
	
	wxBoxSizer* s_mini_row_1;
	s_mini_row_1 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText_mini_row_1_left = new wxStaticText( this, wxID_ANY, wxT("Calc Time [ms]:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_mini_row_1_left->Wrap( -1 );
	s_mini_row_1->Add( m_staticText_mini_row_1_left, 0, wxLEFT, 5 );
	
	
	s_mini_row_1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText_mini_row_1_right = new wxStaticText( this, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_mini_row_1_right->Wrap( -1 );
	s_mini_row_1->Add( m_staticText_mini_row_1_right, 0, wxRIGHT, 5 );
	
	s_miniFrame->Add( s_mini_row_1, 5, wxEXPAND, 5 );
	
	m_staticline_mini_row_2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	s_miniFrame->Add( m_staticline_mini_row_2, 0, wxEXPAND, 5 );
	
	wxBoxSizer* s_mini_row_2;
	s_mini_row_2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText_mini_row_2_left = new wxStaticText( this, wxID_ANY, wxT("Video [fps]:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_mini_row_2_left->Wrap( -1 );
	s_mini_row_2->Add( m_staticText_mini_row_2_left, 0, wxLEFT, 5 );
	
	
	s_mini_row_2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText_mini_row_2_right = new wxStaticText( this, wxID_ANY, wxT("32"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_mini_row_2_right->Wrap( -1 );
	s_mini_row_2->Add( m_staticText_mini_row_2_right, 0, wxRIGHT, 5 );
	
	s_miniFrame->Add( s_mini_row_2, 5, wxEXPAND, 5 );
	
	m_staticline_mini_row_3 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	s_miniFrame->Add( m_staticline_mini_row_3, 0, wxEXPAND, 5 );
	
	wxBoxSizer* s_mini_row_3;
	s_mini_row_3 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText_mini_row_3_left = new wxStaticText( this, wxID_ANY, wxT("Blob Count:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_mini_row_3_left->Wrap( -1 );
	s_mini_row_3->Add( m_staticText_mini_row_3_left, 0, wxLEFT, 5 );
	
	
	s_mini_row_3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText_mini_row_3_right = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_mini_row_3_right->Wrap( -1 );
	s_mini_row_3->Add( m_staticText_mini_row_3_right, 0, wxRIGHT, 5 );
	
	s_miniFrame->Add( s_mini_row_3, 5, wxEXPAND, 5 );
	
	m_staticline_mini_row_4 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	s_miniFrame->Add( m_staticline_mini_row_4, 0, wxEXPAND, 5 );
	
	wxBoxSizer* s_mini_row_4;
	s_mini_row_4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText_mini_row_4_left = new wxStaticText( this, wxID_ANY, wxT("Communication:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_mini_row_4_left->Wrap( -1 );
	s_mini_row_4->Add( m_staticText_mini_row_4_left, 0, wxLEFT, 5 );
	
	
	s_mini_row_4->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText_mini_row_4_right = new wxStaticText( this, wxID_ANY, wxT("YES"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_mini_row_4_right->Wrap( -1 );
	s_mini_row_4->Add( m_staticText_mini_row_4_right, 0, wxRIGHT, 5 );
	
	s_miniFrame->Add( s_mini_row_4, 5, wxEXPAND, 5 );
	
	this->SetSizer( s_miniFrame );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( CCVbaseMiniFrame::OnClose ) );
}

CCVbaseMiniFrame::~CCVbaseMiniFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( CCVbaseMiniFrame::OnClose ) );
	
}
