#include "robotFactory.h"


RobotFactory::CreateEntity(JsonObject& entity){
	
    Robot* entityPtr = new Robot(entity);
  

}