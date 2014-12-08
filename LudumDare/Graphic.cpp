#include "Graphic.h"
#include "Map.h"
#include "Mob.h"

Graphic::Graphic(SDL_Window* wind ,SDL_Renderer* gRend)
{
	frame=0;
	gRenderer=gRend;
	window = wind;
	SDL_Surface* loadedSurface = SDL_LoadBMP("map.bmp");
	bg = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
	SDL_Surface* loadedSurface2 = SDL_LoadBMP("bam.bmp");
	SDL_SetColorKey(loadedSurface2, SDL_TRUE, SDL_MapRGB( loadedSurface2->format, 0, 255, 255 ) );
	pan = SDL_CreateTextureFromSurface( gRenderer, loadedSurface2 );

	SDL_FreeSurface( loadedSurface );
	SDL_FreeSurface( loadedSurface2 );

	//Clip
	for(int i = 0; i < 18; i++){
		clip[i].x = CASE*i;
		clip[i].y = 0;
		clip[i].w = CASE;
		clip[i].h = CASE;
	}


}


Graphic::~Graphic(void)
{
	SDL_DestroyTexture(bg);
	SDL_DestroyTexture(pan);
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


void Graphic::displayEntities(vector<Entity> tableEntities, bool attack){
	SDL_Surface* loadedSurface=NULL;
	SDL_Texture* tex=NULL;
	SDL_Rect clap;
	clap.x=0;
	clap.y=0;
	clap.w=32;
	clap.h=32;

	SDL_Rect cloup[4];

	for(int i=0; i < 4; i++){
		cloup[i].x=i*32;
		cloup[i].y=0;
		cloup[i].w =32;
		cloup[i].h = 32;
	}

	vector<Entity>::iterator cursor;
	for(cursor= tableEntities.begin();cursor!=tableEntities.end();cursor++){
		if(!cursor->isDead()){
			loadedSurface = SDL_LoadBMP(cursor->getLoader().c_str());
			SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 255, 255 ) );
			tex=SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
			render(tex, cursor->getPosX(), cursor->getPosY(), &clap);
			SDL_FreeSurface( loadedSurface );
			SDL_DestroyTexture(tex);
		}
	}
	if(attack || frame>0){
		if(frame ==0){
			frame=15;
		}
		frame--;
		int coordX = tableEntities[0].getPosX();
		int coordY = tableEntities[0].getPosY();
		int orient = tableEntities[0].getEntityOrientation();

		switch(orient){
		case 1:
			coordX-=CASE;
			if(coordX>=0){
				render(pan, coordX, coordY, &cloup[orient-1]);
			}
			break;
		case 2:
			coordY+=CASE;
			if(coordY<=1024){
				render(pan, coordX, coordY, &cloup[orient-1]);
			}
			break;
		case 3:
			coordX+=CASE;
			if(coordX<=768){
				render(pan, coordX, coordY, &cloup[orient-1]);
			}
			break;
		case 4:
			coordY-=CASE;
			if(coordY>=0){
				render(pan, coordX, coordY, &cloup[orient-1]);
			}
			break;
		}

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
