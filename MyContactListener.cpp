#include "MyContactListener.h"
// Warning: it is a very bad idea to draw anything here instead of 
// in the main loop where the main drawing takes place
void MyContactListener::BeginContact(b2Contact *contact){

}

void MyContactListener::EndContact(b2Contact *contact){
	std::cout << "Contact ends!" << std::endl;
}
void MyContactListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold){
	//contact->GetFixtureA()->SetRestitution(0);
	//contact->GetFixtureB()->SetRestitution(0);
	std::cout << "Presolve" << std::endl;
		b2WorldManifold worldManifold;
	contact->GetWorldManifold(&worldManifold);

	int numPoints = contact->GetManifold()->pointCount;
	for(int i=0; i<numPoints; i++){
		canvas->setColor(255, 255, 0, 255);
		b2Vec2 normalStart = worldManifold.points[i] - 0.1 * worldManifold.normal;
		b2Vec2 normalEnd = worldManifold.points[i] + 0.1 * worldManifold.normal;
		canvas->drawScaledLine(normalStart, normalEnd);
	}

	
}
void MyContactListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse){
	std::cout << "PostSolve" << std::endl;
	//contact->GetFixtureA()->SetRestitution(0.6f);
	//contact->GetFixtureB()->SetRestitution(0.6f);
	std::cout << contact->GetFixtureA()->GetBody()->GetAngle() << std::endl;
	std::cout << contact->GetFixtureB()->GetBody()->GetAngle() << std::endl;
}