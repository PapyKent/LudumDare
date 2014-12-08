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
	if(loadedSurface!=NULL){
		SDL_FreeSurface( loadedSurface );
	}
	if(loadedSurface!=NULL){
		SDL_FreeSurface( loadedSurface2 );
	}

	loadedSurface = SDL_LoadBMP("ghost1.bmp");
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 255, 255 ) );
	ghost = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
	if(loadedSurface!=NULL){
		SDL_FreeSurface( loadedSurface );
	}
	loadedSurface = SDL_LoadBMP("pacman.bmp");
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 255, 255 ) );
	pacman = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );

	if(loadedSurface!=NULL){
		SDL_FreeSurface( loadedSurface );
		loadedSurface = SDL_LoadBMP("junior.bmp");
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 255, 255 ) );
		junior = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );

		if(loadedSurface!=NULL){
			SDL_FreeSurface( loadedSurface );
		}

	loadedSurface = SDL_LoadBMP("sortie.bmp");
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 255, 255 ) );
	sortie = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
	if(loadedSurface!=NULL){
		SDL_FreeSurface( loadedSurface );
	}

		//Clip
		for(int i = 0; i < 18; i++){
			clip[i].x = CASE*i;
			clip[i].y = 0;
			clip[i].w = CASE;
			clip[i].h = CASE;
		}


	}

}
Graphic::~Graphic(void)
{
	SDL_DestroyTexture(bg);
	SDL_DestroyTexture(pan);
	SDL_DestroyTexture(pacman);
	SDL_DestroyTexture(junior);
	SDL_DestroyTexture(ghost);
	SDL_DestroyTexture(sortie);
}

void Graphic::display(SDL_Texture* mTexture, int x, int y, int frame){
	SDL_Rect clap;
	clap.x=0;
	clap.y=0;
	clap.w=32;
	clap.h=32;
	render(mTexture, x, y, &clap);

}

void Graphic::displayBackground(Map map, int niveau){
	int index=0;

	for(int i = 0; i < SCREEN_HEIGHT/32; i++){
		for(int j = 0; j < SCREEN_WIDTH/32; j++){
			index= map.getTab(i, j);
			if(index=='H'){
				if(niveau==2){
					index='0';
				}
			}
			if(index<=57 && index>=48){
				render(bg, i*32, j*32, &clip[index-'0']);
			}else{
				render(bg, i*32, j*32, &clip[index-55]);
			}



		}
	}
	if(niveau==2){
		render(sortie, 0, 0, &clip[0]);
	}

}

void Graphic::refresh(){
	SDL_RenderPresent( gRenderer );
}


bool Graphic::displayEntities(vector<Entity> tableEntities, bool attack){
	bool retour=false;
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
			if(cursor->getNameEntity()=="ghost"){
				render(ghost, cursor->getPosX(), cursor->getPosY(), &clap);
			}else if(cursor->getLoader()=="pacman.bmp"){
				render(pacman, cursor->getPosX(), cursor->getPosY(), &clap);
			}else{
				render(junior, cursor->getPosX(), cursor->getPosY(), &clap);
			}

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
				retour=true;
			}
			break;
		case 2:
			coordY+=CASE;
			if(coordY<=1024){
				render(pan, coordX, coordY, &cloup[orient-1]);
				retour=true;
			}
			break;
		case 3:
			coordX+=CASE;
			if(coordX<=768){
				render(pan, coordX, coordY, &cloup[orient-1]);
				retour=true;
			}
			break;
		case 4:
			coordY-=CASE;
			if(coordY>=0){
				render(pan, coordX, coordY, &cloup[orient-1]);
				retour=true;
			}
			break;
		}

	}


	return retour;
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
