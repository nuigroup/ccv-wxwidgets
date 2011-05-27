/////////////////////////////////////////////////////////////////////////////
// Name:        src/MovidGraph.h
// Purpose:     For generating a movid processing graph
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#ifndef _MOVID_GRAPH_H
#define _MOVID_GRAPH_H

#include <map>
#include <vector>
#include <string>
#include <moPipeline.h>
#include "CCVCommon.h"

class MovidGraph
{
private:
    std::map<std::string,std::string> MovidModules;
    std::pair<std::string,std::string> MovidEdges;
    
public:
    int AddModule(std::string moduleID, std::string moduleType);
    int ConnectModules(std::string firstModuleID, std::string secondModuleID);
    int BuildPipeline(moPipeline *pipeline);
};

#endif
