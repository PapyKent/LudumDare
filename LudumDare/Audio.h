#pragma once
#include "Header.h"

class Audio{
private:
	Mix_Music* ambiant;
	vector <string> soundEffect;
public:
	Audio(void);
	~Audio(void);
	void start(int);
};

