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
	this->SetSizeHints( wxSize( 950,700 ), wxDefaultSize );
	
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
	m_staticText_inputViewer->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_CAPTIONTEXT ) );
	
	s_title->Add( m_staticText_inputViewer, 1, wxEXPAND|wxALL, 10 );
	
	m_staticText_outputViewer = new wxStaticText( panelleft, wxID_ANY, wxT("Tracked"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText_outputViewer->Wrap( -1 );
	m_staticText_outputViewer->SetFont( wxFont( 14, 74, 90, 90, false, wxT("Verdana") ) );
	m_staticText_outputViewer->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_CAPTIONTEXT ) );
	
	s_title->Add( m_staticText_outputViewer, 1, wxEXPAND|wxALL, 10 );
	
	s_leftMain->Add( s_title, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer_input;
	bSizer_input = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel_inputViewer = new wxPanel( panelleft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL );
	m_panel_inputViewer->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer_input->Add( m_panel_inputViewer, 1, wxEXPAND|wxRIGHT|wxLEFT, 20 );
	
	m_panel_outputViewer = new wxPanel( panelleft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL );
	m_panel_outputViewer->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer_input->Add( m_panel_outputViewer, 1, wxEXPAND|wxRIGHT|wxLEFT, 20 );
	
	s_leftMain->Add( bSizer_input, 80, wxEXPAND, 5 );
	
	wxBoxSizer* s_inout_ctrl;
	s_inout_ctrl = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel_inputContrl = new wxPanel( panelleft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	m_panel_inputContrl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText_title_inputctrl = new wxStaticText( m_panel_inputContrl, wxID_ANY, wxT("Source Image"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_title_inputctrl->Wrap( -1 );
	bSizer10->Add( m_staticText_title_inputctrl, 0, wxALL, 5 );
	
	
	bSizer10->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_checkBox_showoutline = new wxCheckBox( m_panel_inputContrl, wxID_ANY, wxT("Show Outlines"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_checkBox_showoutline, 0, wxALL, 5 );
	
	m_checkBox_showid = new wxCheckBox( m_panel_inputContrl, wxID_ANY, wxT("Show IDs"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_checkBox_showid, 0, wxALL, 5 );
	
	bSizer9->Add( bSizer10, 0, wxEXPAND, 5 );
	
	
	bSizer9->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_radioBox_selectInputChoices[] = { wxT("Use Camera"), wxT("Use Video") };
	int m_radioBox_selectInputNChoices = sizeof( m_radioBox_selectInputChoices ) / sizeof( wxString );
	m_radioBox_selectInput = new wxRadioBox( m_panel_inputContrl, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_radioBox_selectInputNChoices, m_radioBox_selectInputChoices, 1, wxRA_SPECIFY_COLS );
	m_radioBox_selectInput->SetSelection( 0 );
	bSizer11->Add( m_radioBox_selectInput, 0, wxALL, 5 );
	
	
	bSizer11->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	m_button_prevCamera = new wxButton( m_panel_inputContrl, wxID_ANY, wxT("Prev Camera"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_prevCamera->Enable( false );
	
	bSizer12->Add( m_button_prevCamera, 0, wxALIGN_CENTER|wxEXPAND|wxALL, 5 );
	
	m_button_nextCamera = new wxButton( m_panel_inputContrl, wxID_ANY, wxT("Next Camera"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_nextCamera->Enable( false );
	
	bSizer12->Add( m_button_nextCamera, 0, wxALIGN_CENTER|wxEXPAND|wxALL, 5 );
	
	bSizer11->Add( bSizer12, 2, wxEXPAND|wxRIGHT, 10 );
	
	bSizer9->Add( bSizer11, 0, wxEXPAND, 5 );
	
	m_panel_inputContrl->SetSizer( bSizer9 );
	m_panel_inputContrl->Layout();
	bSizer9->Fit( m_panel_inputContrl );
	s_inout_ctrl->Add( m_panel_inputContrl, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 20 );
	
	m_panel_outputControl = new wxPanel( panelleft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	m_panel_outputControl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText_title_outputctrl = new wxStaticText( m_panel_outputControl, wxID_ANY, wxT("Tracked Image"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_title_outputctrl->Wrap( -1 );
	bSizer14->Add( m_staticText_title_outputctrl, 0, wxALL, 5 );
	
	
	bSizer14->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_checkBox13 = new wxCheckBox( m_panel_outputControl, wxID_ANY, wxT("Inverse"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_checkBox13, 0, wxALL, 5 );
	
	bSizer13->Add( bSizer14, 0, wxEXPAND, 5 );
	
	
	bSizer13->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 2, 2, 0, 0 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText8 = new wxStaticText( m_panel_outputControl, wxID_ANY, wxT("Image Threshold"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer15->Add( m_staticText8, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider9 = new wxSlider( m_panel_outputControl, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer15->Add( m_slider9, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	gSizer1->Add( bSizer15, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText9 = new wxStaticText( m_panel_outputControl, wxID_ANY, wxT("Movement Filter"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer16->Add( m_staticText9, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider10 = new wxSlider( m_panel_outputControl, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer16->Add( m_slider10, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	gSizer1->Add( bSizer16, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText10 = new wxStaticText( m_panel_outputControl, wxID_ANY, wxT("Min Blob Size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer17->Add( m_staticText10, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider11 = new wxSlider( m_panel_outputControl, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer17->Add( m_slider11, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	gSizer1->Add( bSizer17, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText11 = new wxStaticText( m_panel_outputControl, wxID_ANY, wxT("Max Blob Size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer18->Add( m_staticText11, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider12 = new wxSlider( m_panel_outputControl, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer18->Add( m_slider12, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	gSizer1->Add( bSizer18, 1, wxEXPAND, 5 );
	
	bSizer13->Add( gSizer1, 0, wxEXPAND, 5 );
	
	m_panel_outputControl->SetSizer( bSizer13 );
	m_panel_outputControl->Layout();
	bSizer13->Fit( m_panel_outputControl );
	s_inout_ctrl->Add( m_panel_outputControl, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 20 );
	
	s_leftMain->Add( s_inout_ctrl, 0, wxEXPAND, 5 );
	
	
	s_leftMain->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_filters;
	s_filters = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel_background = new wxPanel( panelleft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL );
	m_panel_background->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	s_filters->Add( m_panel_background, 1, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 15 );
	
	m_panel_smooth = new wxPanel( panelleft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL );
	m_panel_smooth->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	s_filters->Add( m_panel_smooth, 1, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 15 );
	
	m_panel_highpass = new wxPanel( panelleft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL );
	m_panel_highpass->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	s_filters->Add( m_panel_highpass, 1, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 15 );
	
	m_panel_amplify = new wxPanel( panelleft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL );
	m_panel_amplify->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	s_filters->Add( m_panel_amplify, 1, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 15 );
	
	s_leftMain->Add( s_filters, 40, wxEXPAND|wxRIGHT|wxLEFT, 15 );
	
	wxBoxSizer* s_filter_ctrl;
	s_filter_ctrl = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* s_background;
	s_background = new wxBoxSizer( wxVERTICAL );
	
	m_panel_background_ctrl = new wxPanel( panelleft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	m_panel_background_ctrl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText101 = new wxStaticText( m_panel_background_ctrl, wxID_ANY, wxT("BackGround"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText101->Wrap( -1 );
	bSizer33->Add( m_staticText101, 0, wxALL, 5 );
	
	
	bSizer33->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizer29->Add( bSizer33, 0, wxEXPAND, 5 );
	
	m_checkBox8 = new wxCheckBox( m_panel_background_ctrl, wxID_ANY, wxT("Remove BG"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer29->Add( m_checkBox8, 0, wxRIGHT|wxLEFT, 5 );
	
	m_checkBox9 = new wxCheckBox( m_panel_background_ctrl, wxID_ANY, wxT("Dynamic Subtract"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer29->Add( m_checkBox9, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText12 = new wxStaticText( m_panel_background_ctrl, wxID_ANY, wxT("Learn Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer29->Add( m_staticText12, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider6 = new wxSlider( m_panel_background_ctrl, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer29->Add( m_slider6, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	m_panel_background_ctrl->SetSizer( bSizer29 );
	m_panel_background_ctrl->Layout();
	bSizer29->Fit( m_panel_background_ctrl );
	s_background->Add( m_panel_background_ctrl, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 15 );
	
	
	s_background->Add( 0, 0, 1, wxEXPAND, 5 );
	
	s_filter_ctrl->Add( s_background, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_smooth;
	s_smooth = new wxBoxSizer( wxVERTICAL );
	
	m_panel_smooth_ctrl = new wxPanel( panelleft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	m_panel_smooth_ctrl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText13 = new wxStaticText( m_panel_smooth_ctrl, wxID_ANY, wxT("Smooth"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer34->Add( m_staticText13, 0, wxALL, 5 );
	
	
	bSizer34->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_checkBox10 = new wxCheckBox( m_panel_smooth_ctrl, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( m_checkBox10, 0, wxALL, 5 );
	
	bSizer30->Add( bSizer34, 0, wxEXPAND, 5 );
	
	m_staticText14 = new wxStaticText( m_panel_smooth_ctrl, wxID_ANY, wxT("Smooth Factor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer30->Add( m_staticText14, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider7 = new wxSlider( m_panel_smooth_ctrl, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer30->Add( m_slider7, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	m_panel_smooth_ctrl->SetSizer( bSizer30 );
	m_panel_smooth_ctrl->Layout();
	bSizer30->Fit( m_panel_smooth_ctrl );
	s_smooth->Add( m_panel_smooth_ctrl, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 15 );
	
	
	s_smooth->Add( 0, 0, 1, wxEXPAND, 5 );
	
	s_filter_ctrl->Add( s_smooth, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_highpass;
	s_highpass = new wxBoxSizer( wxVERTICAL );
	
	m_panel_highpass_ctrl = new wxPanel( panelleft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	m_panel_highpass_ctrl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText15 = new wxStaticText( m_panel_highpass_ctrl, wxID_ANY, wxT("HighPass"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer39->Add( m_staticText15, 0, wxALL, 5 );
	
	
	bSizer39->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_checkBox111 = new wxCheckBox( m_panel_highpass_ctrl, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer39->Add( m_checkBox111, 0, wxALL, 5 );
	
	bSizer31->Add( bSizer39, 0, wxEXPAND, 5 );
	
	m_staticText17 = new wxStaticText( m_panel_highpass_ctrl, wxID_ANY, wxT("Blur"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer31->Add( m_staticText17, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider8 = new wxSlider( m_panel_highpass_ctrl, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer31->Add( m_slider8, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	m_staticText18 = new wxStaticText( m_panel_highpass_ctrl, wxID_ANY, wxT("Noise"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer31->Add( m_staticText18, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider91 = new wxSlider( m_panel_highpass_ctrl, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer31->Add( m_slider91, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	m_panel_highpass_ctrl->SetSizer( bSizer31 );
	m_panel_highpass_ctrl->Layout();
	bSizer31->Fit( m_panel_highpass_ctrl );
	s_highpass->Add( m_panel_highpass_ctrl, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 15 );
	
	s_filter_ctrl->Add( s_highpass, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_amplify;
	s_amplify = new wxBoxSizer( wxVERTICAL );
	
	m_panel_amplify_ctrl = new wxPanel( panelleft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	m_panel_amplify_ctrl->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText16 = new wxStaticText( m_panel_amplify_ctrl, wxID_ANY, wxT("Amplify"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer40->Add( m_staticText16, 0, wxALL, 5 );
	
	
	bSizer40->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_checkBox121 = new wxCheckBox( m_panel_amplify_ctrl, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer40->Add( m_checkBox121, 0, wxALL, 5 );
	
	bSizer32->Add( bSizer40, 0, wxEXPAND, 5 );
	
	m_staticText19 = new wxStaticText( m_panel_amplify_ctrl, wxID_ANY, wxT("Amplify Factor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer32->Add( m_staticText19, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider101 = new wxSlider( m_panel_amplify_ctrl, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer32->Add( m_slider101, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	m_panel_amplify_ctrl->SetSizer( bSizer32 );
	m_panel_amplify_ctrl->Layout();
	bSizer32->Fit( m_panel_amplify_ctrl );
	s_amplify->Add( m_panel_amplify_ctrl, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 15 );
	
	s_filter_ctrl->Add( s_amplify, 1, wxEXPAND, 5 );
	
	s_leftMain->Add( s_filter_ctrl, 0, wxEXPAND|wxRIGHT|wxLEFT, 15 );
	
	panelleft->SetSizer( s_leftMain );
	panelleft->Layout();
	s_leftMain->Fit( panelleft );
	mainSizer->Add( panelleft, 72, wxEXPAND, 5 );
	
	panelright = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	panelright->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	panelright->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DDKSHADOW ) );
	
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

CCVbaseFrame::~CCVbaseFrame()
{
}
