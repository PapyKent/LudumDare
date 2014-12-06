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
		int hp, string entitySprite, int frame);
	~Hero(void);
};

