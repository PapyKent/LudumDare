#pragma once
#include "engine.h"
#include "Header.h"

class Audio :
	public Engine
{
private:
	string ambiant;
	vector <string> soundEffect;
public:
	Audio(void);
	~Audio(void);
};

