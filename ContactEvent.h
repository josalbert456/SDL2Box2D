#ifndef __CONTACTEVENT__
#define __CONTACTEVENT__
#include <Box2D/Box2D.h>
class ContactEvent{
public:
	ContactEvent(){}
	~ContactEvent(){}
	virtual void presolveCall(b2Contact *contact, const b2Manifold* oldManifold);
	virtual void beginCall(b2Contact *contact);
	virtual void endCall(b2Contact *contact);
	virtual void postsolveCall(b2Contact *contact, const b2ContactImpulse *impulse);
};

#endif