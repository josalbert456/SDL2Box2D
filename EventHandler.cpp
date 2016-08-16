#include "EventHandler.h"


void EventHandler::eventHandler(EventCalls *eCalls){
	if(eCalls!=NULL){
		eventCalls = eCalls;		
	} 
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_KEYUP:
				eventCalls->keyUp(event);
				break;
			case SDL_KEYDOWN:
				eventCalls->keyDown(event);
				break;
			case SDL_MOUSEBUTTONDOWN:
				eventCalls->mouseDown(event);
				break;
			case SDL_MOUSEBUTTONUP:
				eventCalls->mouseUp(event);break;
			case SDL_MOUSEMOTION:
				eventCalls->mouseMove(event);break;
		}
	}
}