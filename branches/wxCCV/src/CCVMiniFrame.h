/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVMiniFrame.h
// Purpose:     Provide the main frame and callback functions
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

 
#include <wx/wx.h>
#include "CCVbaseFrame.h"

//
// CCVbaseMiniFrame is generated automatically by wxFormBuilder, CCVMiniFrame
// extends CCVbaseMiniFrame to implement the event handling functions.
//
class CCVMiniFrame : public CCVbaseMiniFrame
{
public:
    /**
        Default constructor.
    */
    CCVMiniFrame(wxWindow* parent) : CCVbaseMiniFrame(parent) {}
        
    /**
        Close the parent frame when the miniFrame was closed.
    */
    virtual void OnClose( wxCloseEvent& event );
};
