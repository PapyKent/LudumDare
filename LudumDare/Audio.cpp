#include "Audio.h"


Audio::Audio(void)
{
	if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
	{
		printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
	}
	//Load music
	ambiant = Mix_LoadMUS( "sound/La_chanson_de_PacMan_1985.wav" );
	if( ambiant == NULL )
	{
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
	}

}


Audio::~Audio(void)
{
	Mix_FreeMusic(ambiant);
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
