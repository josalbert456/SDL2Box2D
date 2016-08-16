#ifndef __STEELCHAIN__
#define __STEELCHAIN__
#include <list>
#include "BodyGenerator.h"
#include "Canvas.h"
#include "Camera.h"
using namespace std;
class SteelChain{
public:
	SteelChain(float ul, float uh, int un, b2Vec2 sp, b2World *w){
		unitLength = ul;
		unitHeight = uh;
		unitsNum = un;
		startPos = sp;
		world = w;
	}
	~SteelChain(){}
	void initialize();

	void process(void drawCallback(b2Body *body));
	list<b2Body*>chain;	
	b2Body *getOneNode(int index);
	b2Body *getHead();
	void addToCamera(Camera *camera);
protected:
private:
	float unitLength;
	float unitHeight;
	int unitsNum;
	b2Vec2 startPos;
	b2World *world;
	b2Body *head;
};

#endif