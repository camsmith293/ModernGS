/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Keyboard_Handler.hpp"

void Keyboard_Handler::handleKeys(const Uint8* state) {
    //If a key was pressed
    //printf("Key press\n");
    if( state[SDL_SCANCODE_UP] || 
        state[SDL_SCANCODE_DOWN] ||
        state[SDL_SCANCODE_LEFT] ||
        state[SDL_SCANCODE_RIGHT])
    {
        camera.handleEvent(state);
    }
}

void Keyboard_Handler::setCamera(Camera camera) {
    this->camera = camera;
}

