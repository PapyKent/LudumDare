#include "Graphic.h"


Graphic::Graphic(void)
{
	

	//The window renderer
	gRenderer = NULL;

	//Create vsynced renderer for window
	gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	if( gRenderer == NULL )
	{
		printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
	}
	else{
		SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	}

	//Clip
	clip[0].x = 0;
	clip[0].y = 0;
	clip[0].w = CASE;
	clip[0].h = CASE;

	clip[1].x = CASE;
	clip[1].y = 0;
	clip[1].w = CASE;
	clip[1].h = CASE;

	clip[2].x = CASE*2;
	clip[2].y = 0;
	clip[2].w = CASE;
	clip[2].h = CASE;

	clip[3].x = CASE*3;
	clip[3].y = 0;
	clip[3].w = CASE;
	clip[3].h = CASE;

	clip[4].x = CASE*4;
	clip[4].y = 0;
	clip[4].w = CASE;
	clip[4].h = CASE;

	clip[5].x = CASE*5;
	clip[5].y = 0;
	clip[5].w = CASE;
	clip[5].h = CASE;

}


Graphic::~Graphic(void)
{
}

void Graphic::displayBackground(char** map){
	SDL_RenderClear( gRenderer );
	SDL_Rect renderQuad = { 0, 0, CASE, CASE };

	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}


	for(int i = 0; i < SCREEN_WIDTH; i++){
		for(int j = 0; j < SCREEN_HEIGHT; j++){
			SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
		}
	}
}

