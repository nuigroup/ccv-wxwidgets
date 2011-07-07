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
}

void *CCVWorkerEngine::Entry()
{
    wxLogMessage(wxT("BEGIN CCVWorkerEngine::Entry();"));
    while (true) {
        wxThread::Sleep(20);
        
        if (!procGraph || ! procGraph->isStarted())
            continue;
            
        if (procGraph->isStarted() && !TestDestroy()) {
            // wxLogMessage(wxT("BEFORE procGraph->poll();"));
            procGraph->SetBusy();
            procGraph->poll();
            procGraph->SetNotBusy();
            // wxLogMessage(wxT("AFTER procGraph->poll();"));
        }
        else {
            continue;
        }

        while (procGraph->haveError()) {
            std::string err_msg = procGraph->getLastError();
            wxLogMessage(wxT("ERROR procGraph error msg: %s"), err_msg.c_str());
        }
            
        Strings outputModules = procGraph->GetOutputModuleIDs();
        outImages.clear();
        
        for (Strings::const_iterator iter = outputModules.begin();
         iter != outputModules.end(); ++iter) {
            std::string moduleID = *iter;
            moModule *theModule = procGraph->getModuleById(moduleID);
            
            unsigned char *outRGBRaw;
            CvSize *outRoi = new CvSize;
            
            if (procGraph->size()>0 && theModule->getName() == "Stream") {
                otStreamModule *stream = (otStreamModule *)theModule;
                if (stream->copy()) {
                    if (stream->output_buffer->nChannels == 3)
                        cvCvtColor(stream->output_buffer, stream->output_buffer, CV_BGR2RGB);
                    cvGetRawData(stream->output_buffer, &outRGBRaw, NULL, outRoi);

                    if (stream->output_buffer->nChannels == 1) {
                        unsigned char *RGBfromGray = new unsigned char[outRoi->height * outRoi->width * 3];
                        for (int k=0; k<outRoi->height * outRoi->width; k++) {
                            RGBfromGray[3*k] = outRGBRaw[k];
                            RGBfromGray[3*k+1] = outRGBRaw[k];
                            RGBfromGray[3*k+2] = outRGBRaw[k];
                        }
                        outRGBRaw = RGBfromGray;
                    }
                    
                    outImages[moduleID] = new OutRGBImage(outRGBRaw, outRoi);
                }
            }
        }
        
        if (eventHandler != NULL && ! outImages.empty()) {
            wxCommandEvent event( newEVT_MOVIDPROCESS_NEWIMAGE, GetId() );
            wxThread::Sleep(1);
            if(!TestDestroy()) {
                // wxLogMessage(wxT("BEFORE wxPostEvent(eventHandler, event);"));
                wxPostEvent(eventHandler, event);
                // wxLogMessage(wxT("AFTER wxPostEvent(eventHandler, event);"));
            }
        }
    }

    return NULL;
}

int CCVWorkerEngine::SafeSetProperty(std::string moduleName, std::string propertyName, int value)
{
    moModule *mo = procGraph->getModuleById(moduleName);
    if (mo == NULL) {
        wxLogMessage(wxT("ERROR no such module: %s"), moduleName.c_str());
        return CCV_ERROR_ITEM_NOT_EXISTS;
    } 
    if (procGraph->isBusy()) {
        wxLogMessage(wxT("MESSAGE procGraph->isBusy(). Return."));
        return CCV_ERROR_BUSY;
    }
    this->Pause();
    procGraph->stop();  
    mo->property(propertyName).set(value);
    procGraph->start();
    this->Resume();
    return CCV_SUCCESS;
}
