/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVMovidProcess.cpp
// Purpose:     Provide the thread for movid processing
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#include <wx/string.h>
#include <wx/log.h>
#include "CCVMovidProcess.h"
#include "otMovidStreamModule.h"

int g_config_delay = 50;

CCVMovidProcess::CCVMovidProcess()
{
    // initialize/discover all modules
    moFactory::init();
    factory = moFactory::getInstance();

    // create our pipeline
    pipeline = new moPipeline();
}

void *CCVMovidProcess::Entry()
{
    movid_test();
  
    pipeline->start();
    while (true) {
        cvWaitKey(50);

        if ( pipeline->isStarted() )
            pipeline->poll();

        while ( pipeline->haveError() )
            wxLogMessage(wxT("Pipeline error: %s"), pipeline->getLastError().c_str());
            
        if (pipeline->lastModule()->getName() == "Stream") {
            CvSize roiSize;
		    int step = 0;
		    unsigned char *outputRawImage;
		    IplImage *outIpl = ((otStreamModule *)(pipeline->lastModule()))->output_buffer;
            cvGetRawData(outIpl, &outputRawImage, &step, &roiSize );
            
            // then draw outputRawImage on wxWidgets
            // (drawing codes here)
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
