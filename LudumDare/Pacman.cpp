#include "Pacman.h"


Pacman::Pacman(void)
{
}


Pacman::Pacman(string nameEntity, int entitySpeed, int orientation,
		int hp, string entitySprite, int frame)

		:Entity( nameEntity,  entitySpeed,  orientation,
		 hp, entitySprite,  frame){}


Pacman::~Pacman(void)
{
}
