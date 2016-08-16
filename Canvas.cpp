#include "Canvas.h"

void Canvas::clearCanvas(){
	SDL_RenderClear(renderer);
}
void Canvas::setColor(int r, int g, int b, int alpha){
	SDL_SetRenderDrawColor(renderer, r, g, b, alpha);
}
void Canvas::drawPoint(float x, float y){
	SDL_RenderDrawPoint(renderer, x, y);
}
void Canvas::drawScaledPoint(float x, float y){	
	drawPoint(x * MKS_Pixel, y * MKS_Pixel);
}
void Canvas::drawLine(b2Vec2 start, b2Vec2 end){
	SDL_RenderDrawLine(renderer, start.x, start.y, end.x, end.y);
}
void Canvas::drawScaledLine(b2Vec2 start, b2Vec2 end){
	SDL_RenderDrawLine(renderer, start.x * MKS_Pixel, start.y * MKS_Pixel, 
		end.x * MKS_Pixel, end.y * MKS_Pixel);	
}
void Canvas::drawRect(b2Vec2 topLeft, b2Vec2 bottomRight, bool filled){
	SDL_Rect rect = {topLeft.x, topLeft.y, bottomRight.x, bottomRight.y};
	if(filled){
		SDL_RenderFillRect(renderer, &rect);
	}else{
		SDL_RenderDrawRect(renderer, &rect);
	}
}
void Canvas::drawScaledRect(b2Vec2 topLeft, b2Vec2 bottomRight, bool filled){
	SDL_Rect rect = {topLeft.x * MKS_Pixel, topLeft.y * MKS_Pixel, 
		(bottomRight.x -topLeft.x)* MKS_Pixel, (bottomRight.y -topLeft.y)* MKS_Pixel};
	if(filled){
		SDL_RenderFillRect(renderer, &rect);
	}else{
		SDL_RenderDrawRect(renderer, &rect);
	}
}
void Canvas::drawEdge(b2EdgeShape *edge, b2Body *body){
	b2Vec2 vertex1 = body->GetWorldPoint(edge->m_vertex1);
	b2Vec2 vertex2 = body->GetWorldPoint(edge->m_vertex2);
	drawScaledLine(vertex1, vertex2);
}
int Canvas::getTopLeftPoint(b2PolygonShape *polygon){
	int index;
	for(int i=0; i<polygon->m_count; i++){
		
	}
}
void Canvas::drawPolygon(b2PolygonShape *polygon, b2Body *body, bool filled){
	b2Vec2 worldPoints[polygon->m_count];
	for(int i=0; i<polygon->m_count; i++){
		worldPoints[i] = body->GetWorldPoint(polygon->m_vertices[i]);
	}			
	for(int i=0; i<polygon->m_count-1; i++){
		drawScaledLine(worldPoints[i], worldPoints[i+1]);
	}
	drawScaledLine(worldPoints[polygon->m_count-1], worldPoints[0]);
}
void Canvas::show(){
	SDL_RenderPresent(renderer);
}
void Canvas::drawChain(b2ChainShape *chain, b2Body *body){
	int counter = chain->m_count;
	b2Vec2 worldPoints[counter];
	for(int i=0; i<counter; i++){
		worldPoints[i] = body->GetWorldPoint(chain->m_vertices[i]);
	}
	for(int i=0; i<counter-1; i++){
		drawScaledLine(worldPoints[i], worldPoints[i+1]);
	}
	drawScaledLine(worldPoints[counter-1], worldPoints[0]);
}
void Canvas::drawBody(b2Body *body){
	for(b2Fixture *f = body->GetFixtureList(); f; f=f->GetNext()){
		switch(f->GetType()){
			case 0: drawCircle((b2CircleShape *)(f->GetShape()), body, false); break;
			case 1: drawEdge((b2EdgeShape*)(f->GetShape()), body); break;
			case 2: drawPolygon((b2PolygonShape *)(f->GetShape()), body, false); break;
			case 3: drawChain((b2ChainShape *)(f->GetShape()), body); break;
		}
	}
}
void Canvas::drawCircle(b2CircleShape *cirlce, b2Body *body, bool filled){
	float xPos = body->GetWorldPoint(cirlce->m_p).x * MKS_Pixel;
	float yPos = body->GetWorldPoint(cirlce->m_p).y * MKS_Pixel;
	float r = cirlce->m_radius * MKS_Pixel;
	float centerX = cirlce->m_p.x * MKS_Pixel;
	float centerY = cirlce->m_p.y * MKS_Pixel;
	float unit = M_PI / (2 * r);
	for(int i=0; i<r*4; i++){
		float curX = r * cos (i * unit)  + xPos + centerX;
		float curY = r * sin (i * unit)  + yPos + centerY;
		drawPoint(curX, curY);
	}
}
float Canvas::calcDistance(b2Vec2 point1, b2Vec2 point2){
	return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}
b2Vec2 Canvas::rotatePoint(b2Vec2 center, b2Vec2 point, float angle){
	b2Vec2 result;
	float radius = calcDistance(center, point);
	float curAngle = acos((point.x - center.x)/radius);

	if(center.y >= point.y){
		curAngle += angle * DEGTORAD;
		float incX = cos(curAngle) * radius + center.x;
		float incY = center.y - sin(curAngle) * radius;
		result.Set(incX, incY);			
	}else{
		curAngle = M_PI - curAngle;
		curAngle += angle * DEGTORAD;
		float incX = center.x - cos(curAngle) * radius;
		float incY = center.y + sin(curAngle) * radius;
		result.Set(incX, incY);
	}
	return result;
}
b2PolygonShape* Canvas::rotatePolygon(b2PolygonShape *polygon, b2Vec2 center, float angle){
	b2Vec2 result;
	b2PolygonShape *poly = new b2PolygonShape();
	b2Vec2 tmp[polygon->m_count];
	//tmp[0].Set(polygon->m_vertices[0].x, polygon->m_vertices[0].y);
	
	for(int i=0; i<polygon->m_count; i++){
		result = rotatePoint(center, polygon->m_vertices[i], angle);		
		tmp[i].Set(result.x, result.y);
	}
	poly->Set(tmp, polygon->m_count);
	
	return poly;
}


void Canvas::load_texture(std::string path){
	SDL_Surface *loadSurface = IMG_Load(path.c_str());
	if(loadSurface==NULL){
		std::cout << "Unable to load image" << path.c_str()
		<< IMG_GetError() << std::endl;
	}else{
		texture = SDL_CreateTextureFromSurface(renderer, loadSurface);
		if(texture==NULL){
			std::cout << "Unable to create texture" << path.c_str() 
			<< SDL_GetError() << std::endl;
			SDL_FreeSurface(loadSurface);
		}
	}
}
void Canvas::drawTexture(std::string path, b2Body *body, b2PolygonShape *polygon){
	SDL_Rect rect = {0, 0, 100, 100};
	load_texture(path);
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}


void Canvas::drawMassCenter(b2Body *body){
	b2MassData md;
	body->GetMassData(&md);
	b2Vec2 pos = body->GetWorldPoint(md.center);
	drawScaledPoint(pos.x, pos.y);
}

void Canvas::drawAABB(b2Body *body){
	for(b2Fixture *f = body->GetFixtureList(); f; f=f->GetNext()){
		b2AABB boxAABB;
		b2Shape *s = f->GetShape();
		s->ComputeAABB(&boxAABB, body->GetTransform(), 0);
		drawScaledRect(boxAABB.lowerBound, boxAABB.upperBound, false);
	}	
}