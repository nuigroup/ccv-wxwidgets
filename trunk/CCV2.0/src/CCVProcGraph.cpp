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
    
    if (isOutModule) {
        outputModuleIDs.push_back(moduleID);
    }
    
    return CCV_SUCCESS;
}

int CCVProcGraph::ConnectModules(std::string firstModuleID, std::string secondModuleID)
{ 	        
    moModule *moFirst = this->getModuleById(firstModuleID);
    moModule *moSecond = this->getModuleById(secondModuleID);
    
    this->stop();
	moFirst->stop();
	moSecond->stop();
	
    // TODO: replace "moFirst->getOutput(0), 0" with some more flexible codes
    moSecond->setInput(moFirst->getOutput(0), 0);
    
    return CCV_SUCCESS;
}

int CCVProcGraph::DisconnectModules(std::string firstModuleID, std::string secondModuleID)
{
    moModule *moFirst = this->getModuleById(firstModuleID);
    moModule *moSecond = this->getModuleById(secondModuleID);
    
    this->stop();
	moFirst->stop();
	moSecond->stop();
	
    // TODO: DisconnectModules
    
    return CCV_SUCCESS;
}

int CCVProcGraph::RemoveModule(std::string moduleID)
{
    if (moduleTypeOf.find(moduleID) != moduleTypeOf.end()) {
	    return CCV_ERROR_ITEM_CANNOT_ADDED;
    }
    moModule *module = this->getModuleById(moduleID); 
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
	
	Strings::iterator iter_id = find(outputModuleIDs.begin(), outputModuleIDs.end(), moduleID);
    if (iter_id != outputModuleIDs.end()) { 
        outputModuleIDs.erase(iter_id);
    }
    
    ModuleTypeDict::iterator iter_type = moduleTypeOf.find(moduleID); 
    if (iter_type != moduleTypeOf.end()) { 
        moduleTypeOf.erase(iter_type);
    }

	// remove element from pipeline
	this->removeElement(module);
    
    return CCV_SUCCESS;
}

void CCVProcGraph::ClearGraph()
{
    moduleTypeOf.clear();
    outputModuleIDs.clear();
    this->clear();
}

Strings CCVProcGraph::GetOutputModuleIDs()
{
    return outputModuleIDs;
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
