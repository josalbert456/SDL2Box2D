#ifndef __CONTENTLISTENER__
#define __CONTENTLISTENER__
#include <Box2D/Box2D.h>
#include "ContactEvent.h"

class ContactListener : public b2ContactListener{
public:
	ContactListener(){
		contactEvent = new ContactEvent();
	}
	~ContactListener(){}
	void BeginContact(b2Contact *contact);
	void EndContact(b2Contact *contact);
	void PreSolve(b2Contact *contact, const b2Manifold *oldManifold);
	void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse);
	ContactEvent *contactEvent;
};


#endif