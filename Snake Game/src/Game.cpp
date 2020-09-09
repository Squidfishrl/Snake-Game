#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"

SDL_Rect srcRect, destRect;

GameObject* snakeHead;
GameObject* apple;


Game::Game(){

}

Game::~Game(){

}

void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen){
	int flags = 0;
	if(fullscreen){
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if(SDL_Init(SDL_INIT_VIDEO) == 0){
		printf("Initialized SDL subsystems \n");
		window = SDL_CreateWindow(title, x, y, width, height, flags);
		if (window) {
			printf("SDL window created \n");
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if(renderer){
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			printf("SDL renderer created \n");
		}
		isRunning = true;

		apple = new GameObject("assets/apple.png", renderer, 60, 60);
		snakeHead = new GameObject("assets/snake_head.png", renderer, 900, 1000);



	}else{
		printf("SDL Initialization error: %s \n", SDL_GetError());
		isRunning = false;
	}

}

void Game::handleEvents(){
	SDL_Event event;
	SDL_PollEvent(&event);

	switch(event.type){
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym){
				case SDLK_UP: case SDLK_w:
					snakeHead->direction = 'u';
					snakeHead->angle = 0;
					break;
				case SDLK_DOWN: case SDLK_s:
					snakeHead->direction = 'd';
					snakeHead->angle = 180;
					break;
				case SDLK_LEFT: case SDLK_a:
					snakeHead->direction = 'l';
					snakeHead->angle = 270;
					break;
				case SDLK_RIGHT: case SDLK_d:
					snakeHead->direction = 'r';
					snakeHead->angle = 90;
					break;
			}
	}
}

void Game::update(){
	snakeHead->UpdateSnake(1);
	apple->UpdateApple();

}

void Game::render(){
	SDL_RenderClear(renderer);

	snakeHead->Render();
	apple->Render();

	SDL_RenderPresent(renderer);

}

void Game::close(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	printf("Game closed \n");

}
