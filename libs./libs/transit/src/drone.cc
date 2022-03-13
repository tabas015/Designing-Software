#include "drone.h"

Drone::Drone(JsonObject &obj) : details(obj) {
    JsonArray pos(obj["position"]);
    position = {pos[0], pos[1], pos[2]};

    JsonArray dir(obj["direction"]);
    direction = {dir[0], dir[1], dir[2]};
}

double Drone::GetPosition(int index) const {
    return position[index];
}

double Drone::GetDirection(int index) const {
    return direction[index];
}

JsonObject Drone::GetDetails() const {
    return details;
}
