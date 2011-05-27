/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVProcGraph.cpp
// Purpose:     Deccripting a processing graph
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#include "CCVProcGraph.h"
#include "otMovidStreamModule.h"

CCVProcGraph::CCVProcGraph()
{
    // initialize/discover all modules
    moFactory::init();
    factory = moFactory::getInstance();
    factory->registerModule("Stream", otStreamModule::createModule);
}

int CCVProcGraph::AddModule(std::string moduleID, std::string moduleType)
{    
    if (modules.find(moduleID) != modules.end()) {
	return CCV_ERROR_ITEM_CANNOT_ADDED;
    }
    modules[moduleID] = moduleType;
    return CCV_SUCCESS;
}

int CCVProcGraph::ConnectModules(std::string firstModuleID, std::string secondModuleID)
{
    if (modules.find(firstModuleID) == modules.end()
	|| modules.find(secondModuleID) == modules.end()) {
	return CCV_ERROR_ITEM_NOT_EXISTS;
    }

    edges.push_back(MovidEdge(firstModuleID, secondModuleID));
    
    return CCV_SUCCESS;
}

int CCVProcGraph::BuildPipeline(moPipeline *pipeline)
{
    for (std::vector<MovidEdge>::const_iterator iter = edges.begin();
	 iter != edges.end(); ++iter) {
	std::string id_input = iter->first;
	std::string id_output = iter->second;
	
	if (modules.find(id_input) == modules.end())
	    return CCV_ERROR_ITEM_NOT_EXISTS;
	std::string type_input = modules[id_input];

	if (modules.find(id_output) == modules.end())
	    return CCV_ERROR_ITEM_NOT_EXISTS;
	std::string type_output = modules[id_output];

	moModule *input = factory->create(type_input);
	pipeline->addElement(input);
	moModule *output = factory->create(type_output);
	pipeline->addElement(output);
	output->setInput(input->getOutput(0), 0);
    }
    return CCV_SUCCESS;
}

void CCVProcGraph::ClearGraph()
{
    modules.clear();
    edges.clear();
}
