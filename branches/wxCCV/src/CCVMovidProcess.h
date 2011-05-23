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
    
    CvSize *getRoi() { return imgRoi; }
    int getWidthstep() { return widthstep; }
    unsigned char *getOutRaw() { return outRaw; }
    
private:
    moFactory *factory;
    moPipeline *pipeline;
    
    CvSize *imgRoi;
    int widthstep;
    unsigned char *outRaw;
  
    int movid_test();
};

#endif

