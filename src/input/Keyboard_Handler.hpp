/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Keyboard_Handler.hpp
 * Author: cameron
 *
 * Created on May 16, 2018, 10:56 PM
 */

#ifndef KEYBOARD_HANDLER_HPP
#define KEYBOARD_HANDLER_HPP

#include "../Open_Libs.hpp"
#include "../global.hpp"
#include "../render/Camera.hpp"

class Keyboard_Handler {
public:
    void handleKeys(const Uint8* state);
    void setCamera(Camera camera);
private:
    Camera camera;
};

#endif /* KEYBOARD_HANDLER_HPP */

