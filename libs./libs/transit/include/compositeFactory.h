#ifndef COMPOSITEFACTORY_H_
#define COMPOSITEFACTORY_H_

#include "iEntityFactory.h"


class CompositeFactory : public IEntityFactory {
public:
    CompositeFactory(JsonObject& entity){};
    IEntity* CreateEntity(JsonObject& entity);
    void AddFactory (IEntityFactory* factoryEntity);


private:
    std::vector<IEntityFactory *> I;
};

#endif
