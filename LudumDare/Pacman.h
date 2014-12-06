#pragma once
#include "entity.h"
class Pacman :
	public Entity
{
public:
	Pacman(void);
	Pacman(string nameEntity, int entitySpeed, int orientation,
		int hp, string entitySprite, int frame);
	~Pacman(void);
};

