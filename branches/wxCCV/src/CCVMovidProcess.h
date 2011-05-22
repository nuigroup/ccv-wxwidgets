/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVMovidProcess.h
// Purpose:     Provide the thread for movid processing
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#ifndef _CCV_MOVID_PROCESS_H
#define _CCV_MOVID_PROCESS_H

#include <wx/thread.h>
#include "moMovid.h"

class CCVMovidProcess : public wxThread
{
public:
  CCVMovidProcess();
  virtual void *Entry();
	
private:
  moFactory *factory;
  moPipeline *pipeline;
  
  int movid_test1();
  int movid_test2();
};

#endif

