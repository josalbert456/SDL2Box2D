#include "WorldUpdater.h"


void WorldUpdater::update(){
	world->Step(timeStep, velocityIterations, positionIterations);
}
void WorldUpdater::setTimeStep(float ts){
	timeStep = ts;
}
void WorldUpdater::setVelocityIterations(int32 vi){
	velocityIterations = vi;
}
void WorldUpdater::setPositionIterations(int32 pi){
	positionIterations = pi;
}
void WorldUpdater::cleanUp(){	
	for(b2Body *b = world->GetBodyList(); b; b=b->GetNext()){
		world->DestroyBody(b);
	}
	delete world;
	std::cout << "Clean Up!" << std::endl;
}