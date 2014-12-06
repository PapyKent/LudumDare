#include "Mob.h"


Mob::Mob(void)
{
}

Mob::Mob(string nameEntity, int entitySpeed, int orientation,
		int hp, string entitySprite, int frame, SDL_Renderer* gRenderer)

		:Entity( nameEntity,  entitySpeed,  orientation,
		 hp, entitySprite,  frame, gRenderer){}

Mob::~Mob(void)
{
}
