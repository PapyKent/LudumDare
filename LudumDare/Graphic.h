#pragma once
#include "Header.h"


class Map;
class Entity;

class Graphic
{
	SDL_Renderer* gRenderer;
	SDL_Window* window;
	SDL_Rect clip[ 12 ];
	SDL_Texture *bg;

public:
	Graphic(SDL_Window* window, SDL_Renderer* gRenderer);
	~Graphic(void);

	void displayBackground(Map map);
	void displayEntities(vector<Entity>);
	void refresh();
	void display(SDL_Texture* mTexture, int x, int y, int frame);
	void render(SDL_Texture*, int x, int y, SDL_Rect* clip );
	void SDL_RenderDrawRect();
};

