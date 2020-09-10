#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"


GameObject* snakeHead;
GameObject* apple;
GameObject* snakeBody[1000];



Game::Game(){

	isRunning = NULL;
	snakeLength = 0;

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



		apple = new GameObject("assets/apple.png", renderer, 900, 900, 0);
		snakeHead = new GameObject("assets/snake_head.png", renderer, 900, 1000, 20);
		snakeHead->direction='u';




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

	for (int i = 2; i < snakeLength; i++) {//end game if snake collides with itself. the first bodypart is always collided with the head and the 2nd one gets collided after a turn
			if(snakeHead->CollisionCheck(snakeBody[i])){
			printf("collision with %d \n", i);

			}
		}

	if(snakeLength>0){ // ,snake body to follow head
		for(int i = snakeLength; i>1; i--){
			snakeBody[i-1]->UpdateBody(snakeBody[i-2]);
		}
		snakeBody[0]->UpdateBody(snakeHead);
	}


	snakeHead->UpdateSnake(); //snake head movement

	// check if snake is going out of screen and tp it to other end of screen
	if(snakeHead->xpos<0)snakeHead->xpos=1800;
	else if(snakeHead->xpos>1800)snakeHead->xpos=0;
	else if(snakeHead->ypos<0)snakeHead->ypos=1000;
	else if(snakeHead->ypos>1000)snakeHead->ypos=0;
	snakeHead->TeleportSnake();




	if(snakeHead->CollisionCheck(apple)){
		apple->UpdateApple(); // increase snake body and move apple

		if(snakeLength == 0){
			snakeBody[snakeLength] = new GameObject("assets/snake_body.png", renderer, snakeHead->xpos, snakeHead->ypos-10, snakeHead->speed);
		}else{
			snakeBody[snakeLength] = new GameObject("assets/snake_body.png", renderer, snakeBody[snakeLength-1]->xpos, snakeBody[snakeLength-1]->ypos, snakeHead->speed);
		}

		snakeLength++;
	}









}

void Game::render(){
	SDL_RenderClear(renderer);

	snakeHead->Render();
	apple->Render();

	for(int i=0; i<snakeLength; i++){
		snakeBody[i]->Render();
	}


	SDL_RenderPresent(renderer);

}

void Game::close(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	printf("Game closed \n");

}

