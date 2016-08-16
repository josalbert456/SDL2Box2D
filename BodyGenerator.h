#ifndef __BODYGENERATOR__
#define __BODYGENERATOR__
#include <Box2D/Box2D.h>

class BodyGenerator{
public:
	BodyGenerator(b2World *w){
		world = w;
	}
	~BodyGenerator(){}
	b2Body* genBody(float x, float y, float friction, float restitution);
	b2Body *genSimpleBox(b2Vec2 pos, b2Vec2 size, float friction, float restitution);
	b2Body *genPolygonBody(b2PolygonShape *polygonShape, b2Vec2 pos, float friction, 
	float restitution);
	b2Body *genPolygonBody(b2PolygonShape *polygonShape, b2Vec2 pos, float friction, 
	float restitution, void *userData);	
	// category "I am a..."
	// mask: "I will collide with ..."
	//  The important point is that these conditions must 
	// be satisfied for both fixtures in order for collision to be allowed.
	b2Body* genCircle(b2Vec2 pos, float radius, float friction, float restitution, 
		float category, float mask);
	b2Body* genCircle(b2Vec2 pos, float radius, float friction, float restitution);
protected:
private:
	b2World *world;
};

#endif