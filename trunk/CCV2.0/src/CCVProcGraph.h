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

/**
    Used to present an edge of the proc graph. The two strings in this pair
    are the ids of the income module and the outcome module.
*/  
typedef std::pair<std::string,std::string> MovidEdge;
      
/**
    Dict for finding a module's address with its ID. This is faster
    than moPipeline::getModuleById().
*/    
typedef std::map<std::string, moModule *> ModuleAddrDict;

/**
    Dict for finding a module's type with its ID.
*/    
typedef std::map<std::string, std::string> ModuleTypeDict;

class CCVProcGraph : public moPipeline
{
private:
    ModuleTypeDict modulesTypeOf;
    std::vector<MovidEdge> edges;
    moFactory *factory;
    ModuleAddrDict outputModules;
    ModuleAddrDict moduleAddr;
    
    /**
        Once locked, using the pipeline will be not allowed.
    */
    bool locked;
    
public:
    CCVProcGraph();
    
    /**
        Add a module. If the module is used to draw on UI, set isOutModule to true. 
    */
    int AddModule(std::string moduleID, std::string moduleType, bool isOutModule=false);
    
    int ConnectModules(std::string firstModuleID, std::string secondModuleID);
        
    /**
        The graph is just a logical struct. Once you have set your graph by
        AddModule() and ConnectModules(..), you need use BuildPipeline() to
        generate a real pipeline.
    */
    int BuildPipeline();
        
    /**
        Clear graph, dicts and the pipeline..
    */
    void ClearGraph();
    
    /**
        Get a dict that includes all modules that were output stream modules.
    */
    ModuleAddrDict GetOutputModules();
    
    /**
        Check whether the pipeline was locked.
    */
    bool hasLocked();
    
    /**
        Lock the pipeline.
    */
    int Lock();
     
    /**
        Unlock the pipeline.
    */
    void Unlock();
};

#endif
