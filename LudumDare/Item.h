#pragma once
#include "Header.h"


class Item
{
private:
	string nameItem;
	string spriteItem;
	int rangeItem;
	int damageItem;
public:
	Item(void);
	Item(string nameItem, string spriteItem,int rangeItem,int damageItem);
	~Item(void);

	string getnameItem(){return nameItem;}
	string getSpriteItem(){return spriteItem;}
	int getRangeItem(){return rangeItem;}
	int getDamageItem(){return damageItem;}

	void setnameItem(string n){nameItem=n;}
	void setSpriteItem(string s){spriteItem=s;}
	void setRangeItem(int r){rangeItem=r;}
	void setDamageItem(int d){damageItem=d;}
};

