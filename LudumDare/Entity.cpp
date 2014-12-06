#include "Entity.h"


Entity::Entity(void)
{
}

Entity::Entity( string nameEntity,  int entitySpeed,  int orientation,
		int  hp,string entitySprite, int frame){

			this->nameEntity = nameEntity;
			this->entitySpeed =  entitySpeed;
			this->entityOrientation =orientation;
			this->hp = hp;
			SDL_Surface* loadedSurface = SDL_LoadBMP(entitySprite.c_str());
			sprite = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );

			SDL_FreeSurface( loadedSurface );
}

Entity::~Entity(void)
{
	SDL_DestroyTexture(sprite);
}
