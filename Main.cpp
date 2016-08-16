#include "Main.h"
b2Body *box1;
class TemplateEventHandler : public EventCalls{
	void *keyDown(SDL_Event event){
		switch(event.key.keysym.sym){	
			case 'q': isRunning = false;break;	
			case 'a': box->ApplyForce(b2Vec2(0, -6), box->GetPosition(), true);break;				
			case 'r': box->ApplyForce(b2Vec2(-6, 0), box->GetPosition(), true);break;
			case 'l': box->ApplyForce(b2Vec2(6, 0), box->GetPosition(), true);break;
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

void drawCallback(b2Body *body){
	canvas->drawBody(body);
}
int main(int argc, char **argv){
	Initializer init;
	SDL_Renderer *render = init.init_sdl();
	canvas = new Canvas(render);
	EventHandler eh;
	TemplateEventHandler ceh;
	Controller ctrl;
	b2World *bw = new b2World(b2Vec2(0.f, 10.f));
	WorldUpdater wu(bw);
	BodyGenerator bg(bw);
	EdgeGenerator eg(bw);
	b2Body *borders[7];
	borders[0] = eg.genSimpleEdge(b2Vec2(0.5, 0.5), b2Vec2(0.5, 12), b2Vec2(0, 0));
	borders[1] = eg.genSimpleEdge(b2Vec2(0.5, 12), b2Vec2(37.5, 12), b2Vec2(0, 0));
	borders[2] = eg.genSimpleEdge(b2Vec2(0.5, 0.5), b2Vec2(7.5, 0.5), b2Vec2(0, 0));
	borders[3] = eg.genSimpleEdge(b2Vec2(7.5, 0.5), b2Vec2(7.5, 0.6), b2Vec2(0, 0));
	borders[4] = eg.genSimpleEdge(b2Vec2(37.5, 12), b2Vec2(46, 11), b2Vec2(0, 0));
	borders[5] = eg.genSimpleEdge(b2Vec2(46, 11), b2Vec2(60, 12), b2Vec2(0, 0));
	borders[6] = eg.genSimpleEdge(b2Vec2(60, 12), b2Vec2(70, 12), b2Vec2(0, 0));

	SteelChain chainOne(0.05, 0.02, 80, b2Vec2(4, 1), bw);
	chainOne.initialize();
	
	box = chainOne.getHead();
	box1 = chainOne.getOneNode(30);

	Camera camera(box);
	for(int i=0; i<7; i++){
		camera.addBody(borders[i]);
	}
	chainOne.addToCamera(&camera);

	b2Body *edge = eg.genSimpleEdge(b2Vec2(7.5, 11), b2Vec2(8.5, 10.5), b2Vec2(0, 0));
	b2Body *edge1 = eg.genSimpleEdge(b2Vec2(8.5, 10.5), b2Vec2(9.5, 10.5), b2Vec2(0, 0));
	b2Body *edge2 = eg.genSimpleEdge(b2Vec2(9.5, 10.5), b2Vec2(9.5, 11), b2Vec2(0, 0));
	//b2Body *edge3 = eg.genSimpleEdge(b2Vec2(7.5, 10), b2Vec2(7.5, 9), b2Vec2(0, 0));
	camera.addBody(edge);
	camera.addBody(edge1);
	camera.addBody(edge2);
	//camera.addBody(edge3);
	while(isRunning){
		camera.setCamera();
		wu.update();
		canvas->setColor(42, 30, 40, 255);
		canvas->clearCanvas();
		canvas->setColor(0, 100, 255, 255);
		for(int i=0; i<7; i++){
			canvas->drawBody(borders[i]);
		}
		canvas->setColor(255, 255, 255, 255);
		chainOne.process(drawCallback);
		canvas->drawBody(edge);
		canvas->drawBody(edge1);
		canvas->drawBody(edge2);
		//canvas->drawBody(edge3);
		canvas->show();
		eh.eventHandler(&ceh);
		ctrl.delay(200);
	}
}