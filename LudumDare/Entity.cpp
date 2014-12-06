#include "Entity.h"


Entity::Entity(void)
{
}

Entity::Entity( string nameEntity,  int entitySpeed,  int orientation,
			   int  hp,string entitySprite, int frame,SDL_Renderer* gRenderer){

				   this->nameEntity = nameEntity;
				   this->entitySpeed =  entitySpeed;
				   this->entityOrientation =orientation;
				   this->hp = hp;

				   SDL_Surface* loadedSurface = SDL_LoadBMP(entitySprite.c_str());
				   SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 255, 255 ) );

				   sprite = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );

				   SDL_FreeSurface( loadedSurface );
}

Entity::~Entity(void)
{
	SDL_DestroyTexture(sprite);
}
