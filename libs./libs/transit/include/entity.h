#ifndef ENTITY_H_
#define ENTITY_H_

#include "util/json.h"

//--------------------  Controller Interface ----------------------------

/// Abstract controller class used in the Transit Service.  Uses the Model View Controller Pattern
class IEntity {
public:
    IEntity() {
      static int currentId = 0;
      id = currentId;
      currentId++;
    }
    virtual ~IEntity() {}
    virtual int GetId() const { return id; }
    virtual double GetPosition(int index) const = 0;
    virtual double GetDirection(int index) const = 0;
    virtual JsonObject GetDetails() const = 0;
    virtual void Update(double dt) {}
private:
    int id;
};

#endif
