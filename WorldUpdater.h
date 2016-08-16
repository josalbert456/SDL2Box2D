#ifndef __WORLDUPDATER__
#define __WORLDUPDATER__
#include <Box2D/Box2D.h>
#include <iostream>
class WorldUpdater{
public:
	WorldUpdater(b2World *w){
		world = w;
		timeStep = 1.0f/60.f;
		velocityIterations = 6;
		positionIterations = 2;
	}
	WorldUpdater(b2World *w, float t, int32 v, int pos){
		world = w;
		timeStep = t;
		velocityIterations = v;
		pos = positionIterations;
	}
	~WorldUpdater(){

	}
	void update();
	void setTimeStep(float ts);
	void setVelocityIterations(int32 vi);
	void setPositionIterations(int32 pi);
	void cleanUp();
	b2World *world;
	float timeStep;
	int32 velocityIterations;
	int32 positionIterations;
private:
protected:
};


#endif