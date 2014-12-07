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
				   loader=entitySprite;

}

Entity::~Entity(void){

}
