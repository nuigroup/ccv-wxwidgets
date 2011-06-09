/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVProcGraph.cpp
// Purpose:     Deccripting a processing graph
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#include "moDataStream.h"
#include "otMovidStreamModule.h"
#include "CCVProcGraph.h"

CCVProcGraph::CCVProcGraph() : moPipeline()
{
    locked = false;
    
    // initialize/discover all modules
    moFactory::init();
    factory = moFactory::getInstance();
    factory->registerModule("Stream", otStreamModule::createModule);
}

int CCVProcGraph::AddModule(std::string moduleID, std::string moduleType, bool isOutModule)
{    
    if (moduleTypeOf.find(moduleID) != moduleTypeOf.end()) {
	    return CCV_ERROR_ITEM_CANNOT_ADDED;
    }
    moduleTypeOf[moduleID] = moduleType;
    
    this->stop();    
    moModule *node = factory->create(moduleType);
    node->property("id").set(moduleID);
    this->addElement(node);
    moduleAddrOf[moduleID] = node;
    
    if (isOutModule) {
        outputModules[moduleID] = node;
    }
    
    return CCV_SUCCESS;
}

int CCVProcGraph::ConnectModules(std::string firstModuleID, std::string secondModuleID)
{
    if (moduleTypeOf.find(firstModuleID) == moduleTypeOf.end()
	 || moduleTypeOf.find(secondModuleID) == moduleTypeOf.end()) {
	    return CCV_ERROR_ITEM_NOT_EXISTS;
    }
    
    if (moduleAddrOf.find(firstModuleID) == moduleAddrOf.end()
     || moduleAddrOf.find(secondModuleID) == moduleAddrOf.end()) {
        return CCV_ERROR_ITEM_NOT_EXISTS;
    }
    	        
    moModule *moFirst = moduleAddrOf[firstModuleID];
    moModule *moSecond = moduleAddrOf[secondModuleID];
    this->stop();
	moFirst->stop();
	moSecond->stop();
	
    moSecond->setInput(moFirst->getOutput(moFirst->getOutputCount()),
                       moSecond->getInputCount());
    
    return CCV_SUCCESS;
}

int CCVProcGraph::RemoveModule(std::string moduleID)
{
    if (moduleTypeOf.find(moduleID) != moduleTypeOf.end()) {
	    return CCV_ERROR_ITEM_CANNOT_ADDED;
    }
    moModule *module = moduleAddrOf[moduleID]; 
    moDataStream *ds;
    
    this->stop();
	module->stop();
    
    // disconnect inputs
	if ( module->getInputCount() ) {
		for ( int i = 0; i < module->getInputCount(); i++ ) {
			ds = module->getInput(i);
			if ( ds == NULL )
				continue;
			ds->removeObserver(module);
		}
	}

	// disconnect output
	if ( module->getOutputCount() ) {
		for ( int i = 0; i < module->getOutputCount(); i++ ) {
			ds = module->getOutput(i);
			if ( ds == NULL )
				continue;
			ds->removeObservers();
		}
	}

	// remove element from pipeline
	this->removeElement(module);
    
    return CCV_SUCCESS;
}

void CCVProcGraph::ClearGraph()
{
    moduleTypeOf.clear();
    outputModules.clear();
    moduleAddrOf.clear();
    this->clear();
}

ModuleAddrDict CCVProcGraph::GetOutputModules()
{
    return outputModules;
}

bool CCVProcGraph::hasLocked()
{
    return locked;
}

int CCVProcGraph::Lock()
{
    if (!locked) {
        locked = true;
        return CCV_SUCCESS;
    }
    else 
        return CCV_ERROR_LOCKED;
}

void CCVProcGraph::Unlock()
{
    locked = false;
}
