/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVWorkerEngine.h
// Purpose:     Provide the thread for movid processing
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#ifndef _CCV_WORKER_ENGINE_H
#define _CCV_WORKER_ENGINE_H

#include <iostream>
#include <string>
#include <wx/thread.h>
#include <opencv/highgui.h>
#include <moDaemon.h>
#include <moPipeline.h>
#include <moFactory.h>
#include "CCVCommon.h"
#include "CCVProcGraph.h"

extern const wxEventType newEVT_MOVIDPROCESS_NEWIMAGE;
#define EVT_MOVIDPROCESS_NEWIMAGE(id, fn)                             \
    DECLARE_EVENT_TABLE_ENTRY( newEVT_MOVIDPROCESS_NEWIMAGE, id, -1,  \
    (wxObjectEventFunction) (wxEventFunction)                         \
    (wxCommandEventFunction) & fn, (wxObject*) NULL )

struct OutRGBImage
{    
    unsigned char *data;
    CvSize *outRoi;
        
    OutRGBImage()
    {
        data = NULL;
        outRoi = NULL;
    }

    OutRGBImage(unsigned char * _data, CvSize *_outRoi)
    {
        data = _data;
        outRoi = _outRoi;
    }
};

typedef std::map<std::string, OutRGBImage *> OutImagesMap;

class CCVWorkerEngine : public wxThread
{
public:
    CCVWorkerEngine();
    virtual void *Entry();

    OutImagesMap getOutImages() { return outImages; }
    void setEventHandler(wxEvtHandler *handler) { eventHandler = handler; }
    
    CCVProcGraph *procGraph;

    /**
        Set a modules property safely.
    */
    int SafeSetProperty(std::string moduleName, std::string propertyName, int value);

private:
    wxEvtHandler *eventHandler;
    OutImagesMap outImages;
};

#endif
