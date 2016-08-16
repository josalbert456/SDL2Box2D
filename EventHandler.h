#ifndef __EVENTHANDLER__
#define __EVENTHANDLER__
#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>
#include <iostream>
#include "EventCalls.h"
class EventHandler{
public:
	EventHandler(){
		eventCalls = new EventCalls();
	}
	void eventHandler(EventCalls *eCalls);

protected:
private:
	EventCalls *eventCalls;
	SDL_Event event;	
};

#endif