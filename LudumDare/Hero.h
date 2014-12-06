#pragma once
#include "entity.h"

class Item;
class Hero :
	public Entity
{
private:
	Item *itemHold;
public:
	Hero(void);
	Hero(string nameEntity, int entitySpeed, int orientation,
		int hp, string entitySprite, int frame, SDL_Renderer* gRenderer);
	~Hero(void);
};

