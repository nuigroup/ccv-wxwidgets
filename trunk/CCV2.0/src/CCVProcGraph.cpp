/////////////////////////////////////////////////////////////////////////////
// Name:        src/CCVProcGraph.cpp
// Purpose:     Deccripting a processing graph
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////

#include "moDataStream.h"
#include "otMovidStreamModule.h"
#include "CCVProcGraph.h"

CCVProcGraph::CCVProcGraph() : moPipeline()
{
    busy = false;
    moDaemon::init();
    factory = moFactory::getInstance();
    factory->registerModule("Stream", otStreamModule::createModule);
}

moModule * CCVProcGraph::AddModule(std::string moduleID, std::string moduleType, bool isOutModule)
{
    moModule *node = CreateModule(moduleID, moduleType);
    this->addElement(node);
    
    if (isOutModule) {
        outputModuleIDs.push_back(moduleID);
    }
    
    return node;
}

int CCVProcGraph::AddExistedModule(moModule *node, bool isOutModule)
{
    this->addElement(node);
    
    if (isOutModule) {
        outputModuleIDs.push_back(node->property("id").asString());
    }
    
    return CCV_SUCCESS;
}

moModule * CCVProcGraph::CreateModule(std::string moduleID, std::string moduleType)
{
    moduleTypeOf[moduleID] = moduleType;
    
    moModule *node = factory->create(moduleType);
    node->property("id").set(moduleID);
    
    return node;
}

int CCVProcGraph::ConnectModules(std::string firstModuleID, std::string secondModuleID, int outSlot, int inSlot)
{
    moModule *moFirst = this->getModuleById(firstModuleID);
    moModule *moSecond = this->getModuleById(secondModuleID);
    moSecond->setInput(moFirst->getOutput(outSlot), inSlot);
    
    return CCV_SUCCESS;
}

int CCVProcGraph::DisconnectModules(std::string firstModuleID, std::string secondModuleID)
{
    moModule *moFirst = this->getModuleById(firstModuleID);
    moModule *moSecond = this->getModuleById(secondModuleID);
    
    this->stop();
    moFirst->stop();
    moSecond->stop();
    
    moDataStream *ds;
    // ds->observers only stores the second module, do not store the first
    // so we only remove moSecond
    if ( moSecond->getInputCount() ) {
        for ( int i = 0; i < moSecond->getInputCount(); i++ ) {
            ds = moSecond->getInput(i);
            if ( ds == NULL )
                continue;
            ds->removeObserver(moSecond);
        }
    }
    
    return CCV_SUCCESS;
}

int CCVProcGraph::ReplaceModule(moModule *moOld, moModule *moNew)
{
    this->stop();
    moOld->stop();
    moNew->stop();

    // Backup connections and then remove the old module
    std::vector<moDataStream *> inputDataStreams;
    std::vector<moModule *> outputModules;
    if ( moOld->getInputCount() ) {
        for ( int i = 0; i < moOld->getInputCount(); i++ ) {
            moDataStream *ds = moOld->getInput(i);
            if ( ds == NULL )
                continue;
            ds->removeObserver(moOld);
            inputDataStreams.push_back(ds);
        }
    }
    if ( moOld->getOutputCount() ) {
        for ( int i = 0; i < moOld->getOutputCount(); i++ ) {
            moDataStream *ds = moOld->getOutput(i);
            if ( ds == NULL )
                continue;
            for (unsigned int j=0; j<ds->getObserverCount(); j++) {
                outputModules.push_back(ds->getObserver(j));
            }
            ds->removeObservers();
        }
    }    

    // Connect the new module
    for (unsigned int i = 0; i < inputDataStreams.size(); i++) {
        moNew->setInput(inputDataStreams[i], i);
    }
    for (unsigned int i = 0; i < outputModules.size(); i++) {
        outputModules[i]->setInput(moNew->getOutput(0), 0);
    }
    
    return CCV_SUCCESS;
}

int CCVProcGraph::RemoveModule(std::string moduleID)
{
    this->stop();
   
    if (this->getModuleById(moduleID) == NULL) {
        return CCV_ERROR_ITEM_CANNOT_ADDED;
    }
    moModule *module = this->getModuleById(moduleID); 
    module->stop();

    moDataStream *ds;
    
    // disconnect inputs
    if ( module->getInputCount() ) {
        for ( int i = 0; i < module->getInputCount(); i++ ) {
            ds = module->getInput(i);
            if ( ds == NULL )
                continue;
            ds->removeObserver(module);
        }
    }

    // disconnect output
    if ( module->getOutputCount() ) {
        for ( int i = 0; i < module->getOutputCount(); i++ ) {
            ds = module->getOutput(i);
            if ( ds == NULL )
                continue;
            ds->removeObservers();
        }
    }
    
    Strings::iterator iter_id = find(outputModuleIDs.begin(), outputModuleIDs.end(), moduleID);
    if (iter_id != outputModuleIDs.end()) { 
        outputModuleIDs.erase(iter_id);
    }
    
    ModuleTypeDict::iterator iter_type = moduleTypeOf.find(moduleID); 
    if (iter_type != moduleTypeOf.end()) { 
        moduleTypeOf.erase(iter_type);
    }

    // remove element from pipeline
    this->removeElement(module);
    
    return CCV_SUCCESS;
}

void CCVProcGraph::ClearGraph()
{
    moduleTypeOf.clear();
    outputModuleIDs.clear();
    this->clear();
}

Strings CCVProcGraph::GetOutputModuleIDs()
{
    return outputModuleIDs;
}

bool CCVProcGraph::isBusy()
{
    return busy;
}

void CCVProcGraph::SetBusy()
{
    busy = true;
}

void CCVProcGraph::SetNotBusy()
{
    busy = false;
}
