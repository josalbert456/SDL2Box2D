#include "EdgeGenerator.h"
// Note: if we set the m_hasVertex0 and m_hasVertex3 fields as true
// the bodies that hit the egdge may probably fall under the edge
b2Body* EdgeGenerator::genSimpleEdge(b2Vec2 start, b2Vec2 end, b2Vec2 pos){
	b2EdgeShape bottomBorderTwo;
	bottomBorderTwo.Set(start, end);
	//bottomBorderTwo.m_hasVertex0 = true;
	//bottomBorderTwo.m_hasVertex3 = true;

	b2BodyDef bottomBorderTwoDef;
	bottomBorderTwoDef.type=b2_staticBody;
	bottomBorderTwoDef.position.Set(pos.x, pos.y);
	b2Body *bottomBorderTwoBody = world->CreateBody(&bottomBorderTwoDef);
	b2FixtureDef bottomBorderTwoFixture;
	bottomBorderTwoFixture.shape = &bottomBorderTwo;
	bottomBorderTwoFixture.density = 1.f;
	bottomBorderTwoFixture.friction = friction;
	bottomBorderTwoBody->CreateFixture(&bottomBorderTwoFixture);
	return bottomBorderTwoBody;
}
b2Body* EdgeGenerator::genSimpleEdge(b2Vec2 start, b2Vec2 end, b2Vec2 pos, int mask, int category){
	b2EdgeShape bottomBorderTwo;
	bottomBorderTwo.Set(start, end);
	//bottomBorderTwo.m_hasVertex0 = true;
	//bottomBorderTwo.m_hasVertex3 = true;

	b2BodyDef bottomBorderTwoDef;
	bottomBorderTwoDef.type=b2_staticBody;
	bottomBorderTwoDef.position.Set(pos.x, pos.y);
	b2Body *bottomBorderTwoBody = world->CreateBody(&bottomBorderTwoDef);
	b2FixtureDef bottomBorderTwoFixture;
	bottomBorderTwoFixture.shape = &bottomBorderTwo;
	bottomBorderTwoFixture.density = 1.f;
	bottomBorderTwoFixture.friction = friction;
	bottomBorderTwoFixture.filter.maskBits = mask;
	bottomBorderTwoFixture.filter.categoryBits = category;
	bottomBorderTwoBody->CreateFixture(&bottomBorderTwoFixture);
	return bottomBorderTwoBody;
}