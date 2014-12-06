#include "Graphic.h"
#include "Map.h"

Graphic::Graphic(SDL_Window* wind ,SDL_Renderer* gRend)
{
	gRenderer=gRend;
	window = wind;
	SDL_Surface* loadedSurface = SDL_LoadBMP("testBG.bmp");
	bg = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );

	SDL_FreeSurface( loadedSurface );


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

	clip[6].x = CASE*6;
	clip[6].y = 0;
	clip[6].w = CASE;
	clip[6].h = CASE;

}


Graphic::~Graphic(void)
{
		SDL_DestroyTexture(bg);
}

void Graphic::displayBackground(Map map){
	SDL_RenderClear( gRenderer );
	int test;
	for(int i = 0; i < SCREEN_HEIGHT/32; i++){
		for(int j = 0; j < SCREEN_WIDTH/32; j++){

			test=map.getTab(i, j)-'0';
			render(bg, i*32, j*32, &clip[map.getTab(i, j)-'0']);

		}
	}
}

void Graphic::refresh(){
	SDL_RenderPresent( gRenderer );
}

void Graphic::SDL_RenderDrawRect(){

	SDL_SetRenderDrawColor(gRenderer, 255,0,0,255);
	SDL_RenderClear(gRenderer);

	SDL_Rect r;
	r.x = 50;
	r.y = 50;
	r.w = 50;
	r.h = 50;

	SDL_RenderPresent(gRenderer);


}

void Graphic::render(SDL_Texture* mTexture, int x, int y, SDL_Rect* clip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { y, x, CASE, CASE };

	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy( gRenderer, mTexture, clip, &renderQuad );
}
