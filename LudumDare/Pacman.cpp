#include "Pacman.h"


Pacman::Pacman(void)
{
}


Pacman::Pacman(string nameEntity, int entitySpeed, int orientation,
		int hp, string entitySprite, int frame, SDL_Renderer* gRenderer)

		:Entity( nameEntity,  entitySpeed,  orientation,
		 hp, entitySprite,  frame, gRenderer){}


Pacman::~Pacman(void)
{
}
