#pragma once
#include "Header.h"

class Graphic;
class Audio;
class Physic;

class Engine
{
private:
	Graphic* graphicEngine;
	Audio* audioEngine;
	Physic* physicEngine;
public:
	Engine(void);
	~Engine(void);

	Graphic* getGraphic(){return graphicEngine;};
	Audio* getAudio(){return audioEngine;};
	Physic* getPhysic(){return physicEngine;};

};

