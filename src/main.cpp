#include <sstream>

#include "window/Game_Window.hpp"
#include "render/Camera.hpp"
#include "map/Map.hpp"
#include "input/Keyboard_Handler.hpp"

#include "global.hpp"

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The game window
Game_Window window;

//The keyboard handler
Keyboard_Handler kHandler;

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        if( !window.init() )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        
    }
    
    return success;
}

void close()
{
    //Destroy window
    window.free();

    //Quit SDL subsystems
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    } else {
        //Main loop flag
        bool quit = false;

        //Event handler
        SDL_Event e;

        //Enable text input
        SDL_StartTextInput();

        //While application is running
        while( !quit )
        {
            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 )
            {
                //User requests quit
                if( e.type == SDL_QUIT ) {
                    quit = true;
                } else if( e.type == SDL_WINDOWEVENT ) { 
                    window.handleEvent( e );
                } else if ( e.type == SDL_KEYDOWN ||
                            e.type == SDL_KEYUP) {
                    //Handle keyboard events
                    kHandler.handleKeys( SDL_GetKeyboardState(NULL) );
                }
            }

            //Update screen
            window.update();
        }

        //Disable text input
        SDL_StopTextInput();
    }

    //Free resources and close SDL
    close();

    return 0;
}