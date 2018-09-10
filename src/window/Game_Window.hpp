/* 
 * File:   GameWindow.hpp
 * Author: Cameron
 *
 * Created on May 12, 2018, 7:26 PM
 */

#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include "../Open_Libs.hpp"
#include "../render/Renderer.hpp"

class Game_Window {
public:
    
    //Initializes internals
    Game_Window();

    //Creates window
    bool init();

    //Creates renderer from internal window
    bool createRenderer();
    
    //Update the screen
    void update();

    //Handles window events
    void handleEvent( SDL_Event& e );

    //Deallocates internals
    void free();

    //Window dimensions
    int getWidth();
    int getHeight();

    //Window focii
    bool hasMouseFocus();
    bool hasKeyboardFocus();
    bool isFullscreen();
    bool isMinimized();

private:
    //Window data
    SDL_Window* window;
    
    //OpenGL context
    SDL_GLContext gContext;
    
    //The graphics renderer
    Renderer renderer;
    
    //Window dimensions
    int width;
    int height;

    //Window focus
    bool mFocus;
    bool bFocus;
    bool fullscreen;
    bool minimized;
};

#endif /* GAMEWINDOW_HPP */

