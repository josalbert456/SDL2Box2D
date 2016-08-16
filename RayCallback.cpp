#include "RayCallback.h"


float32 RayCallback::ReportFixture(b2Fixture *fixture, 
	const b2Vec2& point, const b2Vec2 &normal, float32 fraction){
	std::cout << "Ray Callback" << std::endl;
	std::cout << fixture->GetType() << std::endl;
	//To find only the closest intersection:
	// return the fraction value from the callback
	// use the most recent intersection as the result
	//To find all intersections along the ray:
	// return 1 from the callback
	// store the intersections in a list
	//To simply find if the ray hits anything:
	// if you get a callback, something was hit (but it may not be the closest)
	// return 0 from the callback for efficiency
	m_fixture = fixture;
	m_point = point;
	m_normal = normal;
	m_fraction = fraction;
	return fraction;
}