#ifndef __AABBCALLBACK__
#define __AABBCALLBACK__
#include <Box2D/Box2D.h>
#include <iostream>
#include "Canvas.h"
class AABBCallback : public b2QueryCallback{
public:
	Canvas *canvas;
	AABBCallback(Canvas *c){
		canvas = c;
	}
	~AABBCallback(){}
	bool ReportFixture(b2Fixture *fixture);
};

#endif