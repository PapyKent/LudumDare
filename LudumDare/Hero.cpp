#include "Hero.h"
#include "Item.h"

Hero::Hero(void)
{
}


Hero::Hero(string nameEntity, int entitySpeed, int orientation,
		int hp, string entitySprite, int frame, SDL_Renderer* gRenderer)

		:Entity( nameEntity,  entitySpeed,  orientation,
		 hp, entitySprite,  frame, gRenderer){}

Hero::~Hero(void)
{
	delete itemHold;
}
