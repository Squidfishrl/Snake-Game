#include "Game.hpp"

Game *game = nullptr;

int main(int argc, char **argv) {
	const int FPS = 60;
	const int frameDelay = 1000/FPS;

	Uint32 frameStart;
	int frameTime;

	gameStartLabel:

	game = new Game();

	game->init("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1800, 1000, false);
	while(game->running()){

		frameStart = SDL_GetTicks();

		game->handleEvents();
		if(!game->update()){

			game->score.points=1000*(game->score.snakeLength/(game->score.movesMade));
			printf("score - %ld \n", game->score.points);
			break;
		}


		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if(frameDelay>frameTime){
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->close();

	// show score on screen
	// try again option
	goto gameStartLabel;
	return 0;
}
