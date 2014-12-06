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
	Mob* test = new Mob("test", 0, 0, 0, "pacTEST.bmp", 0, gRenderer);
	test->setPosX(50);
	test->setPosY(50);
	map->addEntity(test);

	Mob* test2 = new Mob("test2", 0, 0, 0, "pacTEST.bmp", 0, gRenderer);
	test2->setPosX(100);
	test2->setPosY(100);
	map->addEntity(test2);


	for(int i=0;i<5;i++){
		map->tabTest[i]=*test;
	}
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
					map->getTableEntities().begin()->setEntityOrientation(1);
					map->getTableEntities().begin()->setEntitySpeed(5); //valeur test
							   }
				break; 
				case SDLK_DOWN: {
					map->getTableEntities().begin()->setEntityOrientation(3);
					map->getTableEntities().begin()->setEntitySpeed(5); //valeur test			
								}
				break; 
				case SDLK_LEFT: {
					map->getTableEntities().begin()->setEntityOrientation(4);
					map->getTableEntities().begin()->setEntitySpeed(5); //valeur test			
								}
				break;
				case SDLK_RIGHT: {
					map->getTableEntities().begin()->setEntityOrientation(2);
					map->getTableEntities().begin()->setEntitySpeed(5); //valeur test			 
								 }
				break; 

				default: map->getTableEntities().begin()->setEntitySpeed(0);
				break;
				} 
			}
			//map->activateAI();
			//map->moveEntities();


			//		graphicEngine->displayBackground(*map);
			graphicEngine->displayEntities(map->getTableEntities());
			graphicEngine->refresh();
		}
	}

	return true;
}

bool Context::createRenderer()
{
	gRenderer = SDL_CreateRenderer( window, -1, 0 );

	if ( gRenderer == nullptr )
	{
		std::cout << "Failed to create renderer : " << SDL_GetError();
		return false;
	}

	return true;
}