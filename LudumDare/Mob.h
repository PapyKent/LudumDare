#pragma once
#include "entity.h"

class Mob :
	public Entity
{
public:
	Mob(void);
	Mob(string nameEntity, int entitySpeed, int orientation,
		int hp, string entitySprite, int frame);
	~Mob(void);
};

