/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camera.hpp
 * Author: cameron
 *
 * Created on May 14, 2018, 1:17 AM
 */

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Camera.hpp"
#include "../global.hpp"

class Camera {
public:
    
    //Create and destroy the camera
    Camera();
    
    //Initialize the camera
    bool init(int x, int y);
    
    //Handles camera events
    void handleEvent( const Uint8* state );
    
    //Deallocates internals
    void free();
    
private:
    float x, y;
    float scroll_vel;
};

#endif /* CAMERA_HPP */

