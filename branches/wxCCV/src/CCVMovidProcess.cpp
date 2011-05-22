/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVMovidProcess.cpp
// Purpose:     Provide the thread for movid processing
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#include "CCVMovidProcess.h"
#include <wx/string.h>
#include <wx/log.h>

int g_config_delay = 200;

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
  movid_test1();
  
  pipeline->start();
  while (true) {
    cvWaitKey(50);

    if ( pipeline->isStarted() )
      pipeline->poll();

    while ( pipeline->haveError() )
      wxLogMessage(wxT("Pipeline error: %s"), pipeline->getLastError().c_str());
  }
  pipeline->stop();

  return NULL;
}

int CCVMovidProcess::movid_test1()
{
  pipeline->clear();

  moModule *camera = factory->create("Camera");
  pipeline->addElement(camera);

  moModule *display = factory->create("ImageDisplay");
  pipeline->addElement(display);

  display->setInput(camera->getOutput(0), 0);
  
  return 0;
}

int CCVMovidProcess::movid_test2()
{
  pipeline->clear();

  moModule *camera = factory->create("Camera");
  pipeline->addElement(camera);

  moModule *invert = factory->create("Invert");
  pipeline->addElement(invert);

  moModule *display = factory->create("ImageDisplay");
  pipeline->addElement(display);

  display->setInput(invert->getOutput(0), 0);
  invert->setInput(camera->getOutput(0), 0);
  
  return 0;
}
