#include "AABBCallback.h"

bool AABBCallback::ReportFixture(b2Fixture *fixture){
	b2Vec2 point = fixture->GetBody()->GetPosition();
	canvas->drawScaledLine(b2Vec2(0, 0), point);
	return true;
}
