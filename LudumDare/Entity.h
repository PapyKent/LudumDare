#pragma once
#include "Header.h"
class Entity
{
private:
	string nameEntity;
	int entitySpeed;
	int entityOrientation;
	int hp;
	int frame;
	int wantToMoveTo;
	string loader;

	int posX;
	int posY;
public:
	Entity(void);
	Entity(string nameEntity, int entitySpeed, int orientation,
		int hp, string entitySprite, int frame);

	~Entity(void);

	void setNameEntity(string n){nameEntity=n;}
	void setEntitySpeed(int e){entitySpeed=e;}
	void setEntityOrientation(int e){entityOrientation=e;}
	void setHp(int h){hp=h;}
	void setFrame(int f){frame=f;}
	void setWantToMove(int w){wantToMoveTo=w;}
	void setPosX(int p){posX=p;}
	void setPosY(int p){posY=p;}


	string getNameEntity()	{return nameEntity;}
	string getLoader(){return loader;}
	int getEntitySpeed()	{return entitySpeed;}
	int getEntityOrientation()	{return entityOrientation;}
	int getHp()	{return hp;}
	int getFrame()	{return frame;}
	int getWantToMove()	{return wantToMoveTo;}
	int getPosX(){return posX;}
	int getPosY(){return posY;}

	bool takeDMG(int dmg);
	bool isDead();

};

