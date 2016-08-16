#ifndef __CAMERA__
#define __CAMERA__
#include <list>
#include <Box2D/Box2D.h>

using namespace std;
class Camera{
public:
	Camera(b2Body *center){
		cameraCenterBody = center;
		prevPos.Set(center->GetPosition().x, center->GetPosition().y);
	}
	~Camera(){}
	void setCamera();
	void addBody(b2Body *body);
	list<b2Body *> bodies;
	b2Body *cameraCenterBody;
	b2Vec2 prevPos;
};

#endif