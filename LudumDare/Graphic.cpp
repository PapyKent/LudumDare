#include "Graphic.h"
#include "Map.h"
#include "Mob.h"

Graphic::Graphic(SDL_Window* wind ,SDL_Renderer* gRend)
{
	gRenderer=gRend;
	window = wind;
	SDL_Surface* loadedSurface = SDL_LoadBMP("map.bmp");
	bg = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );

	SDL_FreeSurface( loadedSurface );


	//Clip
	for(int i = 0; i < 16; i++){
	clip[i].x = CASE*i;
	clip[i].y = 0;
	clip[i].w = CASE;
	clip[i].h = CASE;
	}


}


Graphic::~Graphic(void)
{
	SDL_DestroyTexture(bg);
}

void Graphic::display(SDL_Texture* mTexture, int x, int y, int frame){
	SDL_Rect clap;
	clap.x=0;
	clap.y=0;
	clap.w=32;
	clap.h=32;
	render(mTexture, x, y, &clap);

}

void Graphic::displayBackground(Map map){
	int index=0;

	for(int i = 0; i < SCREEN_HEIGHT/32; i++){
		for(int j = 0; j < SCREEN_WIDTH/32; j++){
			index= map.getTab(i, j);
			if(index<=57 && index>=48){
				render(bg, i*32, j*32, &clip[index-'0']);
			}else{
				render(bg, i*32, j*32, &clip[index-55]);
			}



		}
	}

}

void Graphic::refresh(){
	SDL_RenderPresent( gRenderer );
}


void Graphic::displayEntities(vector<Entity> tableEntities){
	SDL_Surface* loadedSurface=NULL;
	SDL_Texture* tex=NULL;
	SDL_Rect clap;
	clap.x=0;
	clap.y=0;
	clap.w=32;
	clap.h=32;
	vector<Entity>::iterator cursor;
	for(cursor= tableEntities.begin();cursor!=tableEntities.end();cursor++){
		loadedSurface = SDL_LoadBMP(cursor->getLoader().c_str());
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 255, 255 ) );
		tex=SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		render(tex, cursor->getPosX(), cursor->getPosY(), &clap);
		SDL_FreeSurface( loadedSurface );
	}
}

void Graphic::render(SDL_Texture* mTexture, int x, int y, SDL_Rect* clip)
{
	
	
	SDL_Rect renderQuad = { y, x, CASE, CASE };
	//Set rendering space and render to screen

	
	
	
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
