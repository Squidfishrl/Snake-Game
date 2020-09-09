#include "Game.hpp"

class GameObject{

public:
	GameObject(const char* texture, SDL_Renderer* renderer, int xpos, int ypos);
	~GameObject();

	void UpdateSnake(int speed);
	void UpdateApple();
	void Render();

	char direction;
	int angle;

private:

	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;

};
