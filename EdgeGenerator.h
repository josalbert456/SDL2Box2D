#ifndef __EDGEGENERATOR__
#define __EDGEGENERATOR__
#include <Box2D/Box2D.h>
class EdgeGenerator{
public:
	EdgeGenerator(b2World *w){
		world = w;
		friction = 0.3f;
	}
	EdgeGenerator(b2World *w, float frict){
		world = w;
		friction = frict;

	}
	~EdgeGenerator(){}
	b2Body* genSimpleEdge(b2Vec2 start, b2Vec2 end, b2Vec2 pos);
	b2Body* genSimpleEdge(b2Vec2 start, b2Vec2 end, b2Vec2 pos, int mask, int category);
private:
	b2World *world;	
	float friction;
};

#endif