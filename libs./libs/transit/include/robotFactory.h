#ifndef ROBOTFACTORY_H_
#define ROBOTFACTORY_H_

#include "IEntityFactory.h"

class RobotFactory : public IEntityFactory  {
public:
    RobotFactory(JsonObject& entity){};

    IEntity* CreateEntity(JsonObject& entity);

};

#endif