#include "GameObject.hpp"
#include "TextureManager.hpp"
#include <cstdlib>
#include <ctime>

using namespace std;


GameObject::GameObject(const char* texture, SDL_Renderer* rendrr, int startingX, int startingY){
	renderer = rendrr;
	objTexture = TextureManager::LoadTexture(texture, renderer);

	angle=0;
	direction = 'r';
	xpos = startingX;
	ypos = startingY;

	srcRect.h=20;
	srcRect.w=20;
	srcRect.x=0;
	srcRect.y=0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

void GameObject::UpdateSnake(int speed){
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

}

void GameObject::UpdateApple(){
	srand(time(0));

	destRect.x = (rand() % 600);
	destRect.y = (rand() % 800);
}

void GameObject::Render(){
	SDL_RenderCopyEx(renderer, objTexture, &srcRect, &destRect, angle, NULL, SDL_FLIP_NONE);
}
