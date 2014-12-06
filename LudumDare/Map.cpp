#include "Map.h"
#include "Entity.h"
#include "Item.h"
#include <fstream>

Map::Map(void)
{
	
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