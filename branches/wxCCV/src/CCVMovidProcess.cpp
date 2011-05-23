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

    pipeline = new moPipeline();
    imgRoi = new CvSize;
}

void *CCVMovidProcess::Entry()
{
    movid_test();
  
    pipeline->start();
    while (true) {
        if(TestDestroy()==1) 
            break;
    
		// XXX Not needed if you're not using image display of opencv
        //cvWaitKey(50);

        if ( pipeline->isStarted() )
            pipeline->poll();

        while ( pipeline->haveError() )
            wxLogMessage(wxT("Pipeline error: %s"), pipeline->getLastError().c_str());

        if (pipeline->lastModule()->getName() == "Stream") {
			otStreamModule *stream = static_cast<otStreamModule *>(pipeline->lastModule());
            if (stream->copy()) {
                cvGetRawData(stream->output_buffer, &outRaw, &widthstep, imgRoi);
				if (eventHandler != NULL) {
					wxCommandEvent event( newEVT_MOVIDPROCESS_NEWIMAGE, GetId() );
					wxPostEvent(eventHandler, event);
				}
            }
        }
    }
    pipeline->stop();

    return NULL;
}

int CCVMovidProcess::movid_test()
{
    moModule *camera = factory->create("Camera");
    pipeline->addElement(camera);
    
    moModule *stream = new otStreamModule();
    pipeline->addElement(stream);

    stream->setInput(camera->getOutput(0), 0);
  
    return 0;
}
