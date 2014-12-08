#include "Context.h"
#include "Audio.h"
#include "Graphic.h"
#include "Physic.h"
#include "Mob.h"
#include "Hero.h"
#include "Pacman.h"
#include <time.h>


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

	 
	 //The surface contained by the window 
	gScreenSurface = NULL; 
	//The image we will load and show on the screen 
	gHelloWorld = NULL;

	 //Create window 
 
	if( window == NULL ) { 
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() ); 
	
	} else { 
	//Get window 
		 gScreenSurface = SDL_GetWindowSurface( window ); 
	}

	gHelloWorld = SDL_LoadBMP( "picture/accueil.bmp" ); 
	if( gHelloWorld == NULL ) { 
	printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
	 } 

	 SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
	  SDL_UpdateWindowSurface( window );
	  audioEngine=new Audio();
	  audioEngine->playMenu();
	 
	  SDL_Delay(3000);

	  gHelloWorld = SDL_LoadBMP( "picture/control.bmp" ); 
	if( gHelloWorld == NULL ) { 
	printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
	 } 

	 SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
	  SDL_UpdateWindowSurface( window );
	  SDL_Delay(3000);

  audioEngine->playGunEffect();
   SDL_Delay(500);
	createRenderer();

	physicEngine=new Physic();

	graphicEngine=new Graphic(window, gRenderer);

	
	audioEngine->start(1);

	map=new Map(gRenderer);
	Hero* test = new Hero("ghost", 0, 1, 1, "ghost1.bmp", 0);
	test->setPosX(0);
	test->setPosY(0);
	map->addEntity(test);

	Pacman* test2 = new Pacman("Pacman", 4, 1, 10, "pacman.bmp", 0);
	map->addEntity(test2);

	for(int i = 0; i < 7; i ++){
		map->addEntity(new Mob("Pacman", 3, 1, 1, "junior.bmp", 0));
	}
	for(int i = 0; i < 6; i++){
		map->addEntity(new Mob("junior", 3, 1, 1, "junior.bmp", 0));
	}
	
}

Context::~Context(void)
{
	SDL_FreeSurface( gHelloWorld ); 
	gHelloWorld = NULL; 
	SDL_DestroyWindow( window );
	delete(graphicEngine);
	delete(audioEngine);
	delete(map);
	
	SDL_DestroyRenderer(gRenderer);
	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

}



bool Context::launchGame(int niveau){

	bool quit=false;
	SDL_Event e;
	srand(time(NULL));
	int key=0;
	bool haut=false;
	bool bas=false;
	bool droite=false;
	bool gauche=false;

	bool attack=false;

	map->respawn(niveau);

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
				if(e.key.keysym.sym ==SDLK_SPACE){
					attack = true;
					
					
				}
			}




		}
		if(attack){
			
			map->activateHeroAttack(); 

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
		int tmp=(rand()%20)+1;
		if(tmp==5)
			map->activateAI();


		map->moveEntities();

		for(int i=1; i < map->getTableEntities().size(); i++){
			if(physicEngine->collision(map->getEntityX(0),map->getEntityY(0), map->getEntityX(i), map->getEntityY(i) ) ){
				map->bam(i);
			}
		}

		if(map->heroDead()){
			audioEngine->playGameOverEffect();
			map->respawn(niveau);
			haut=false;
			bas=false;
			droite=false;
			gauche=false;
		}
		graphicEngine->displayBackground(*map, niveau);
		if(graphicEngine->displayEntities(map->getTableEntities(), attack )&& attack==true) audioEngine->playGunEffect();

			attack=false;


		if(victory(map->getEntityX(0), map->getEntityY(0), niveau)){
			audioEngine->playWinEffect();
			return true;
		}

		graphicEngine->refresh();

	}

	 gHelloWorld = SDL_LoadBMP( "picture/end.bmp" ); 
	if( gHelloWorld == NULL ) { 
	printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
	 } 

	 SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
	  SDL_UpdateWindowSurface( window );

	  SDL_Delay(3000);

	return false;
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

bool Context::victory(int posx, int posy, int niveau)
{
	int xTarget=23;
	int yTarget=31;

	if(niveau==2){
		xTarget=0;
		yTarget=0;
	}

	if(posx/32==xTarget && posy/32==yTarget){
		return true;
	}
	return false;
}

bool Context::gameOver(int niveau){

	SDL_RenderClear( gRenderer );

	bool quit=false;
	SDL_Event e;
	if(niveau==1){
		return true;
	}
	if(niveau == 2){
			SDL_Surface* fin = SDL_LoadBMP( "picture/win.bmp" ); 
				 SDL_BlitSurface( fin, NULL, gScreenSurface, NULL );
				 SDL_UpdateWindowSurface( window );
				 SDL_Delay(5000);

		return false;
	}

	return false;
}

