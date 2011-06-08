/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVProcGraph.cpp
// Purpose:     Deccripting a processing graph
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#include "CCVProcGraph.h"
#include "otMovidStreamModule.h"

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
    if (modulesTypeOf.find(moduleID) != modulesTypeOf.end()) {
	return CCV_ERROR_ITEM_CANNOT_ADDED;
    }
    modulesTypeOf[moduleID] = moduleType;
    
    moModule *node = factory->create(moduleType);
    node->property("id").set(moduleID);
    this->addElement(node);
    moduleAddr[moduleID] = node;
    
    if (isOutModule) {
        outputModules[moduleID] = node;
    }
    
    return CCV_SUCCESS;
}

int CCVProcGraph::ConnectModules(std::string firstModuleID, std::string secondModuleID)
{
    if (modulesTypeOf.find(firstModuleID) == modulesTypeOf.end()
	 || modulesTypeOf.find(secondModuleID) == modulesTypeOf.end()) {
	    return CCV_ERROR_ITEM_NOT_EXISTS;
    }

    edges.push_back(MovidEdge(firstModuleID, secondModuleID));
    
    if (moduleAddr.find(firstModuleID) == moduleAddr.end()
     || moduleAddr.find(secondModuleID) == moduleAddr.end()) {
        return CCV_ERROR_ITEM_NOT_EXISTS;
    }
    	        
    moduleAddr[secondModuleID]->setInput(moduleAddr[firstModuleID]->getOutput(0), 0);
    
    return CCV_SUCCESS;
}

void CCVProcGraph::ClearGraph()
{
    modulesTypeOf.clear();
    edges.clear();
    outputModules.clear();
    moduleAddr.clear();
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

int CCVProcGraph::BuildPipeline()
{
    if (this->Lock() != CCV_SUCCESS) {
        return CCV_ERROR_LOCKED;
    }
    // TODO: Redegin the graph struct
    // TODO: Move building codes to here from AddModule() and ConnectModules(..)
    
    this->Unlock();
    return CCV_ERROR_LOCKED;
}