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

extern const wxEventType newEVT_MOVIDPROCESS_NEWIMAGE;
#define EVT_MOVIDPROCESS_NEWIMAGE(id, fn)                             \
	DECLARE_EVENT_TABLE_ENTRY( newEVT_MOVIDPROCESS_NEWIMAGE, id, -1,  \
	(wxObjectEventFunction) (wxEventFunction)                         \
	(wxCommandEventFunction) & fn, (wxObject*) NULL )

class CCVMovidProcess : public wxThread
{
public:
    CCVMovidProcess();
    virtual void *Entry();
    
    CvSize *getRoi() { return imgRoi; }
    int getWidthstep() { return widthstep; }
    unsigned char *getOutRaw() { return outRaw; }
	void setEventHandler(wxEvtHandler *handler) { eventHandler = handler; }
    
private:
    moFactory *factory;
    moPipeline *pipeline;
	wxEvtHandler *eventHandler;
    
    CvSize *imgRoi;
    int widthstep;
    unsigned char *outRaw;
  
    int movid_test();
};

#endif

