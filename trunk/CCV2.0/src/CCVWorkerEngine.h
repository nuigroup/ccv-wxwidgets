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
#include <cstring>
#include <queue>
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
        SetImageData(_data, _outRoi);
    }

    ~OutRGBImage()
    {
        if (data != NULL) {
            delete[] data;
            data = NULL;
        }
        if (outRoi != NULL) {
            delete outRoi;
            outRoi = NULL;
        }
    }

    void SetImageData(unsigned char * _data, CvSize *_outRoi)
    {
        int size = _outRoi->width * _outRoi->height * 3;
        data = new unsigned char[size];
        outRoi = new CvSize;
        memcpy(data, _data, size*sizeof(unsigned char));
        memcpy(outRoi, _outRoi, sizeof(CvSize));
    }
};

typedef std::map<std::string, OutRGBImage *> OutImagesMap;

struct CCVWorkerEngineResItem {
    OutImagesMap outImages;

    CCVWorkerEngineResItem() {}

    ~CCVWorkerEngineResItem()
    {
        for (OutImagesMap::const_iterator iter = outImages.begin();iter != outImages.end(); ++iter) {
            delete iter->second;
        }
        outImages.clear();
    }
};
typedef std::queue<CCVWorkerEngineResItem *> CCVWorkerEngineResQueue;

class CCVWorkerEngine : public wxThread
{
public:
    CCVWorkerEngine();
    virtual void *Entry();

    CCVWorkerEngineResQueue *getResQueue() { return &resourceQueue; }
    void setEventHandler(wxEvtHandler *handler) { eventHandler = handler; }
    
    CCVProcGraph *procGraph;

private:
    wxEvtHandler *eventHandler;
    CCVWorkerEngineResQueue resourceQueue;
};

#endif
