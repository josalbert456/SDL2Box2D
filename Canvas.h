#ifndef __CANVAS__
#define __CANVAS__
#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>
#include <iostream>
#include <SDL2/SDL_image.h>

#include <math.h>

const int MKS_Pixel	= 50;
const double  DEGTORAD = 0.0174532925199432957;
const double  RADTODEG = 57.295779513082320876;
class Canvas{
public:
	Canvas(SDL_Renderer *r){
		renderer = r;
	}
	~Canvas(){}
	void clearCanvas();
	void setColor(int r, int g, int b, int alpha);	
	void drawScaledPoint(float x, float y);
	void drawLine(b2Vec2 start, b2Vec2 end);
	void drawRect(b2Vec2 topLeft, b2Vec2 bottomRight, bool filled);
	void drawPolygon(b2PolygonShape *polygon, b2Body* body, bool filled);
	void drawBody(b2Body *body);
	void drawEdge(b2EdgeShape *edge, b2Body *body);
	void drawCircle(b2CircleShape *circle, b2Body *body, bool filled);
	void drawScaledLine(b2Vec2 start, b2Vec2 end);
	void drawChain(b2ChainShape *chain, b2Body *body);
	void show();

	float calcDistance(b2Vec2 point1, b2Vec2 point2);
	b2Vec2 rotatePoint(b2Vec2 center, b2Vec2 point, float angle);
	b2PolygonShape* rotatePolygon(b2PolygonShape *polygon, b2Vec2 center, float angle);
	void rotateBody(b2Body *body);

	void drawPoint(float x, float y);

	void load_texture(std::string path);
	void drawTexture(std::string path, b2Body *body, b2PolygonShape *polygon);

	int getTopLeftPoint(b2PolygonShape *polygon);

	void drawScaledRect(b2Vec2 topLeft, b2Vec2 bottomRight, bool filled);
	void drawMassCenter(b2Body *body);
	void drawAABB(b2Body *body);
protected:
private:
	SDL_Renderer *renderer;
	SDL_Texture *texture;
};

#endif