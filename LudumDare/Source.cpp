#include "Header.h"
#include "Context.h"


int main( int argc, char* args[] )
{
	Context game;
	int niveau =1;
	bool continuer=true;
	while(continuer && game.launchGame(niveau)){
		continuer = game.gameOver(niveau);
		if(niveau<1){
			niveau++;
		}

	}



	return 0;
}
