#ifndef __EVENTCALLS__
#define __EVENTCALLS__
#include <SDL2/SDL.h>
class EventCalls{
public:
	EventCalls(){}
	~EventCalls(){}
	virtual void *keyDown(SDL_Event event){
		std::cout << "Key Down" << std::endl;
	}
	virtual void *keyUp(SDL_Event event){
		std::cout << "Key Up" << std::endl;
		switch(event.key.keysym.sym){
			case 'q':exit(0);break;
		}
	}
	virtual void *mouseDown(SDL_Event event){
		std::cout << "Mouse Down" << std::endl;
	}
	virtual void *mouseUp(SDL_Event event){
		std::cout << "Mouse Up" << std::endl;
	}
	virtual void *mouseMove(SDL_Event event){
		std::cout << "Mouse Move" << std::endl;
	}
};

#endif