/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVWorkerEngine.cpp
// Purpose:     Provide the thread for movid processing
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#include <wx/wx.h>
#include <wx/string.h>
#include <wx/log.h>
#include "CCVWorkerEngine.h"
#include "otMovidStreamModule.h"

int g_config_delay = 50;

const wxEventType newEVT_MOVIDPROCESS_NEWIMAGE = wxNewEventType();

CCVWorkerEngine::CCVWorkerEngine()
{
    eventHandler = NULL;

    pipeline = new moPipeline();
    outRoi = new CvSize;
        
    pipelineLocked = false;
    if (SetFirstPipeline() != CCV_SUCCESS) {
        wxLogMessage(wxT("SetFirstPipeline Error"));
        wxExit();
    }
}

void CCVWorkerEngine::LockPipeline()
{
    pipelineLocked = true;
}

void CCVWorkerEngine::UnlockPipeline()
{
    pipelineLocked = false;
}

void *CCVWorkerEngine::Entry()
{
    while (true) {
        wxThread::Sleep(20);
        
        if (! pipeline->isStarted())
            continue;
            
        if (!pipelineLocked && pipeline->isStarted())
            pipeline->poll();

        while (pipeline->haveError())
            wxLogMessage(wxT("Pipeline error: %s"), pipeline->getLastError().c_str());

        if (!pipelineLocked && pipeline->size()>0 && pipeline->lastModule()->getName() == "Stream") {
            otStreamModule *stream = static_cast<otStreamModule *>(pipeline->lastModule());
            if (stream->copy()) {
                cvGetRawData(stream->output_buffer, &outRGBRaw, NULL, outRoi);
                if (eventHandler != NULL) {
                    wxCommandEvent event( newEVT_MOVIDPROCESS_NEWIMAGE, GetId() );
                    if(!TestDestroy()) {
                        wxPostEvent(eventHandler, event);
                    }
                }
            }
        }
    }

    return NULL;
}

int CCVWorkerEngine::SetPipeline(CCVProcGraph & graph)
{
    if (pipelineLocked) {
        return CCV_ERROR_LOCKED;
    }
    
    LockPipeline();
    Pause();
    if (pipeline->isStarted())
        pipeline->stop();
    
    pipeline->clear();
    graph.BuildPipeline(pipeline);
    
    pipeline->start();
    Resume();
    UnlockPipeline();
    return CCV_SUCCESS;
}

int CCVWorkerEngine::SetFirstPipeline()
{
    CCVProcGraph graph;
    graph.AddModule("input_camera", "Camera");
    graph.AddModule("output_leftviewer", "Stream");
    graph.ConnectModules("input_camera", "output_leftviewer");
    
    return SetPipeline(graph);
}
