#include "Graphic.h"
#include "Map.h"
#include "Mob.h"

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

void Graphic::display(Map map){

	for(int i = 0; i < SCREEN_HEIGHT/32; i++){
		for(int j = 0; j < SCREEN_WIDTH/32; j++){
			if(map.getTab(i, j)-'0' !=0){
				render(bg, i*32, j*32, &clip[map.getTab(i, j)-'0']);
			}

		}
	}
	SDL_Rect clap;
	clap.x=0;
	clap.y=0;
	clap.w=32;
	clap.h=32;
	//	Entity* test = new Mob("test", 0, 0, 0, "pacTEST.bmp", 0, gRenderer);
	Entity* test =map.findEntity(0);
	test->setPosX(50);
	test->setPosY(50);
	render(test->getSprite(), test->getPosX(),test->getPosY(), &clap);

}

void Graphic::displayBackground(Map map){


	for(int i = 0; i < SCREEN_HEIGHT/32; i++){
		for(int j = 0; j < SCREEN_WIDTH/32; j++){
			if(map.getTab(i, j)-'0' !=0){
				render(bg, i*32, j*32, &clip[map.getTab(i, j)-'0']);
			}

		}
	}

}

void Graphic::refresh(){
	SDL_RenderPresent( gRenderer );
}


void Graphic::displayEntities(vector<Entity> tableEntities){

	SDL_Rect clap;
	clap.x=0;
	clap.y=0;
	clap.w=32;
	clap.h=32;
	render(tableEntities[0].getSprite(), 20,20, &clap);
	/*vector<Entity>::iterator cursor;
	for(cursor= tableEntities.begin();cursor!=tableEntities.end();cursor++){
		render(cursor->getSprite(), cursor->getPosX(), cursor->getPosY(), &clap);
	}*/
}

void Graphic::render(SDL_Texture* mTexture, int x, int y, SDL_Rect* clip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { y, x, CASE, CASE };

	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
		SDL_RenderCopy( gRenderer, mTexture, clip, &renderQuad );
	}

	else{
		SDL_RenderCopy( gRenderer, mTexture, NULL, &renderQuad );
	}
}
