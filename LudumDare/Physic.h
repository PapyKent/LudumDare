#pragma once
#include "engine.h"
#include "Header.h"

class Character;
class Map;

class Physic :
	public Engine
{
private:
	int* collisionMask;

public:
	Physic(void);
	Physic(Map);
	~Physic(void);

	bool canMove(Character);
};

