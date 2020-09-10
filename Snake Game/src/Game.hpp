
#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <stdio.h>


class Game {

	public:
		Game();
		~Game();

		void init(const char* title, int x, int y, int width, int height, bool fullscreen);
		void handleEvents();
		bool update(); // returns if the game can continue or not
		void render();
		void close();

		bool running(){return isRunning;}


		struct scoreBoard{
			long int points;  // 100000*(snakeLength/(movesMade*secondsElapsed)
			int applesEaten = 0;
			int snakeLength = 0;
			int secondsElapsed;
			int movesMade = 0;
		};

		scoreBoard score;

	private:
		bool isRunning;
		SDL_Window *window = NULL;
		SDL_Renderer *renderer = NULL;
};

#endif
