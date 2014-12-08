#pragma once
#include "Header.h"


class Map;
class Entity;

class Graphic
{
	SDL_Renderer* gRenderer;
	SDL_Window* window;
	SDL_Rect clip[ 18 ];
	SDL_Texture *bg;
	SDL_Texture *pan;
	SDL_Texture *pacman;
	SDL_Texture *junior;
	SDL_Texture *ghost;
	SDL_Texture* sortie;
	int frame;

public:
	Graphic(SDL_Window* window, SDL_Renderer* gRenderer);
	~Graphic(void);

	void displayBackground(Map map, int niveau);
	bool displayEntities(vector<Entity>, bool);
	void refresh();
	void display(SDL_Texture* mTexture, int x, int y, int frame);
	void render(SDL_Texture*, int x, int y, SDL_Rect* clip );
	void SDL_RenderDrawRect();
	void displayAttack(int orientation);
};

