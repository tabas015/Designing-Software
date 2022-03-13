#ifndef DRONE_H
#define DRONE_H

#include "util/json.h"
#include "entity.h"

#include <vector>

class Drone : public IEntity {
public:
    Drone(JsonObject& obj);

    ~Drone() override = default;

    double GetPosition(int index) const override;

    double GetDirection(int index) const override;

    JsonObject GetDetails() const override;

protected:
    JsonObject details;
    std::vector<double> position;
    std::vector<double> direction;
};

#endif //DRONE_H
