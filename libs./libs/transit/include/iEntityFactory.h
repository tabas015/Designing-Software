#ifndef IENTITYFACTORY_H_
#define IENTITYFACTORY_H_


class IEntityFactory {
public:
    IEntityFactory(){};
    virtual IEntity * CreateEntity(JsonObject& entity){};
};

#endif
