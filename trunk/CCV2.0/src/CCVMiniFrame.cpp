/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVMiniFrame.cpp
// Purpose:     Provide the main frame and callback functions
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#include "CCVMiniFrame.h"

void CCVMiniFrame::OnClose( wxCloseEvent& event )
{
    wxWindow *parent = GetParent();
    if (parent!=NULL) {
        parent->Close();
    }
}
