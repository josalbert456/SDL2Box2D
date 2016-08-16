#include "SteelChain.h"

void SteelChain::initialize(){
	BodyGenerator bg(world);
	head = bg.genCircle(startPos, 0.2, 0.2, 0.2);
	b2Body *bodies[unitsNum];
	for(int i=0; i<unitsNum; i++){
		bodies[i] = bg.genSimpleBox(b2Vec2(startPos.x + i * unitLength,
			startPos.y), b2Vec2(unitLength, unitHeight), 0.2, 0.9);
		chain.push_back(bodies[i]);
	}
	for(int i=0; i<unitsNum-1; i++){
		b2RevoluteJointDef rjd;
		rjd.bodyA = bodies[i];
		rjd.bodyB = bodies[i+1];
		rjd.localAnchorA.Set(unitLength - 0.005, 0);
		rjd.localAnchorB.Set(0.005 - unitLength, 0);
		world->CreateJoint(&rjd);
		b2RopeJointDef rope;
		rope.bodyA = bodies[i];
		rope.bodyB = bodies[i+1];
		rope.localAnchorA.Set(0, 0);
		rope.localAnchorB.Set(0, 0);
		rope.maxLength = unitLength * 2 + b2_linearSlop - 0.01;
		world->CreateJoint(&rope);
	}

	b2RevoluteJointDef rjd;
	rjd.bodyA = head;
	rjd.bodyB = bodies[0];
	rjd.localAnchorA.Set(0, 0);
	rjd.localAnchorB.Set(0.005 - unitLength, 0);
	world->CreateJoint(&rjd);

	b2RopeJointDef rope;
	rope.bodyA = bodies[0];
	rope.bodyB = head;
	rope.localAnchorA.Set(0, 0);
	rope.localAnchorB.Set(0, 0);
	rope.maxLength = 0.2 + unitLength - 0.01 + b2_linearSlop;
	world->CreateJoint(&rope);
}

void SteelChain::process(void drawCallback(b2Body *body)){
	list<b2Body *>::iterator chainIterator;
	for(chainIterator = chain.begin(); chainIterator != chain.end(); chainIterator++){
		drawCallback(*chainIterator);
	}
	drawCallback(head);
}
b2Body *SteelChain::getOneNode(int index){
	index -= 1;
	list<b2Body *>::iterator chainIterator = chain.begin();
	for(int i=0; i<index; chainIterator++, i++);
	return *chainIterator;
}
void SteelChain::addToCamera(Camera *camera){
	list<b2Body *>::iterator chainIterator;
	for(chainIterator = chain.begin(); chainIterator != chain.end(); chainIterator++){
		camera->addBody(*chainIterator);
	}
	camera->addBody(head);
}
b2Body* SteelChain::getHead(){
	return head;
}