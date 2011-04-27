///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "CCVbaseFrame.h"

///////////////////////////////////////////////////////////////////////////

CCVbaseFrame::CCVbaseFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer_main;
	bSizer_main = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel_left = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_left->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	wxBoxSizer* bSizer_workspace;
	bSizer_workspace = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer_inout;
	bSizer_inout = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer_input;
	bSizer_input = new wxBoxSizer( wxVERTICAL );
	
	m_staticText_inputViewer = new wxStaticText( m_panel_left, wxID_ANY, wxT("Input"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText_inputViewer->Wrap( -1 );
	m_staticText_inputViewer->SetFont( wxFont( 14, 74, 90, 90, false, wxT("Verdana") ) );
	m_staticText_inputViewer->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_CAPTIONTEXT ) );
	
	bSizer_input->Add( m_staticText_inputViewer, 0, wxEXPAND|wxALL, 10 );
	
	m_panel_inputViewer = new wxPanel( m_panel_left, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_inputViewer->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer_input->Add( m_panel_inputViewer, 3, wxEXPAND|wxRIGHT|wxLEFT, 20 );
	
	m_panel_inputContrl = new wxPanel( m_panel_left, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_inputContrl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	bSizer_input->Add( m_panel_inputContrl, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 20 );
	
	bSizer_inout->Add( bSizer_input, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer_output;
	bSizer_output = new wxBoxSizer( wxVERTICAL );
	
	m_staticText_outputViewer = new wxStaticText( m_panel_left, wxID_ANY, wxT("Tracked"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText_outputViewer->Wrap( -1 );
	m_staticText_outputViewer->SetFont( wxFont( 14, 74, 90, 90, false, wxT("Verdana") ) );
	m_staticText_outputViewer->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_CAPTIONTEXT ) );
	
	bSizer_output->Add( m_staticText_outputViewer, 0, wxEXPAND|wxALL, 10 );
	
	m_panel_outputViewer = new wxPanel( m_panel_left, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_outputViewer->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer_output->Add( m_panel_outputViewer, 3, wxEXPAND|wxRIGHT|wxLEFT, 20 );
	
	m_panel_outputControl = new wxPanel( m_panel_left, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_outputControl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	bSizer_output->Add( m_panel_outputControl, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 20 );
	
	bSizer_inout->Add( bSizer_output, 1, wxEXPAND, 5 );
	
	bSizer_workspace->Add( bSizer_inout, 2, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer_filters;
	bSizer_filters = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer_workspace->Add( bSizer_filters, 1, wxEXPAND, 5 );
	
	m_panel_left->SetSizer( bSizer_workspace );
	m_panel_left->Layout();
	bSizer_workspace->Fit( m_panel_left );
	bSizer_main->Add( m_panel_left, 72, wxEXPAND, 5 );
	
	m_panel_right = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_right->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_panel_right->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DDKSHADOW ) );
	
	wxBoxSizer* bSizer_contols;
	bSizer_contols = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer_ctrl_camera;
	sbSizer_ctrl_camera = new wxStaticBoxSizer( new wxStaticBox( m_panel_right, wxID_ANY, wxT("Camera Properties") ), wxVERTICAL );
	
	m_checkBox_filpV = new wxCheckBox( m_panel_right, wxID_ANY, wxT("Filp Vertical"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer_ctrl_camera->Add( m_checkBox_filpV, 0, wxALL, 2 );
	
	m_checkBox_filpH = new wxCheckBox( m_panel_right, wxID_ANY, wxT("Filp Horizontal"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer_ctrl_camera->Add( m_checkBox_filpH, 0, wxALL, 2 );
	
	bSizer_contols->Add( sbSizer_ctrl_camera, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer_ctrl_Gpu;
	sbSizer_ctrl_Gpu = new wxStaticBoxSizer( new wxStaticBox( m_panel_right, wxID_ANY, wxT("GPU Properties") ), wxVERTICAL );
	
	m_checkBox_gpu = new wxCheckBox( m_panel_right, wxID_ANY, wxT("GPU Shaders"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer_ctrl_Gpu->Add( m_checkBox_gpu, 0, wxALL, 2 );
	
	bSizer_contols->Add( sbSizer_ctrl_Gpu, 0, wxALL|wxEXPAND, 5 );
	
	wxString m_radioBox_ctrl_commuChoices[] = { wxT("None"), wxT("TUIO UDP"), wxT("Flash XML"), wxT("Binary TCP") };
	int m_radioBox_ctrl_commuNChoices = sizeof( m_radioBox_ctrl_commuChoices ) / sizeof( wxString );
	m_radioBox_ctrl_commu = new wxRadioBox( m_panel_right, wxID_ANY, wxT("Communication"), wxDefaultPosition, wxDefaultSize, m_radioBox_ctrl_commuNChoices, m_radioBox_ctrl_commuChoices, 1, wxRA_SPECIFY_COLS );
	m_radioBox_ctrl_commu->SetSelection( 0 );
	bSizer_contols->Add( m_radioBox_ctrl_commu, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer_ctrl_settings;
	sbSizer_ctrl_settings = new wxStaticBoxSizer( new wxStaticBox( m_panel_right, wxID_ANY, wxT("Settings") ), wxHORIZONTAL );
	
	wxBoxSizer* bSizer_ctrl_setting_aligner;
	bSizer_ctrl_setting_aligner = new wxBoxSizer( wxVERTICAL );
	
	m_button_camera_setting = new wxButton( m_panel_right, wxID_ANY, wxT("Camera Settings"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_ctrl_setting_aligner->Add( m_button_camera_setting, 0, wxALL|wxEXPAND, 2 );
	
	m_button_calibr = new wxButton( m_panel_right, wxID_ANY, wxT("Enter Calibration"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_ctrl_setting_aligner->Add( m_button_calibr, 0, wxALL|wxEXPAND, 2 );
	
	m_button_savesetting = new wxButton( m_panel_right, wxID_ANY, wxT("Save Settings"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_ctrl_setting_aligner->Add( m_button_savesetting, 0, wxALL|wxEXPAND, 2 );
	
	sbSizer_ctrl_settings->Add( bSizer_ctrl_setting_aligner, 3, wxEXPAND, 0 );
	
	
	sbSizer_ctrl_settings->Add( 0, 0, 1, wxEXPAND, 0 );
	
	bSizer_contols->Add( sbSizer_ctrl_settings, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer_contols->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText_about = new wxStaticText( m_panel_right, wxID_ANY, wxT("ccv.nuigroup.com"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText_about->Wrap( -1 );
	m_staticText_about->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DDKSHADOW ) );
	m_staticText_about->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	bSizer_contols->Add( m_staticText_about, 0, wxEXPAND, 5 );
	
	m_panel_right->SetSizer( bSizer_contols );
	m_panel_right->Layout();
	bSizer_contols->Fit( m_panel_right );
	bSizer_main->Add( m_panel_right, 23, wxEXPAND, 5 );
	
	this->SetSizer( bSizer_main );
	this->Layout();
	
	this->Centre( wxBOTH );
}

CCVbaseFrame::~CCVbaseFrame()
{
}
