/*
 * EntityInstanceManager.h
 *
 *  Created on: 24.01.2015
 *      Author: aschaeffer
 */

#ifndef SRC_ENGINE_ENTITY_ENTITYINSTANCEMANAGER_H_
#define SRC_ENGINE_ENTITY_ENTITYINSTANCEMANAGER_H_

#include "../EntitySystemBase.h"
#include "EntityTypeManager.h"
#include "../domain/InstanceRefPtr.h"
#include "../domain/TypeRefPtr.h"
#include "../domain/graph/EntityInstance.h"

/**
 * The EntityInstanceManager manages all entity instances.
 */
class EntityInstanceManager
{
    public:
        EntityInstanceManager(CefRefPtr<EntityTypeManager> entity_type_manager) : entity_type_manager(entity_type_manager) {};
        virtual ~EntityInstanceManager() {};

        InstanceRefPtr<EntityInstance> Create(TypeRefPtr<EntityType> entity_type);
        InstanceRefPtr<EntityInstance> Create(std::string entity_type_name);

        bool Exists(std::string uuid);
        InstanceRefPtr<EntityInstance> Get(std::string uuid);
        std::list<InstanceRefPtr<EntityInstance> > GetAll(TypeRefPtr<EntityType> entity_type);
        std::list<InstanceRefPtr<EntityInstance> > GetAll(std::string entity_type_name);

        void DeleteInstance(InstanceRefPtr<EntityInstance> instance);
        void DeleteInstance(std::string uuid);

        void DeleteAllInstances();
        void DeleteAllInstances(TypeRefPtr<EntityType> entity_type);

        int Size();

    private:
        // The entity instances.
        std::map<std::string, InstanceRefPtr<EntityInstance> > entity_instances;

        // The entity type manager.
        CefRefPtr<EntityTypeManager> entity_type_manager;

        // Include the default reference counting implementation.
        IMPLEMENT_REFCOUNTING(EntityInstanceManager);

};

#endif /* SRC_ENGINE_ENTITY_ENTITYINSTANCEMANAGER_H_ */