#ifndef __RAYCALLBACK__
#define __RAYCALLBACK__
#include <Box2D/Box2D.h>
#include <iostream>
#include <stdio.h>

// Note, the raycast callback should be registered in
// the loop, that is each time the world steps forward
// you should registered once again
class RayCallback : public b2RayCastCallback{
public:
	RayCallback(){
		m_fixture = NULL;
	}
	~RayCallback(){}
	float32 ReportFixture(b2Fixture *fixture, const b2Vec2& point, const b2Vec2 &normal, float32 fraction);
	b2Fixture *m_fixture;
	b2Vec2 m_point;
	b2Vec2 m_normal;
	float32 m_fraction;
};

#endif