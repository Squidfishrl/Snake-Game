#include "Game.hpp"

class GameObject{

public:
	GameObject(const char* texture, SDL_Renderer* renderer, int xpos, int ypos, int spd);
	~GameObject();

	void UpdateSnake();
	void UpdateApple();
	void UpdateBody(GameObject* obj);
	void Render();
	bool CollisionCheck(GameObject* B);

	char direction;
	int angle;

	int xpos;
	int ypos;
	int width;
	int height;
	int speed;

private:


	SDL_Rect srcRect, destRect;

	SDL_Texture* objTexture;

	SDL_Renderer* renderer;

};


