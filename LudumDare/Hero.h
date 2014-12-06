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
	~Hero(void);
};

