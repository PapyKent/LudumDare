#include "Context.h"
#include "Audio.h"
#include "Graphic.h"
#include "Physic.h"
#include "Mob.h"
#include "Hero.h"
#include "Pacman.h"


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

	physicEngine=new Physic();

	graphicEngine=new Graphic(window, gRenderer);

	audioEngine=new Audio();
	//audioEngine->start(1);

	map=new Map(gRenderer);
	Hero* test = new Hero("ghost", 0, 1, 1, "ghost1.bmp", 0);
	test->setPosX(0);
	test->setPosY(0);
	map->addEntity(test);


	Mob* test3 = new Mob("junior", 3, 1, 1, "pacTEST.bmp", 0);
	test3->setPosX(9*CASE);
	test3->setPosY(6*CASE);
	map->addEntity(test3);


	Mob* test4 = new Mob("junior", 3, 1, 1, "pacTEST.bmp", 0);
	test4->setPosX(20*CASE);
	test4->setPosY(6*CASE);
	map->addEntity(test4);

	Pacman* test2 = new Pacman("Pacman", 4, 1, 50, "pacTEST.bmp", 0);
	test2->setPosX(13*CASE);
	test2->setPosY(0);
	map->addEntity(test2);

}

Context::~Context(void)
{


	delete(graphicEngine);
	delete(audioEngine);
	delete(map);

	SDL_DestroyRenderer(gRenderer);
	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

}



bool Context::launchGame(){
	bool quit=false;
	SDL_Event e;

	int key=0;
	bool haut=false;
	bool bas=false;
	bool droite=false;
	bool gauche=false;

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

					haut=true;
					bas=false;
					droite=false;
					gauche=false;

							   }
							   break; 
				case SDLK_DOWN: {

					haut=false;
					bas=true;
					droite=false;
					gauche=false;

								}
								break; 
				case SDLK_LEFT: {

					haut=false;
					bas=false;
					droite=false;
					gauche=true;

								}
								break;
				case SDLK_RIGHT: {

					haut=false;
					bas=false;
					droite=true;
					gauche=false;

								 }
								 break; 

				default: 
					break;
				} 
			}




		}


		if(droite)key=2;
		else if(gauche)key=4;
		else if (haut)key=1;
		else if(bas)key=3;
		else key=0;

		if(key!=0){
			map->setEntityOrientation(0, key);
			map->setEntitySpeed(0, 4);
		}
		else map->setEntitySpeed(0, 0);
		int tmp=(rand()%30)+1;
		if(tmp==5)
			map->activateAI();


		map->moveEntities();

		for(int i=1; i < map->getTableEntities().size(); i++){
			if(physicEngine->collision(map->getEntityX(0),map->getEntityY(0), map->getEntityX(i), map->getEntityY(i) )){
				map->bam(i);
			}
		}

		graphicEngine->displayBackground(*map);
		graphicEngine->displayEntities(map->getTableEntities());
		graphicEngine->refresh();

		if(map->heroDead()){

			map->respawn();
			haut=false;
			bas=false;
			droite=false;
			gauche=false;
		}

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

