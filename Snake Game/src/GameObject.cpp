#include "GameObject.hpp"
#include "TextureManager.hpp"
#include <random>
using namespace std;


GameObject::GameObject(const char* texture, SDL_Renderer* rendrr, int startingX, int startingY, int spd){
	renderer = rendrr;
	objTexture = TextureManager::LoadTexture(texture, renderer);

	angle=0;
	direction = NULL;
	xpos = startingX;
	ypos = startingY;

	width = 20;
	height = 20;

	srcRect.h=width;
	srcRect.w=height;
	srcRect.x=0;
	srcRect.y=0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

	speed=spd;

}

void GameObject::UpdateSnake(){

	switch (direction) {
		case 'u':
			destRect.y-=speed;
			break;
		case 'd':
			destRect.y+=speed;
			break;
		case 'l':
			destRect.x-=speed;
			break;

		case 'r':
			destRect.x+=speed;
			break;
	}

	xpos=destRect.x;
	ypos=destRect.y;

}

void GameObject::TeleportSnake(){
	destRect.x = xpos;
	destRect.y = ypos;
}

void GameObject::UpdateApple(){
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(0, 1800);
	destRect.x = distr(gen);

	destRect.y = distr(gen);
	if(destRect.y>1000)destRect.y-=800;
}

void GameObject::UpdateBody(GameObject* obj){


	xpos = obj->xpos;
	ypos = obj->ypos;


//	switch (obj->direction) {
//		case 'd':
//			ypos-=;
//			break;
//
//		case 'u':
//			ypos+=height;
//			break;
//
//		case 'l':
//			xpos+=width;
//			break;
//
//		case 'r':
//			xpos-=width;
//			break;
//
//
//	}

	destRect.x = xpos;
	destRect.y = ypos;
}


void GameObject::Render(){
	SDL_RenderCopyEx(renderer, objTexture, &srcRect, &destRect, angle, NULL, SDL_FLIP_NONE);
}

bool GameObject::CollisionCheck(GameObject* B){


	int left1=destRect.x;
	int right1=destRect.x + destRect.w;
	int top1=destRect.y;
	int bottom1=destRect.y + destRect.h;

	int left2=B->destRect.x;
	int right2=B->destRect.x + B->destRect.w;
	int top2=B->destRect.y;
	int bottom2=B->destRect.y + B->destRect.h;

	if(left1 > right2 || left2 > right1 || top1>bottom2 || top2>bottom1){
		return false;
	}else{
		return true;
	}

}



