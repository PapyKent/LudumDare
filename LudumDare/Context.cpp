#include "Context.h"
#include "Audio.h"
#include "Graphic.h"
#include "Physic.h"
#include "Mob.h"


Context::Context(void)
{

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "Pacman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Update the surface
			SDL_UpdateWindowSurface( window );
		}
	}

	createRenderer();


	graphicEngine=new Graphic(window, gRenderer);

	audioEngine=new Audio();
	audioEngine->start(1);

	map = new Map(gRenderer);
	Mob* test = new Mob("ghost", 0, 1, 0, "pacTEST.bmp", 0);
	test->setPosX(0);
	test->setPosY(0);
	map->addEntity(test);

	Mob* test2 = new Mob("junior", 0, 1, 0, "pacTEST.bmp", 0);
	test->setPosX(64);
	test->setPosY(0);
	map->addEntity(test);


}

Context::~Context(void)
{


	delete(graphicEngine);
	delete(audioEngine);
	delete(map);
	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

}



bool Context::launchGame(){
	bool quit=false;
	SDL_Event e;



	while(!quit){


		while(SDL_PollEvent(&e) !=0){
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			//User presses a key
			else if( e.type == SDL_KEYDOWN )
			{
				//Select surfaces based on key press
				switch( e.key.keysym.sym ) { 
				case SDLK_UP:  {
					map->setEntityOrientation(0, 1);
					map->setEntitySpeed(0, 5); //valeur test
							   }
							   break; 
				case SDLK_DOWN: {
					map->setEntityOrientation(0, 3);
					map->setEntitySpeed(0, 5); //valeur test			
								}
								break; 
				case SDLK_LEFT: {
					map->setEntityOrientation(0, 4);
					map->setEntitySpeed(0, 5); //valeur test			
								}
								break;
				case SDLK_RIGHT: {
					map->setEntityOrientation(0, 2);
					map->setEntitySpeed(0, 5); //valeur test			 
								 }
								 break; 

				default: map->setEntitySpeed(0,0);
					break;
				} 
			}
		}
		map->activateAI();
		map->moveEntities();


		graphicEngine->displayBackground(*map);
		graphicEngine->displayEntities(map->getTableEntities());
		graphicEngine->refresh();
	}

	return true;
}

bool Context::createRenderer()
{
	gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

	if ( gRenderer == nullptr )
	{
		std::cout << "Failed to create renderer : " << SDL_GetError();
		return false;
	}

	return true;
}