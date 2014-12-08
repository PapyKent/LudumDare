#include "Audio.h"


Audio::Audio(void)
{
	if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
	{
		printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
	}
	//Load music
	ambiant = Mix_LoadMUS( "sound/8bit_Dungeon_Boss.wav" );
	if( ambiant == NULL )
	{
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
	}

	gunEffect = Mix_LoadWAV( "sound/piew.wav" );

	if(  gunEffect == NULL ){
		printf( "Failed to load beat effect! SDL_mixer Error: %s\n", Mix_GetError() );
	}

	gameOver = Mix_LoadWAV( "sound/hit.wav" );

	if( gameOver == NULL ){
		printf( "Failed to load beat effect! SDL_mixer Error: %s\n", Mix_GetError() );
	}

	win = Mix_LoadWAV( "sound/win.wav" );

	if(  win == NULL ){
		printf( "Failed to load beat effect! SDL_mixer Error: %s\n", Mix_GetError() );
	}

	menu = Mix_LoadWAV( "sound/menu.wav" );

	if(  menu == NULL ){
		printf( "Failed to load beat effect! SDL_mixer Error: %s\n", Mix_GetError() );
	}
}


Audio::~Audio(void)
{
	Mix_FreeChunk( gunEffect ); Mix_FreeChunk( gameOver ); Mix_FreeChunk( win );Mix_FreeChunk( menu );
	Mix_FreeMusic(ambiant);
	ambiant = NULL;
	gameOver = NULL;
	win= NULL;
	menu = NULL;
	ambiant = NULL;
	Mix_Quit();
}

void Audio::start(int level){

	if( Mix_PlayingMusic() == 0 )
	{
		//Play the music
		Mix_PlayMusic( ambiant, -1 );
	}
}


int Audio::playGunEffect(){
	if( Mix_PlayChannel( -1, gunEffect, 0 ) == -1 ) { return 1; }
	return 0;
}

int Audio::playWinEffect(){
	if( Mix_PlayChannel( -1, win, 0 ) == -1 ) { return 1; }
	return 0;
}

int Audio::playGameOverEffect(){
	if( Mix_PlayChannel( -1, gameOver, 0 ) == -1 ) { return 1; }
	return 0;
}


int Audio::playMenu(){
	if( Mix_PlayChannel( -1,menu, 0 ) == -1 ) { return 1; }
	return 0;
}