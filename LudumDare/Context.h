#pragma once
#include "Header.h"
#include "Map.h"

class Audio;
class Graphic;
class Physic;

class Context
{
private:


	SDL_Window* window;
	SDL_Renderer* gRenderer;
	Map* map;
	Graphic* graphicEngine;
	Audio* audioEngine;
	Physic* physicEngine;
public:
	Context(void);
	~Context(void);
	bool init();
	bool launchGame(int niveau);
	bool restart();
	bool quit();
	bool createRenderer();
	bool victory(int, int, int niveau);
	bool gameOver(int niveau);
	
};

