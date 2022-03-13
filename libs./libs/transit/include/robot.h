#ifndef ROBOT_H
#define ROBOT_H

#include "util/json.h"
#include "entity.h"

#include <vector>

class Robot : public IEntity {
public:
    Robot(JsonObject& obj);

    ~Robot() override = default;

    double GetPosition(int index) const override;

    double GetDirection(int index) const override;

    JsonObject GetDetails() const override;

protected:
    JsonObject details;
    std::vector<double> position;
    std::vector<double> direction;
};

#endif //ROBOT_H
