#include "simulation_model.h"

SimulationModel::SimulationModel(IController& controller) : controller(controller) {}

/// Creates an simulation entity
void SimulationModel::CreateEntity(JsonObject& entity) {
    //int id = entity["entityId"];
    std::string type = entity["type"];
    std::string name = entity["name"];
    JsonArray position = entity["position"];
    std::cout << name << ": " << position << std::endl;
    std::cout << entity.ToString() << std::endl;

    // Call AddEntity to add it to the view
    IEntity* entityPtr = nullptr;
    if (type == "drone") {
        entityPtr = new Drone(entity);
    } else if (type == "robot") {
        entityPtr = new Robot(entity);
    }

    if (entityPtr != nullptr) {
        controller.AddEntity(*entityPtr);
    }
}

/// Schedules a trip for an object in the scene
void SimulationModel::ScheduleTrip(JsonObject& details) {
    std::string name = details["name"];
    JsonArray start = details["start"];
    JsonArray end = details["end"];
    std::cout << name << ": " << start << " --> " << end << std::endl;
    double startx = start[0];
    double starty = start[1];
    double endx = end[0];
    double endy = end[1];
    controller.SendEventToView("TripScheduled", details);

    // Add a route to visualize the path
    // controller.AddPath(pathId, path);
}

/// Updates the simulation
void SimulationModel::Update(double dt) {
    // std::cout << "Update: " << dt << std::endl;
    // Call controller to update changed entities
    // for (int i = 0; i < entities.size(); i++) {
    //   static_cast<EntityBase*>(entities[i])->Update(dt);
    //   controller.UpdateEntity(*entities[i]);
    // }


    // Remove entites you no longer need
    // controller.RemoveEntity(myDeletedEntityId);

    // Remove paths you no longer want to see:
    // controller.RemovePath(myDeletedPathId);
}
