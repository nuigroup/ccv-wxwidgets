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
    procGraph = new CCVProcGraph;
}

void *CCVWorkerEngine::Entry()
{
    wxLogMessage(wxT("BEGIN CCVWorkerEngine::Entry();"));
    while (true) {
        if (!procGraph || ! procGraph->isStarted())
            continue;
            
        if (procGraph->isStarted() && !TestDestroy()) {
            procGraph->poll();
        }
        else {
            continue;
        }

        while (procGraph->haveError()) {
            std::string err_msg = procGraph->getLastError();
            wxLogMessage(wxT("ERROR procGraph error msg: %s"), err_msg.c_str());
        }

        CCVWorkerEngineResItem *curResItem = new CCVWorkerEngineResItem;
        Strings outputModules = procGraph->GetOutputModuleIDs();
        for (Strings::const_iterator iter = outputModules.begin();iter != outputModules.end(); ++iter) {
            std::string moduleID = *iter;
            moModule *theModule = procGraph->getModuleById(moduleID);
            if (theModule == NULL) {
                continue;
            }

            if (procGraph->size() <= 0) {
                continue;
            }

            if (theModule->getName() != "Stream") {
                continue;
            }
            otStreamModule *stream = (otStreamModule *)theModule;

            if (! stream->copy()) {
                continue;
            }
            unsigned char *outRGBRaw;
            CvSize *outRoi = new CvSize;
            if (stream->output_buffer->nChannels == 1) {
                cvGetRawData(stream->output_buffer, &outRGBRaw, NULL, outRoi);
                unsigned char *RGBfromGray = new unsigned char[outRoi->height * outRoi->width * 3];
                for (int k=0; k<outRoi->height * outRoi->width; k++) {
                    RGBfromGray[3*k] = outRGBRaw[k];
                    RGBfromGray[3*k+1] = outRGBRaw[k];
                    RGBfromGray[3*k+2] = outRGBRaw[k];
                }
                curResItem->outImages[moduleID] = new OutRGBImage(RGBfromGray, outRoi);
                delete[] RGBfromGray;
            }
            else if (stream->output_buffer->nChannels == 3){
                cvCvtColor(stream->output_buffer, stream->output_buffer, CV_BGR2RGB);
                cvGetRawData(stream->output_buffer, &outRGBRaw, NULL, outRoi);
                curResItem->outImages[moduleID] = new OutRGBImage(outRGBRaw, outRoi);
            }
            else {
                wxLogMessage(wxT("ERROR Unknown stream->output_buffer->nChannels."));
                return NULL;
            }
            delete outRoi;
        }

        if (!TestDestroy() && eventHandler != NULL && curResItem && ! curResItem->outImages.empty()) {
            resourceQueue.push(curResItem);
            wxCommandEvent event( newEVT_MOVIDPROCESS_NEWIMAGE, GetId() );
            wxPostEvent(eventHandler, event);
            //wxLogMessage(wxT("AFTER wxPostEvent"));
        }
        else {
            //wxLogMessage(wxT("MSG No wxPostEvent"));
            delete curResItem;
        }
    }

    return NULL;
}
