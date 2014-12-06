#pragma once
#include "Header.h"
#include "Map.h"

class Audio;
class Graphic;
class Physic;

class Context
{
private:
	Map map;
	Graphic* graphicEngine;
	Audio* audioEngine;
	Physic* physicEngine;
public:
	Context(void);
	~Context(void);
	bool init();
	bool launchGame();
	bool restart();
	bool quit();
};

