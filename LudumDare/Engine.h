#pragma once
#include "Header.h"
#include "Graphic.h"
#include "Audio.h"
#include "Physic.h"

class Engine
{
private:
	Graphic graphicEngine;
	Audio audioEngine;
	Physic physicEngine;
public:
	Engine(void);
	~Engine(void);
};

