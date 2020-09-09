#include "Game.hpp"

class GameObject{

public:
	GameObject(const char* texture, SDL_Renderer* renderer, int xpos, int ypos);
	~GameObject();

	void UpdateSnake(int speed);
	void UpdateApple();
	void Render();
	bool CollisionCheck(GameObject* B);

	char direction;
	int angle;

	SDL_Rect srcRect, destRect;
protected:

	int xpos;
	int ypos;

	SDL_Texture* objTexture;

	SDL_Renderer* renderer;

};


