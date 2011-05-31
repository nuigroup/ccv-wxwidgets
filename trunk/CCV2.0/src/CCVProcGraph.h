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
#include "moFactory.h"
#include "moPipeline.h"
#include "CCVCommon.h"

typedef std::pair<std::string,std::string> MovidEdge;

class CCVProcGraph
{
private:
    std::map<std::string,std::string> modules;
    std::vector<MovidEdge> edges;
    moFactory *factory;
    
public:
    CCVProcGraph();
    int AddModule(std::string moduleID, std::string moduleType);
    int ConnectModules(std::string firstModuleID, std::string secondModuleID);
    void ClearGraph();
    int BuildPipeline(moPipeline *pipeline);
};

#endif
