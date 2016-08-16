#ifndef __INITIALIZESDL__
#define __INITIALIZESDL__

#include <SDL2/SDL.h>
#include <iostream>
#include <Box2D/Box2D.h>

class Initializer{
public:
	Initializer(){}
	~Initializer(){}
	SDL_Renderer *init_sdl();
	b2World *init_world();

	SDL_Window *window;
	SDL_Renderer *r;
protected:
private:
};

#endif