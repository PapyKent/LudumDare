#pragma once
#include "Header.h"
#include "Entity.h"
#include "Item.h"



class Map	
{
private:
	SDL_Renderer* gRenderer;
	char tableau [24][32];
	
	int level;

	vector <Entity> tableEntities;
	vector <Item> tableItems;
	
public:
	
	Map(SDL_Renderer* gRenderer);
	Map(SDL_Renderer* gRenderer,int level );
	~Map(void);

	Entity* getEntity(int index);
	Entity* getEntity(string nom);
	
	void addEntity(Entity* c);
	void removeEntity(string nom);
	void removeEntity(int index);
	void setEntityOrientation(int index, int or);
	void setEntitySpeed(int index, int speed);

	void addItem(Item i);
	void removeItem(string nom);
	void removeItem(int index);

	int getLevel(){return level;}
	void setLevel(int l){level=l;}

	void testAffiche();
	void chargerTableau(string nomFichier);
	int getEntityX(int index);
	int getEntityY(int index);

	void moveEntities();
	bool checkMove(int x, int y,int or);

	char getTab(int i, int j){ return tableau[i][j];};
	void activateAI(void);
	Entity* findEntity(int index);

	vector<Entity> getTableEntities();

	bool heroDead();
	bool bam(int);
	void respawn();
	void bamHero(bool);
};

