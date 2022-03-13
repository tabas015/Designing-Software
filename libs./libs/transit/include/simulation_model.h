#ifndef SIMULATION_MODEL_H_
#define SIMULATION_MODEL_H_

#include "controller.h"
#include "robot.h"
#include "drone.h"

//--------------------  Model ----------------------------

/// Simulation Model handling the transit simulation.  The model can communicate with the controller.
class SimulationModel {
public:
    SimulationModel(IController& controller);

    /// Creates an simulation entity
    void CreateEntity(JsonObject& entity);

    /// Schedules a trip for an object in the scene
    void ScheduleTrip(JsonObject& details);

    /// Updates the simulation
    void Update(double dt);

private:
    IController& controller;
    std::vector<IEntity *> entities;
};

#endif
