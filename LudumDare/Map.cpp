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

void Map::addItem(Item* i){

	tableItems.push_back(*i);

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
	int heroX;
	int heroY;




	for(cursor=tableEntities.begin();cursor!=tableEntities.end();cursor++){

		if(cursor->getNameEntity()=="ghost"){
			heroX=(cursor->getPosX()+17)/CASE;
			heroY=(cursor->getPosY()+17)/CASE;
		}



		// IA PACMAN ************************************************************
		else if(cursor->getNameEntity()=="Pacman"){
			actualX=(cursor->getPosX()+17)/CASE;
			actualY=(cursor->getPosY()+17)/CASE;


			if(heroX-actualX<=0){

				if(checkMove(actualX,actualY,1)){
					cursor->setEntityOrientation(1);
				}
				else if(heroY-actualY<=0){
					if(checkMove(actualX,actualY,4))
						cursor->setEntityOrientation(4);
					else{
						int i= rand()%4+1;


						while(!checkMove(actualX,actualY,i)){
							i= rand()%4+1;

						}
						cursor->setEntityOrientation(i);
					}
				} else{
					if(checkMove(actualX,actualY,2))
						cursor->setEntityOrientation(2);
					else{
						int i= rand()%4+1;
						while(!checkMove(actualX,actualY,i)){
							i= rand()%4+1;
						}
						cursor->setEntityOrientation(i);
					}
				}
			}
			else{
				if(checkMove(actualX,actualY,3)){
					cursor->setEntityOrientation(3);
				}
				else if(heroY-actualY<=0){
					if(checkMove(actualX,actualY,4))
						cursor->setEntityOrientation(4);
					else{
						int i= rand()%4+1;


						while(!checkMove(actualX,actualY,i)){
							i= rand()%4+1;

						}
						cursor->setEntityOrientation(i);
					}
				} else{
					if(checkMove(actualX,actualY,2))
						cursor->setEntityOrientation(2);
					else{
						int i= rand()%4+1;
						while(!checkMove(actualX,actualY,i)){
							i= rand()%4+1;
						}
						cursor->setEntityOrientation(i);
					}
				}
			}




		}

		// FIN IA PACMAN ************************************************************
		else if(cursor->getNameEntity()=="junior"){

			int i= rand()%4+1;


			while(!checkMove(actualX,actualY,i)){
				i= rand()%4+1;

			}
			cursor->setEntityOrientation(i);


		}
	}
}



bool Map::heroDead(){
	vector<Entity>::iterator cursor;
	for(cursor=tableEntities.begin();cursor!=tableEntities.end();cursor++){
		if(cursor->getNameEntity()=="ghost"){
			if(cursor->isDead())return true;
		}
	}

	return false;
}

bool Map::bam(int i){
	vector<Entity>::iterator cursor;
	int tmp=0;
	for(cursor=tableEntities.begin();cursor!=tableEntities.end();cursor++){
		if(tmp==i){
			bamHero(cursor->isDead());
			cursor->takeDMG(1,cursor->isDead());

		}
		tmp++;
	}
	return true;
}

void Map::bamHero(bool b){
	vector<Entity>::iterator cursor;
	for(cursor=tableEntities.begin();cursor!=tableEntities.end();cursor++){
		if(cursor->getNameEntity()=="ghost")cursor->takeDMG(1,b);
	}
}


