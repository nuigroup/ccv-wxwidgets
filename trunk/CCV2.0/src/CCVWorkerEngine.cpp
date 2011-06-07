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

    procGraph = new CCVProcGraph();
        
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
        
        if (! procGraph->isStarted())
            continue;
            
        if (!pipelineLocked && procGraph->isStarted())
            procGraph->poll();

        while (procGraph->haveError())
            wxLogMessage(wxT("procGraph error: %s"), procGraph->getLastError().c_str());
            
        ModuleList outputModules;
        
        for (ModuleList::const_iterator iter = outputModules.begin();
	     iter != outputModules.end(); ++iter) {
	        moModule *theModule = iter->first;
	        std::string moduleLable = iter->second;
	        
	        RGBRawImage outRGBRaw;
	        CvSize *outRoi = new CvSize;
	        
            if (!pipelineLocked && procGraph->size()>0 && theModule->getName() == "Stream") {
                otStreamModule *stream = (otStreamModule *)theModule;
                if (stream->copy()) {
                    cvGetRawData(stream->output_buffer, &outRGBRaw, NULL, outRoi);                    
                }
            }
            
            outImages.push_back(new OutRGBImage(outRGBRaw, outRoi, moduleLable));
        }
        
        if (eventHandler != NULL) {
            wxCommandEvent event( newEVT_MOVIDPROCESS_NEWIMAGE, GetId() );
            if(!TestDestroy()) {
                wxPostEvent(eventHandler, event);
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
    if (procGraph->isStarted())
        procGraph->stop();
    
    procGraph->clear();
    graph.Build();
    
    procGraph->start();
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
