#pragma once
#include "Header.h"
class Entity
{
private:
	string nameEntity;
	int entitySpeed;
	int entityOrientation;
	int hp;
	string entitySprite;
	string frame;
	int wantToMoveTo;
public:
	Entity(void);
	Entity(string nameEntity, int entitySpeed, int orientation,
		int hp, string entitySprite, int frame=0);

	~Entity(void);

	void setNameEntity(string n){nameEntity=n;}
	void setEntitySpeed(int e){entitySpeed=e;}
	void setEntityOrientation(int e){entityOrientation=e;}
	void setHp(int h){hp=h;}
	void setEntitySprite(string e){entitySprite=e;}
	void setFrame(string f){frame=f;}
	void setWantToMove(int w){wantToMoveTo=w;}


	string getNameEntity()	{return nameEntity;}
	int getEntitySpeed()	{return entitySpeed;}
	int getEntityOrientation()	{return entityOrientation;}
	int getHp()	{return hp;}
	string getEntitySprite()	{return entitySprite;}
	string getFrame()	{return frame;}
	int getWantToMove()	{return wantToMoveTo;}
};

