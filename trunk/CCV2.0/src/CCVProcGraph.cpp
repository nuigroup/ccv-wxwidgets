/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVProcGraph.cpp
// Purpose:     Deccripting a processing graph
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#include "CCVProcGraph.h"

int CCVProcGraph::AddModule(std::string moduleID, std::string moduleType)
{
    modules[moduleID] = moduleType;
    
    return CCV_SUCCESS;
}

int CCVProcGraph::ConnectModules(std::string firstModuleID, std::string secondModuleID)
{
    
    return CCV_SUCCESS;
}

int CCVProcGraph::BuildPipeline(moPipeline *pipeline)
{
    return CCV_SUCCESS;
}
