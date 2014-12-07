#pragma once
#include "engine.h"
#include "Header.h"


class Map;

class Physic
{
private:

public:
	Physic(void);
	Physic(Map);
	~Physic(void);

	bool collision(int,int, int, int);
};

