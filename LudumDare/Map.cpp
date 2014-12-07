#include "Map.h"
#include "Entity.h"
#include "Item.h"
#include <fstream>
#include <ctime>
Map::Map(SDL_Renderer* g)
{
	srand(time(NULL));
	gRenderer=g;
	level=0;

	chargerTableau("map.txt");
}


Map::~Map(void)
{

}

void Map::chargerTableau(string nomFichier){

	char tmp;
	ifstream fichier(nomFichier, ios::in);  // on ouvre le fichier en lecture

	if(fichier)  // si l'ouverture a réussi
	{     
		for(int i=0;i<24;i++){
			for(int j=0;j<=32;j++){

				fichier.get(tmp);
				if(j<32)
					tableau[i][j]=tmp;

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

vector<Entity> Map::getTableEntities(){
	return tableEntities;
}

void Map::setEntityOrientation(int index, int or){
	if(index<tableEntities.size()){
		tableEntities[index].setEntityOrientation(or);
	}
}

void Map::setEntitySpeed(int index, int speed){
	if(index<tableEntities.size()){
		tableEntities[index].setEntitySpeed(speed);
	}
}

void Map::moveEntities(){

	vector<Entity>::iterator cursor;
	for(cursor= tableEntities.begin();cursor!=tableEntities.end();cursor++){
		int actualX=cursor->getPosX();
		int  actualY=cursor->getPosY();
		actualX=((actualX+10)/CASE);
		actualY=((actualY+10)/CASE);



		if(checkMove(actualX,actualY,cursor->getEntityOrientation())){
			if(cursor->getEntityOrientation()==1){ 
				cursor->setPosX(cursor->getPosX()-cursor->getEntitySpeed());
				cursor->setPosY(actualY*CASE);
			}
			else if(cursor->getEntityOrientation()==2){
				cursor->setPosY(cursor->getPosY()+cursor->getEntitySpeed());
				cursor->setPosX(actualX*CASE);
			}
			else if(cursor->getEntityOrientation()==3){
				cursor->setPosX(cursor->getPosX()+cursor->getEntitySpeed());
				cursor->setPosY(actualY*CASE);
			}
			else if(cursor->getEntityOrientation()==4){
				cursor->setPosY(cursor->getPosY()-cursor->getEntitySpeed());
				cursor->setPosX(actualX*CASE);
			}

		}
		else{

			if(cursor->getEntityOrientation()==1){ 
				cursor->setPosX(actualX*CASE);

			}
			else if(cursor->getEntityOrientation()==2){
				cursor->setPosY(actualY*CASE);
			}
			else if(cursor->getEntityOrientation()==3){
				cursor->setPosX(actualX*CASE);
			}
			else if(cursor->getEntityOrientation()==4){
				cursor->setPosY(actualY*CASE);
			}
		}
	}
}

bool Map:: checkMove(int x, int y, int or){
	if(or==1){ 
		if(x>0)
			if(tableau[x-1][y]=='0')return true;
			else return false;
	}
	else if(or==2){
		if(y<31)
			if(tableau[x][y+1]=='0')return true;
			else return false;

	}
	else if(or==3){
		if(x<24)
			if(tableau[x+1][y]=='0')return true;
			else return false;

	}
	else if(or==4){
		if(y>0)
			if(tableau[x][y-1]=='0')return true;
			else return false;

	}
	return false;
}



void Map::addEntity(Entity* c){
	tableEntities.push_back(*c);

}

void Map::removeEntity(string nom){

	vector<Entity>::iterator cursor;
	for(cursor= tableEntities.begin();cursor!=tableEntities.end();cursor++){
		if(cursor->getNameEntity()==nom) tableEntities.erase(cursor);

	}

}


Entity* Map::findEntity(int index){
	int tmp=0;
	vector<Entity>::iterator cursor;
	for(cursor= tableEntities.begin();cursor!=tableEntities.end();cursor++){
		if(tmp==index) return &tableEntities[tmp];

	}
	return NULL;
}
void Map::removeEntity(int index){

	int tmp=0;
	vector<Entity>::iterator cursor;
	for(cursor= tableEntities.begin();cursor!=tableEntities.end();cursor++){
		if(tmp==index) tableEntities.erase(cursor);
		tmp++;
	}
}

void Map::addItem(Item i){

	tableItems.push_back(i);

}
void Map::removeItem(string nom){

	vector<Item>::iterator cursor;
	for(cursor= tableItems.begin();cursor!=tableItems.end();cursor++){
		if(cursor->getnameItem()==nom) tableItems.erase(cursor);

	}
}
void Map::removeItem(int index){
	int tmp=0;
	vector<Item>::iterator cursor;
	for(cursor= tableItems.begin();cursor!=tableItems.end();cursor++){
		if(tmp==index) tableItems.erase(cursor);
		tmp++;
	}

}

int Map::getEntityX(int index){
	if(index< tableEntities.size()){
		return tableEntities[index].getPosX();
	}
}
int Map::getEntityY(int index){
	if(index< tableEntities.size()){
		return tableEntities[index].getPosY();
	}
}

void Map::activateAI(void){
	int actualX;int  actualY;
	vector<Entity>::iterator cursor;






	for(cursor=tableEntities.begin()+1;cursor!=tableEntities.end();cursor++){
		actualX=cursor->getPosX();
		actualY=cursor->getPosY();

		actualX=((actualX+16)/CASE);
		actualY=((actualY+16)/CASE);	

		if(cursor->getNameEntity()=="Pacman"){



			int heroX=(tableEntities.begin()->getPosX()+16)/CASE;
			int heroY=(tableEntities.begin()->getPosY()+16)/CASE;
			int diffX=fabs((double)heroX-actualX);
			int diffY=fabs((double)heroY-actualY);

			if(diffX<=diffY ){

				if(heroX-actualX<=0 && checkMove(actualX,actualY,1)){cursor->setEntityOrientation(1);}

				else if (heroX-actualX<=0 && checkMove(actualX,actualY,2)){cursor->setEntityOrientation(2);} 

				else if (heroX-actualX<=0 && checkMove(actualX,actualY,4)){cursor->setEntityOrientation(4);}

				else if(heroX-actualX>=0 && checkMove(actualX,actualY,3)){cursor->setEntityOrientation(3);}

				else if (heroX-actualX>=0 && checkMove(actualX,actualY,4)){cursor->setEntityOrientation(4);}

				else if (heroX-actualX>=0 && checkMove(actualX,actualY,2)){cursor->setEntityOrientation(2);}

				else if (checkMove(actualX,actualY,1)) {cursor->setEntityOrientation(1);}

				else if (checkMove(actualX,actualY,3)) {cursor->setEntityOrientation(3);}

				else if (checkMove(actualX,actualY,2)) {cursor->setEntityOrientation(2);}

				else if (checkMove(actualX,actualY,4)) {cursor->setEntityOrientation(4);}

				//sinan c'est qu'il y a un gros probleme et qu'il se casse de l'écran, ce qui ne rentre pas dans le thème, du coup on gère pas et FATAL ERROR...
			}


			else if(diffX>diffY ){

				if(heroY-actualY<=0 && checkMove(actualX,actualY,4)){cursor->setEntityOrientation(4);}

				else if (heroY-actualY<=0 && checkMove(actualX,actualY,1)){cursor->setEntityOrientation(1);} 


				else if(heroY-actualY<=0 && checkMove(actualX,actualY,3)){cursor->setEntityOrientation(3);}


				else if (heroY-actualY>=0 && checkMove(actualX,actualY,2)){cursor->setEntityOrientation(2);}

				else if (heroY-actualY>=0 && checkMove(actualX,actualY,1)){cursor->setEntityOrientation(1);}

				else if (heroY-actualY>=0 && checkMove(actualX,actualY,3)){cursor->setEntityOrientation(3);}

				else if (checkMove(actualX,actualY,1)) {cursor->setEntityOrientation(1);}

				else if (checkMove(actualX,actualY,2)) {cursor->setEntityOrientation(2);}

				else if (checkMove(actualX,actualY,3)) {cursor->setEntityOrientation(3);}

				else if (checkMove(actualX,actualY,4)) {cursor->setEntityOrientation(4);}

				//sinan c'est qu'il y a un gros probleme et qu'il se casse de l'écran, ce qui ne rentre pas dans le thème, du coup on gère pas et FATAL ERROR...
			}


		}
		else if(cursor->getNameEntity()=="junior"){

			int i= rand()%4+1;


			while(!checkMove(actualX,actualY,i)){
				i= rand()%4+1;

			}
			cursor->setEntityOrientation(i);
		

		}
	}
}


