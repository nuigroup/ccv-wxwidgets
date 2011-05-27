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
#include "MovidGraph.h"
#include "CCVCommon.h"

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

    CvSize *getRoi() { return outRoi; }
    unsigned char *getOutRGBRaw() { return outRGBRaw; }
    void setEventHandler(wxEvtHandler *handler) { eventHandler = handler; }
    
    int SetPipeline(MovidGraph & graph);

private:
    moFactory *factory;
    moPipeline *pipeline;
    wxEvtHandler *eventHandler;
    
    bool pipelineLocked;
    void LockPipeline();
    void UnlockPipeline();

    CvSize *outRoi;
    unsigned char *outRGBRaw;

    int SetFirstPipeline();
};

#endif
