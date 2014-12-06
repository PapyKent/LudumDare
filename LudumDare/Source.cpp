#include "Header.h"
#include "Context.h"


int main( int argc, char* args[] )
{
	Context game;

	if(game.init()){
		game.launchGame();
	}



	return 0;
}