#include "ContactListener.h"


void ContactListener::BeginContact(b2Contact *contact){
	contactEvent->beginCall(contact);
}
void ContactListener::EndContact(b2Contact *contact){
	contactEvent->endCall(contact);
}
void ContactListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold){
	contactEvent->presolveCall(contact, oldManifold);
}
void ContactListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse){
	contactEvent->postsolveCall(contact, impulse);
}