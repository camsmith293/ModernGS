#include "Game_Window.hpp";

#include "../global.hpp"

//Creates an instances
Game_Window::Game_Window()
{
    //Initialize non-existent window
    window = NULL;
    mFocus = false;
    bFocus = false;
    fullscreen = false;
    minimized = false;
    width = 1366;
    height = 768;
}

//Creates window
bool Game_Window::init()
{
    bool success = true;
    
    //Create window
    window = SDL_CreateWindow("Modern GS", 
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
            );

    if( window != NULL )
    {
        mFocus = true;
        bFocus = true;
        width = SCREEN_WIDTH;
        height = SCREEN_HEIGHT;
        
        gContext = SDL_GL_CreateContext( window );
        
        //Use OpenGL 3.1 core
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
        
        if( gContext == NULL )
        {
            printf( "OpenGL context could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Use Vsync
            if( SDL_GL_SetSwapInterval( 1 ) < 0 )
            {
                printf( "Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError() );
            }

            //Initialize OpenGL
            if( !renderer.init() )
            {
                printf( "Unable to initialize the renderer!\n" );
                success = false;
            }
        }
    } else {
        success = false;
    }
    return success;
}

//Updates the game window
void Game_Window::update()
{
    renderer.render();
    SDL_GL_SwapWindow( window );
}

//Handles window events
void Game_Window::handleEvent( SDL_Event& e )
{
    //Caption update flag
    bool updateCaption = false;

    switch( e.window.event )
    {
        //Get new dimensions and repaint on window size change
        case SDL_WINDOWEVENT_SIZE_CHANGED:
        width = e.window.data1;
        height = e.window.data2;
        update();
        break;

        //Repaint on exposure
        case SDL_WINDOWEVENT_EXPOSED:
        update();
        break;

        //Mouse entered window
        case SDL_WINDOWEVENT_ENTER:
        mFocus = true;
        updateCaption = true;
        break;

        //Mouse left window
        case SDL_WINDOWEVENT_LEAVE:
        mFocus = false;
        updateCaption = true;
        break;

        //Window has keyboard focus
        case SDL_WINDOWEVENT_FOCUS_GAINED:
        bFocus = true;
        updateCaption = true;
        break;

        //Window lost keyboard focus
        case SDL_WINDOWEVENT_FOCUS_LOST:
        bFocus = false;
        updateCaption = true;
        break;

        //Window minimized
        case SDL_WINDOWEVENT_MINIMIZED:
        minimized = true;
        break;

        //Window maxized
        case SDL_WINDOWEVENT_MAXIMIZED:
        minimized = false;
        break;

        //Window restored
        case SDL_WINDOWEVENT_RESTORED:
        minimized = false;
        break;
    }
}

//Deallocates internals
void Game_Window::free()
{
    renderer.free();

    //Destroy window
    if( window != NULL )
    {
        SDL_DestroyWindow( window );
    }

    mFocus = false;
    bFocus = false;
    width = 0;
    height = 0;
}

//Window dimensions
int Game_Window::getWidth()
{
    return width;
}

int Game_Window::getHeight()
{
    return height;
}

//Window focii
bool Game_Window::hasMouseFocus()
{
    return mFocus;
}

bool Game_Window::hasKeyboardFocus()
{
    return bFocus;
}

bool Game_Window::isMinimized()
{
    return minimized;
}

bool Game_Window::isFullscreen()
{
    return fullscreen;
}