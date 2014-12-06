#pragma once
#include "Header.h"
#include "SDL_mixer.h"

class Audio
{
private:
	Mix_Music* ambiant;
	vector <string> soundEffect;
public:
	Audio(void);
	~Audio(void);
};

