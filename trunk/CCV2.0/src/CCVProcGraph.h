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
    Item type of ModuleList. The first part of the std::pair is the address
    f a module, and the second part is the lable. The lable is an alias of 
    the module, which may be used to indicate the related UI item.
*/    
typedef std::pair<moModule *, std::string> ModuleListItem;
    
/**
    A vector that list some modules.
*/ 
typedef std::vector<ModuleListItem> ModuleList;

class CCVProcGraph : public moPipeline
{
private:
    std::map<std::string,std::string> modulesTypeOf;
    std::vector<MovidEdge> edges;
    moFactory *factory;
    bool locked;
    ModuleList outputModules;
    std::map<std::string, moModule *> moduleAddr;
    
public:
    CCVProcGraph();
    
    /**
        Add a module. If the module is used to draw on UI, set isOutModule to true. 
    */
    int AddModule(std::string moduleID, std::string moduleType, bool isOutModule=false);
    
    int ConnectModules(std::string firstModuleID, std::string secondModuleID);
        
    /**
        Clear both the graph and the pipeline..
    */
    void ClearGraph();
    
    /**
        Get a vector that includes all modules that were output stream modules.
    */
    ModuleList GetOutputModules();
    
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
