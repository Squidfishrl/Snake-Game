
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
		void update();
		void render();
		void close();

		bool running(){return isRunning;}

		int snakeLength;

	private:
		bool isRunning;
		SDL_Window *window = NULL;
		SDL_Renderer *renderer = NULL;
};

#endif