void Map::activateHeroAttack(){
	int orientation = tableEntities[0].getEntityOrientation();
	vector<Entity>::iterator cursor;
	int rangeX=0;
	int rangeY=0;

	int casedegatX;
	int casedegatY;

	int posXen;
	int posYen;
	int posXhero=tableEntities[0].getPosX();
	int posYhero=tableEntities[0].getPosY();

	switch(orientation){
	case 1:
		rangeX+=-50;
		break;
	case 2:
		rangeY+=50+CASE;
		break;
	case 3:
		rangeX+=50+CASE;
		break;
	case 4:
		rangeY+=-50;
		break;
	}
	casedegatX =posXhero+rangeX;
	casedegatY =posYhero+rangeY;


	for(int i = 1; i < tableEntities.size(); i++){	

		posXen=tableEntities[i].getPosX();
		posYen = tableEntities[i].getPosY();

		switch(orientation){
		case 1:
			if(posXen>=casedegatX && posXen<=posXhero && posYen>=posYhero && posYen<=posYhero+32){
				tableEntities[i].takeDMG(1, false);
			}
			break;
		case 2:
			if(posYen<=casedegatY && posYen>=posYhero && posXen>=posXhero && posXen<=posXhero+32){
				tableEntities[i].takeDMG(1, false);
			}
			break;
		case 3:
			if(posXen<=casedegatX && posXen>=posXhero && posYen>=posYhero && posYen<=posYhero+32){
				tableEntities[i].takeDMG(1, false);
			}
			break;
		case 4:
			if(posYen>=casedegatY && posYen<=posYhero && posXen>=posXhero && posXen<=posXhero+32){
				tableEntities[i].takeDMG(1, false);
			}
			break;
		}


	}
}

void Map::respawn(int num){
	if(num<tableEntities.size()){
		switch(num){
		case 0:
			tableEntities[num].setPosX(0);
			tableEntities[num].setPosY(0);
			tableEntities[num].setHp(1);
			tableEntities[num].setEntitySpeed(0);
			break;
		case 1:
			tableEntities[num].setPosX(9*CASE);
			tableEntities[num].setPosY(6*CASE);
			tableEntities[num].setHp(1);
			break;
		case 2:
			tableEntities[num].setPosX(20*CASE);
			tableEntities[num].setPosY(6*CASE);
			tableEntities[num].setHp(1);
			break;
		case 3:

			tableEntities[num].setPosX(13*CASE);
			tableEntities[num].setPosY(0*CASE);
			tableEntities[num].setHp(1);
			break;
		case 4:
			tableEntities[num].setPosX(19*CASE);
			tableEntities[num].setPosY(30*CASE);
			tableEntities[num].setHp(1);
			break;
		case 5:
			tableEntities[num].setPosX(10*CASE);
			tableEntities[num].setPosY(7*CASE);
			tableEntities[num].setHp(1);
			break;
		case 6:

			tableEntities[num].setPosX(16*CASE);
			tableEntities[num].setPosY(25*CASE);
			tableEntities[num].setHp(1);
			break;
		case 7:

			tableEntities[num].setPosX(4*CASE);
			tableEntities[num].setPosY(26*CASE);
			tableEntities[num].setHp(1);
			break;
		case 8:

			tableEntities[num].setPosX(4*CASE);
			tableEntities[num].setPosY(17*CASE);
			tableEntities[num].setHp(1);
			break;
		}

	}
}

void Map::respawn(){

	SDL_Delay(1500);
	int tmp=0;
	vector<Entity>::iterator cursor;
	for(cursor=tableEntities.begin();cursor!=tableEntities.end();cursor++){

		if(tmp==0){
			cursor->setPosX(0);
			cursor->setPosY(0);
			cursor->setHp(1);
			cursor->setEntitySpeed(0);

		}

		else if(tmp==1){
			cursor->setPosX(9*CASE);
			cursor->setPosY(6*CASE);
			cursor->setHp(50);
		}

		else if(tmp==2){

			cursor->setPosX(20*CASE);
			cursor->setPosY(6*CASE);
			cursor->setHp(1);
		}

		else if(tmp==3){
			cursor->setPosX(13*CASE);
			cursor->setPosY(0);
			cursor->setHp(1);

		}
		else if(tmp==4){
			cursor->setPosX(19*CASE);
			cursor->setPosY(30*CASE);
			cursor->setHp(1);

		}
		else if(tmp==5){
			cursor->setPosX(10*CASE);
			cursor->setPosY(7);
			cursor->setHp(1);

		}
		else if(tmp==6){
			cursor->setPosX(16*CASE);
			cursor->setPosY(25*CASE);
			cursor->setHp(1);

		}
		else if(tmp==7){
			cursor->setPosX(4*CASE);
			cursor->setPosY(26*CASE);
			cursor->setHp(1);

		}
		else if(tmp==8){
			cursor->setPosX(4*CASE);
			cursor->setPosY(17*CASE);
			cursor->setHp(1);

		}
		tmp++;
	}

}