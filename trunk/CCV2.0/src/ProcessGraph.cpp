/////////////////////////////////////////////////////////////////////////////
// Name:        src/ProcessGraph.cpp
// Purpose:     For generating a movid processing graph
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#include "ProcessGraph.h"

int ProcessGraph::AddModule(std::string moduleID, std::string moduleType)
{
    modules[moduleID] = moduleType;
    
    return CCV_SUCCESS;
}

int ProcessGraph::ConnectModules(std::string firstModuleID, std::string secondModuleID)
{
    
    return CCV_SUCCESS;
}

int ProcessGraph::BuildPipeline(moPipeline *pipeline)
{
    return CCV_SUCCESS;
}
