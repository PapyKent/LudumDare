#pragma once
#include "Header.h"
class Entity
{
private:
	string nameEntity;
	int entitySpeed;
	int entityOrientation;
	int hp;
	string frame;
	int wantToMoveTo;
	SDL_Texture* sprite;

	int posX;
	int posY;
public:
	Entity(void);
	Entity(string nameEntity, int entitySpeed, int orientation,
		int hp, string entitySprite, int frame,SDL_Renderer* gRenderer);

	~Entity(void);

	void setNameEntity(string n){nameEntity=n;}
	void setEntitySpeed(int e){entitySpeed=e;}
	void setEntityOrientation(int e){entityOrientation=e;}
	void setHp(int h){hp=h;}
	void setFrame(string f){frame=f;}
	void setWantToMove(int w){wantToMoveTo=w;}
	void setPosX(int p){posX=p;}
	void setPosY(int p){posY=p;}


	string getNameEntity()	{return nameEntity;}
	int getEntitySpeed()	{return entitySpeed;}
	int getEntityOrientation()	{return entityOrientation;}
	int getHp()	{return hp;}
	string getFrame()	{return frame;}
	int getWantToMove()	{return wantToMoveTo;}
	int getPosX(){return posX;}
	int getPosY(){return posY;}

	 void move();
};

