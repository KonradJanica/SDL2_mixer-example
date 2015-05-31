#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#define WAV_PATH "beat.wav"
#define MUS_PATH "ok.ogg"

#define SCREEN_W 	1024
#define SCREEN_H 	768
#define SCREEN_BPP 	24

// Our wave file
Mix_Chunk *wave = NULL;
// Our music file
Mix_Music *music = NULL;

SDL_Window* gWindow;

void close()
{
    //Deallocate surface
    /* SDL_FreeSurface( gHelloWorld ); */
    /* gHelloWorld = NULL; */

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

int main(int argc, char* argv[]){

  // Initialize SDL.
  /* if (SDL_Init(SDL_INIT_AUDIO) < 0) */
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    return -1;

  //Create window
  int SCREEN_WIDTH = 300;
  int SCREEN_HEIGHT = 300;
  gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

  //Initialize SDL_mixer 
  if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) 
    return -1; 

  // Load our sound effect
  wave = Mix_LoadWAV(WAV_PATH);
  if (wave == NULL)
    return -1;

  // Load our music
  music = Mix_LoadMUS(MUS_PATH);
  if (music == NULL)
    return -1;

  if ( Mix_PlayChannel(-1, wave, 0) == -1 )
    return -1;

  if ( Mix_PlayMusic( music, -1) == -1 )
    return -1;

  //Event handler
  SDL_Event e;
  while ( Mix_PlayingMusic() ) {
    //Handle events on queue
    while( SDL_PollEvent( &e ) != 0 )
    {
      //User requests quit
      if( e.type == SDL_QUIT )
      {
        close();
      }
      //User presses a key
      else if( e.type == SDL_KEYDOWN )
      {
        //Select surfaces based on key press
        switch( e.key.keysym.sym )
        {
          case SDLK_SPACE:
            Mix_PlayChannel(-1, wave, 0);
            break;
          case SDLK_LEFT:
            printf("LEFT\n");
            break;
        }
      }
    }
  }

  // clean up our resources
  Mix_FreeChunk(wave);
  Mix_FreeMusic(music);

  // quit SDL_mixer
  Mix_CloseAudio();

  return 0;
}
