#include "Map.h"
#include "Entity.h"
#include "Item.h"
#include <fstream>

Map::Map(SDL_Renderer* g)
{
	gRenderer=g;
	level=0;

	chargerTableau("map.txt");
}


Map::~Map(void)
{

}

void Map::chargerTableau(string nomFichier){


	ifstream fichier(nomFichier, ios::in);  // on ouvre le fichier en lecture

	if(fichier)  // si l'ouverture a réussi
	{     
		for(int i=0;i<24;i++){
			for(int j=0;j<32;j++){
				cout<<fichier.get(tableau[i][j])<<endl;	
				//	fichier.get(tableau[i][j]);
			}
		}






	}
	else  // sinon
		cerr << "Impossible d'ouvrir le fichier !" << endl;



}
void Map::testAffiche(){
	for(int i=0;i<24;i++){
		for(int j=0;j<32;j++){
			cout<<tableau[i][j];
		}
		cout<<endl;
	}
}

/*
void Map::moveEntities(){

		vector<Entity>::iterator cursor;
		for(cursor= tableEntities.begin();cursor!=tableEntities.end();cursor++){
			int actualX=cursor->getPosX();
		   int  actualY=cursor->getPosY();
		   actualX=((actualX+16)/CASE);
		   actualX=((actualY+16)/CASE);



		   if(checkMove(actualX,actualY,cursor)){
			   cursor->setPosX(actualX);
			   cursor->setPosY(actualY);
		   }
		}
	}

bool Map:: checkMove(int x, int y, Entity e){
	if(e.getEntityOrientation==1){ 
		if(tableau[x][y-e.getEntitySpeed]==5)return true;
	}
	else if(or==2){
	}
	else if(or==3){
	}
	else if(or==4){
	}

}*/