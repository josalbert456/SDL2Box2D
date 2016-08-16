#ifndef __MYCONTACTLISTENER__
#define __MYCONTACTLISTENER__
#include <Box2D/Box2D.h>
#include <iostream>
#include "Canvas.h"
// Warning: it is a very bad idea to draw anything 
// in a subclass, especially a callback-like one instead of 
// in the main loop where the main drawing takes place
class MyContactListener : public b2ContactListener{
public:
	Canvas *canvas;
	MyContactListener(Canvas *c){
		canvas = c;
	}
	~MyContactListener(){}
	void BeginContact(b2Contact *contact);
	void EndContact(b2Contact *contact);
	void PreSolve(b2Contact *contact, const b2Manifold *oldManifold);
	void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse);
};

#endif