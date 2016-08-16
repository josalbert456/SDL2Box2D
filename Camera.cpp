#include "Camera.h"
#include <iostream>
void Camera::setCamera(){
	list<b2Body *>::iterator bodyIterator;
	b2Vec2 posInc(prevPos.x - cameraCenterBody->GetPosition().x,
		cameraCenterBody->GetPosition().y - prevPos.y);
	for(bodyIterator = bodies.begin(); bodyIterator != bodies.end(); bodyIterator++){
		float x = (*bodyIterator)->GetPosition().x;
		float y = (*bodyIterator)->GetPosition().y;
		b2Vec2 setTo(x + posInc.x, y);
		(*bodyIterator)->SetTransform(setTo, (*bodyIterator)->GetAngle());
	}	
	prevPos.Set(cameraCenterBody->GetPosition().x, cameraCenterBody->GetPosition().y);
}
void Camera::addBody(b2Body *body){
	bodies.push_back(body);
}