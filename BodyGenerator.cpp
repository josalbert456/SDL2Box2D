#include "BodyGenerator.h"

b2Body *BodyGenerator::genBody(float x, float y, float friction, float restitution){
	b2BodyDef bodyOneDef;
	bodyOneDef.type = b2_dynamicBody;
	bodyOneDef.position.Set(x, y);
	bodyOneDef.angle = 0;
	b2Body *bodyOne = world->CreateBody(&bodyOneDef);
	b2PolygonShape bodyOneShape;
	bodyOneShape.SetAsBox(0.25, 0.25);
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &bodyOneShape;
	boxFixtureDef.density = 1;
	boxFixtureDef.friction = friction;
	boxFixtureDef.restitution = restitution;
	bodyOne->CreateFixture(&boxFixtureDef);
	return bodyOne;
}
b2Body *BodyGenerator::genSimpleBox(b2Vec2 pos, b2Vec2 size, float friction, float restitution){
	b2BodyDef bodyOneDef;
	bodyOneDef.type = b2_dynamicBody;
	bodyOneDef.position = pos;
	bodyOneDef.angle = 0;
	b2Body *bodyOne = world->CreateBody(&bodyOneDef);
	b2PolygonShape bodyOneShape;
	bodyOneShape.SetAsBox(size.x, size.y);
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &bodyOneShape;
	boxFixtureDef.density = 1;
	boxFixtureDef.friction = friction;
	boxFixtureDef.restitution = restitution;
	bodyOne->CreateFixture(&boxFixtureDef);
	return bodyOne;
}
b2Body *BodyGenerator::genPolygonBody(b2PolygonShape *polygonShape, b2Vec2 pos, float friction, 
	float restitution){
	b2BodyDef bodyOneDef;
	bodyOneDef.type = b2_dynamicBody;
	bodyOneDef.position.Set(pos.x, pos.y);
	bodyOneDef.angle = 0;
	b2Body *bodyOne = world->CreateBody(&bodyOneDef);
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = polygonShape;
	boxFixtureDef.density = 1;
	boxFixtureDef.friction = friction;
	boxFixtureDef.restitution = restitution;
	bodyOne->CreateFixture(&boxFixtureDef);

	return bodyOne;
}
b2Body *BodyGenerator::genPolygonBody(b2PolygonShape *polygonShape, b2Vec2 pos, float friction, 
	float restitution, void *userData){
	b2BodyDef bodyOneDef;
	bodyOneDef.type = b2_dynamicBody;
	bodyOneDef.position.Set(pos.x, pos.y);
	bodyOneDef.angle = 0;
	b2Body *bodyOne = world->CreateBody(&bodyOneDef);
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = polygonShape;
	boxFixtureDef.density = 1;
	boxFixtureDef.friction = friction;
	boxFixtureDef.restitution = restitution;
	bodyOne->CreateFixture(&boxFixtureDef);
	bodyOne->SetUserData(userData);
	return bodyOne;
}	
b2Body *BodyGenerator::genCircle(b2Vec2 center, float radius, float friction, float restitution,
	float category, float mask){
	b2BodyDef bodyOneDef;
	bodyOneDef.type = b2_dynamicBody;
	bodyOneDef.position.Set(center.x, center.y);
	bodyOneDef.angle = 0;
	b2Body *bodyOne = world->CreateBody(&bodyOneDef);
	b2CircleShape bodyOneShape;
	bodyOneShape.m_p.Set(0, 0);
	bodyOneShape.m_radius = radius;
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &bodyOneShape;
	boxFixtureDef.friction = friction;
	boxFixtureDef.restitution = restitution;
	boxFixtureDef.filter.categoryBits = category;
	boxFixtureDef.filter.maskBits = mask;
	boxFixtureDef.density = 1;
	bodyOne->CreateFixture(&boxFixtureDef);
	return bodyOne;
}
b2Body *BodyGenerator::genCircle(b2Vec2 center, float radius, float friction, float restitution){
	b2BodyDef bodyOneDef;
	bodyOneDef.type = b2_dynamicBody;
	bodyOneDef.position.Set(center.x, center.y);
	bodyOneDef.angle = 0;
	b2Body *bodyOne = world->CreateBody(&bodyOneDef);
	b2CircleShape bodyOneShape;
	bodyOneShape.m_p.Set(0, 0);
	bodyOneShape.m_radius = radius;
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &bodyOneShape;
	boxFixtureDef.friction = friction;
	boxFixtureDef.restitution = restitution;
	boxFixtureDef.density = 1;
	bodyOne->CreateFixture(&boxFixtureDef);
	return bodyOne;
}