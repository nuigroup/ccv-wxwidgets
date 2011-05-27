/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVProcGraph.h
// Purpose:     Deccripting a processing graph
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#ifndef _PROCESS_GRAPH_H
#define _PROCESS_GRAPH_H

#include <map>
#include <vector>
#include <string>
#include <moPipeline.h>
#include "CCVCommon.h"

class CCVProcGraph
{
private:
    std::map<std::string,std::string> modules;
    std::pair<std::string,std::string> edges;
    
public:
    int AddModule(std::string moduleID, std::string moduleType);
    int ConnectModules(std::string firstModuleID, std::string secondModuleID);
    int BuildPipeline(moPipeline *pipeline);
};

#endif
