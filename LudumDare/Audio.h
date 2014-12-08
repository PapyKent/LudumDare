#pragma once
#include "Header.h"

class Audio{
private:
	Mix_Music* ambiant;
	Mix_Chunk *gunEffect ;
	Mix_Chunk *menu ;
	Mix_Chunk *gameOver ;
	Mix_Chunk *win ;

public:
	Audio(void);
	~Audio(void);
	int playGunEffect(void);
	int playWinEffect(void);
	int playGameOverEffect(void);

	int playMenu(void);

	void start(int);
};

