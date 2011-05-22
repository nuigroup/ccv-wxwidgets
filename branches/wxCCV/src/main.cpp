/////////////////////////////////////////////////////////////////////////////
// Name:        src/main.cpp
// Purpose:     Provide the entrance of the application
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////
 
#include <wx/wx.h>
#include <wx/thread.h>
#include "CCVFrame.h"
#include "CCVMovidProcess.h"

//
// wxCCV is the class that provides the main application.
//
class wxCCV : public wxApp
{
  virtual bool OnInit();
};

IMPLEMENT_APP(wxCCV)

bool wxCCV::OnInit()
{
  CCVFrame *mainframe = new CCVFrame();
  mainframe->Show(true);
    
  CCVMovidProcess *movidthread = new CCVMovidProcess;
  movidthread->Create();
  movidthread->Run();

  return true;
}
