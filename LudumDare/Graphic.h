#pragma once
#include "Header.h"

class Entity;

class Graphic
{
	SDL_Rect clip[ 6 ];
	SDL_Texture* bg;

public:
	Graphic(void);
	~Graphic(void);

	void display();
	void displayBackground(char**);
	void displayEntities(vector<Entity>);

};

