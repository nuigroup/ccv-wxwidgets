/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVMovidProcess.cpp
// Purpose:     Provide the thread for movid processing
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#include <wx/wx.h>
#include <wx/string.h>
#include <wx/log.h>
#include "CCVMovidProcess.h"
#include "otMovidStreamModule.h"

int g_config_delay = 50;

const wxEventType newEVT_MOVIDPROCESS_NEWIMAGE = wxNewEventType();

CCVMovidProcess::CCVMovidProcess()
{
    eventHandler = NULL;

    // initialize/discover all modules
    moFactory::init();
    factory = moFactory::getInstance();
    factory->registerModule("Stream", otStreamModule::createModule);

    pipeline = new moPipeline();
    outRoi = new CvSize;
        
    pipelineLocked = false;
    if (SetFirstPipeline() != CCV_SUCCESS) {
        wxLogMessage(wxT("SetFirstPipeline Error"));
        wxExit();
    }
}

void CCVMovidProcess::LockPipeline()
{
    pipelineLocked = true;
}

void CCVMovidProcess::UnlockPipeline()
{
    pipelineLocked = false;
}

void *CCVMovidProcess::Entry()
{
    while (true) {
        if (! pipeline->isStarted())
            continue;
            
        if (!pipelineLocked && pipeline->isStarted())
            pipeline->poll();

        while (pipeline->haveError())
            wxLogMessage(wxT("Pipeline error: %s"), pipeline->getLastError().c_str());

        if (!pipelineLocked && pipeline->lastModule()->getName() == "Stream") {
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
        
        wxThread::Sleep(20);
    }

    return NULL;
}

int CCVMovidProcess::SetPipeline(MovidGraph & graph)
{
    if (pipelineLocked) {
        return CCV_ERROR_RESOURCE_LOCKED;
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

int CCVMovidProcess::SetFirstPipeline()
{
    // TODO: Call SetPipeline to replace the codes below
    
    if (pipelineLocked) {
        return CCV_ERROR_RESOURCE_LOCKED;
    }
    
    LockPipeline();
    Pause();
    if (pipeline->isStarted())
        pipeline->stop();
    
    pipeline->clear();
    
    moModule *camera = factory->create("Camera");
    pipeline->addElement(camera);
    moModule *stream = factory->create("Stream");
    pipeline->addElement(stream);
    stream->setInput(camera->getOutput(0), 0);

    pipeline->start();
    Resume();
    UnlockPipeline();
    return CCV_SUCCESS;
}
