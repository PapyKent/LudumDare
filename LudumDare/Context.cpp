#include "Context.h"
#include "Audio.h"
#include "Graphic.h"
#include "Physic.h"


Context::Context(void)
{
	SDL_Window* window = NULL;

	graphicEngine=new Graphic(window, gRenderer);

	audioEngine=new Audio();
	audioEngine->start(1);

	map = new Map(gRenderer);

}

Context::~Context(void)
{
	delete(graphicEngine);
	delete(audioEngine);
	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

}

bool Context::init(){
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
	return true;
}

bool Context::launchGame(){
	bool quit=false;
	SDL_Event e;

	while(!quit){
		graphicEngine->displayBackground(*map);
		graphicEngine->refresh();
		while(SDL_PollEvent(&e) !=0){
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
		}
	}

	return true;
}