#ifndef DRONEFACTORY_H_
#define DRONEFACTORY_H_
#include "IEntityFactory.h"

class DroneFactory : public IEntityFactory  {
public:
    DroneFactory(JsonObject& entity){};
    
    IEntity* CreateEntity(JsonObject& entity);

   
};

#endif