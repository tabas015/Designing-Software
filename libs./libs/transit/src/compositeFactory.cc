#include "compositeFactory.h"


CompositeFactory::CreateEntity(JsonObject& entity){
	std::string type = entity["type"];
	IEntity* entityPtr = nullptr;
	
	for (int i = 0; i <= componentfactories-> size(); i++){
		if (type = "dorne"){
			droneFactory* entityPtr = new droneFactory(entity);
		}
		if (type = "robot"){
			droneFactory* entityPtr = new robotFactory(entity);
		}
	}
}

CompositeFactory::AddFactory(IEntityFactory* factoryEntity){
	

	
}