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

	if(fichier)  // si l'ouverture a r�ussi
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

void Map::moveEntities(){

	vector<Entity>::iterator cursor;
	for(cursor= tableEntities.begin();cursor!=tableEntities.end();cursor++){
		int actualX=cursor->getPosX();
		int  actualY=cursor->getPosY();
		actualX=((actualX+16)/CASE);
		actualX=((actualY+16)/CASE);



		if(checkMove(actualX,actualY,cursor->getEntityOrientation())){
			if(cursor->getEntityOrientation()==1){ 
				cursor->setPosY(actualY-cursor->getEntitySpeed);
			}
			else if(cursor->getEntityOrientation()==2){
				cursor->setPosX(actualX+cursor->getEntitySpeed);
			}
			else if(cursor->getEntityOrientation()==3){
				cursor->setPosX(actualY+cursor->getEntitySpeed);
			}
			else if(cursor->getEntityOrientation()==4){
				cursor->setPosY(actualX-cursor->getEntitySpeed);
			}
			
		}
	}
}

bool Map:: checkMove(int x, int y, int or){
	if(or==1){ 
		if(tableau[x][y-1]==0)return true;
		else return false;
	}
	else if(or==2){
		if(tableau[x+1][y]==0)return true;
		else return false;
	}
	else if(or==3){
		if(tableau[x][y+1]==0)return true;
		else return false;
	}
	else if(or==4){
		if(tableau[x-1][y]==0)return true;
		else return false;
	}
	return false;
}