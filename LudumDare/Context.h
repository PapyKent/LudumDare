#pragma once
#include "Header.h"
#include "SDL.h"
#include "Map.h"
#include "Engine.h"

class Context
{
private:
	Map map;
	Engine engine;
	SDL_Window* window;
public:
	Context(void);
	~Context(void);
	bool init();
	bool launchGame();
	bool restart();
	bool quit();
};

