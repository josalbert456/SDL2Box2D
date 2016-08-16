#include "SensorContactCall.h"

void SensorContactCall::BeginContact(b2Contact *contact){
	std::cout << "Sense Object" << std::endl;
	*detected = true;
}

void SensorContactCall::EndContact(b2Contact *contact){
	*detected = false;
}
void SensorContactCall::PreSolve(b2Contact *contact, const b2Manifold *oldManifold){

}
void SensorContactCall::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse){

}