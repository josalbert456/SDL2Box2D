#include "Initializer.h"

SDL_Renderer *Initializer::init_sdl(){
	SDL_Renderer *renderer;
	if(SDL_Init(SDL_INIT_EVERYTHING)==0){
		std::cout << "SDL Init success\n";
		window = SDL_CreateWindow("Lab", 120, 100, 400, 640, 0);
		if(window!=0){
			std::cout << "window creation success\n";
			renderer = SDL_CreateRenderer(window, -1, 0);
			r = renderer;
			if(renderer !=0){
				std::cout << "renderer creation success\n";
			}else{
				std::cout << "renderer init fail\n";
				return renderer;
			}
			
		}else{
			std::cout << "window init fail\n";
			return renderer;
		}
	}else{
		std::cout << "SDL init fail\n";
		return renderer;
	}
	return renderer;
}
