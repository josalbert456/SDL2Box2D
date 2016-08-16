#ifndef __SENSORCONTACTCALL__
#define __SENSORCONTACTCALL__
#include <Box2D/Box2D.h>
#include <iostream>

//SensorContactListener is the same with the Normal
// contact listener
class SensorContactCall : public b2ContactListener{
public:
	bool *detected;
	SensorContactCall(bool *isDetected){
		detected = isDetected;
	}
	~SensorContactCall(){}
	void BeginContact(b2Contact *contact);
	void EndContact(b2Contact *contact);
	void PreSolve(b2Contact *contact, const b2Manifold *oldManifold);
	void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse);
};

#endif