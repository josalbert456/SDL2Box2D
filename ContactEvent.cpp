#include "ContactEvent.h"


void ContactEvent::presolveCall(b2Contact *contact, const b2Manifold *oldManifold){

}
void ContactEvent::beginCall(b2Contact *contact){

}
void ContactEvent::endCall(b2Contact *contact){

}
void ContactEvent::postsolveCall(b2Contact *contact, const b2ContactImpulse *impulse){

}

/* EXAMPLE */
/*	A better design may avoid the repetition of iteration of contact->GetNext()

class CameraContactEvent : public ContactEvent{
public:
	Canvas *canvas;
	CameraContactEvent(Canvas *c){
		canvas = c;
	}
	void presolveCall(b2Contact *contact, const b2Manifold *oldManifold){
		b2Contact *c = contact;
		while(c){
			c = c->GetNext();
		}
	}
	void beginCall(b2Contact *contact){
		b2Contact *c = contact;
		while(c){
			c = c->GetNext();
		}
	}
	void endCall(b2Contact *contact){
		b2Contact *c = contact;
		while(c){
			c = c->GetNext();
		}
	}
	void postsolveCall(b2Contact *contact, const b2ContactImpulse *impulse){
		b2Contact *c = contact;
		while(c){
			c = c->GetNext();
		}
	}
};
*/