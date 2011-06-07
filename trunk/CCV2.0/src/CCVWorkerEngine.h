/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVWorkerEngine.h
// Purpose:     Provide the thread for movid processing
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#ifndef _CCV_WORKER_ENGINE_H
#define _CCV_WORKER_ENGINE_H

#include <vector>
#include <string>
#include <wx/thread.h>
#include "moMovid.h"
#include "CCVCommon.h"
#include "CCVProcGraph.h"

extern const wxEventType newEVT_MOVIDPROCESS_NEWIMAGE;
#define EVT_MOVIDPROCESS_NEWIMAGE(id, fn)                             \
    DECLARE_EVENT_TABLE_ENTRY( newEVT_MOVIDPROCESS_NEWIMAGE, id, -1,  \
    (wxObjectEventFunction) (wxEventFunction)                         \
    (wxCommandEventFunction) & fn, (wxObject*) NULL )

typedef unsigned char * RGBRawImage;

struct OutRGBImage
{    
    RGBRawImage data;
    CvSize *outRoi;
    std::string lable;
        
    OutRGBImage()
    {
        data = NULL;
        outRoi = NULL;
    }
    
    OutRGBImage(RGBRawImage _data, CvSize *_outRoi, std::string _lable)
    {
        data = _data;
        outRoi = _outRoi;
        lable = _lable;
    }
};

typedef std::vector<OutRGBImage *> OutImagesVector;

class CCVWorkerEngine : public wxThread
{
public:
    CCVWorkerEngine();
    virtual void *Entry();

    OutImagesVector getOutImages() { return outImages; }
    void setEventHandler(wxEvtHandler *handler) { eventHandler = handler; }
    
    CCVProcGraph *procGraph;

private:
    wxEvtHandler *eventHandler;

    OutImagesVector outImages;
};

#endif
