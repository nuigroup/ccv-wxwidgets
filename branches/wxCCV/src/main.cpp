/*
 *  main.cpp
 *  NUI Group Community Core Vision
 * 
 *  Created by NUI Group Dev Team.
 *  Copyright 2011 NUI Group/Inc. All rights reserved.
 *
 */
 
#include <wx/wx.h>
#include "CCVFrame.h"

class wxCCV : public wxApp
{
    virtual bool OnInit();
};

IMPLEMENT_APP(wxCCV)

bool wxCCV::OnInit()
{
    CCVFrame *mainframe = new CCVFrame(NULL);
    mainframe->Show(true);
    
    return true;
}
