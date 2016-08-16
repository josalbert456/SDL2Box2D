/*#include "MyBox.h"
b2Body *circle;
b2Body *box;
class TemplateEventHandler : public EventCalls{
	void *keyDown(SDL_Event event){
		switch(event.key.keysym.sym){	
			case 'q': isRunning = false;break;	
			case 'a': circle->SetLinearVelocity(b2Vec2(2, 0));break;
		}
	}
	void *keyUp(SDL_Event event){
		std::cout << "Key Up" << std::endl;
		switch(event.key.keysym.sym){
		}
	}
	void *mouseDown(SDL_Event event){
	}
	void *mouseUp(SDL_Event event){
	}
	void *mouseMove(SDL_Event event){
	}
};
int main(int argc, char **argv){
	Initializer init;
	SDL_Renderer *render = init.init_sdl();
	Canvas canvas(render);
	EventHandler eh;
	TemplateEventHandler ceh;
	Controller ctrl;
	b2World *bw = new b2World(b2Vec2(0.f, 10.f));
	WorldUpdater wu(bw);
	BodyGenerator bg(bw);
	EdgeGenerator eg(bw);
	b2Body *borders[3];
	borders[0] = eg.genSimpleEdge(b2Vec2(0.5, 0.5), b2Vec2(0.5, 12), b2Vec2(0, 0));
	borders[1] = eg.genSimpleEdge(b2Vec2(0.5, 12), b2Vec2(27.5, 12), b2Vec2(0, 0));
	borders[2] = eg.genSimpleEdge(b2Vec2(0.5, 0.5), b2Vec2(7.5, 0.5), b2Vec2(0, 0));
	circle = bg.genCircle(b2Vec2(1, 1), 0.2, 0.2, 0.2);
	Camera camera(circle);
	for(int i=0; i<3; i++){
		camera.addBody(borders[i]);
	}
	camera.addBody(circle);
	while(isRunning){
		camera.setCamera();
		wu.update();
		canvas.setColor(42, 30, 40, 255);
		canvas.clearCanvas();
		canvas.setColor(0, 100, 255, 255);
		for(int i=0; i<3; i++){
			canvas.drawBody(borders[i]);
		}
		canvas.setColor(255, 255, 255, 255);
		canvas.drawBody(circle);
		canvas.show();
		eh.eventHandler(&ceh);
		ctrl.delay(200);
	}
}*/