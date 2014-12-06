#pragma once
#include "Header.h"
class Entity;
class Item;


class Map	
{
private:
	int level;
	vector <Entity> tableEntities;
	vector <Item> tableItems;
	string directory;
public:
	Map(void);
	Map(string directory,int level =0);
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

	void setDirectory(string d){directory=d;}
	string getDirectory(){return directory;}


};

