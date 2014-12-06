#pragma once
#include "Header.h"
class Entity;
class Item;


class Map	
{
private:

	char tableau [24][32];
	
	int level;
	vector <Entity> tableEntities;
	vector <Item> tableItems;
	
public:
	Map(void);
	Map(int level );
	~Map(void);

	Entity getEntity(int index);
	Entity getEntity(string nom);
	
	void addEntity(Entity c);
	void removeEntity(string nom);
	void removeEntity(int index);

	void addItem(Item i);
	void removeItem(string nom);
	void removeItem(int index);

	int getLevel(){return level;}
	void setLevel(int l){level=l;}

	void testAffiche();
	void chargerTableau(string nomFichier);


};

