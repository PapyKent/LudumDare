#include "Mob.h"


Mob::Mob(void)
{
}

Mob::Mob(string nameEntity, int entitySpeed, int orientation,
		int hp, string entitySprite, int frame)

		:Entity( nameEntity,  entitySpeed,  orientation,
		 hp, entitySprite,  frame){}

Mob::~Mob(void)
{
}
