/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Camera.hpp"
#include "../global.hpp"

Camera::Camera() {
    x, y = 0.f;
    scroll_vel = 10.f;
}

//Creates the camera
bool Camera::init(int x, int y) {
    this->x = x;
    this->y = y;
    
    return true;
}

//Handles camera events
void Camera::handleEvent( const Uint8* state ) {
    //If a key was pressed
    if( state[SDL_SCANCODE_UP] )
    {
        y = y-scroll_vel;
        if (y < 0) {
            y = 0;
        }
    }
    
    if( state[SDL_SCANCODE_DOWN] )
    {
        y = y+scroll_vel;
        if (y > MAP_HEIGHT - SCREEN_HEIGHT) {
            y = MAP_HEIGHT - SCREEN_HEIGHT ;
        }
    }
    
    if( state[SDL_SCANCODE_LEFT] )
    { 
        x = x-scroll_vel;
        if (x < 0) {
            x = 0;
        }
    }
    
    if ( state[SDL_SCANCODE_RIGHT] )
    {
        x = x+scroll_vel;
        if (x > MAP_WIDTH - SCREEN_WIDTH) {
            x = MAP_WIDTH - SCREEN_WIDTH ;
        }
    }
    //If a key was released
//    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
//    {
//        //Adjust the velocity
//        switch( e.key.keysym.sym )
//        {
//            case SDLK_UP: y += scroll_vel; break;
//            case SDLK_DOWN: y -= scroll_vel; break;
//            case SDLK_LEFT: x += scroll_vel; break;
//            case SDLK_RIGHT: x -= scroll_vel; break;
//        }
//    }
    //Take saved matrix off the stack and reset it
    glMatrixMode( GL_MODELVIEW );
    glPopMatrix();
    glLoadIdentity();

    //Move camera to position
    glTranslatef( -x, -y, 0.f );

    //Save default matrix again with camera translation
    glPushMatrix();
}

