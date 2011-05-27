/////////////////////////////////////////////////////////////////////////////
// Name:        src/MovidGraph.cpp
// Purpose:     For generating a movid processing graph
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#include "MovidGraph.h"

int MovidGraph::AddModule(std::string moduleID, std::string moduleType)
{
    MovidModules[moduleID] = moduleType;
    
    return CCV_SUCCESS;
}

int MovidGraph::ConnectModules(std::string firstModuleID, std::string secondModuleID)
{
    
    return CCV_SUCCESS;
}

int MovidGraph::BuildPipeline(moPipeline *pipeline)
{
    return CCV_SUCCESS;
}
