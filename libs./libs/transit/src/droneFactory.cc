#include "droneFactory.h"

DroneFactory::CreateEntity(JsonObject& entity){
	Drone* entityPtr = new Drone(entity);
	
}