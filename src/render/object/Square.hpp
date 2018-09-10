/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RenderObject.hpp
 * Author: cameron
 *
 * Created on May 14, 2018, 1:06 AM
 */

#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "../../Open_Libs.hpp"

#include "Object.hpp"

class Square: public Object {
public:
    //Create and destroy the square
    Square();
    Square(GLfloat x,  GLfloat y, GLfloat width, GLfloat height);
    ~Square();
    
    //Load the texture for the square
    bool loadTexture();
    
    //Load the square to the vertex buffer;
    bool loadToVBuffer(Position3D vBuffer[], GLuint v0_index);
    
    //Load the square to the vertex buffer;
    bool loadToIBuffer(GLuint iBuffer[], GLuint i0_index, GLuint v0_index);
    
    // Return how many vertices in the shape
    GLuint getVCount();
    
    // Return how many vertices in the shape
    GLuint getICount();
    
    // Get the number triangles in the object
    GLuint getTriangleCount();
    
    //The dimensions
    GLfloat height, width;
    
    //The texture
    Texture texture;
};

#endif /* RENDEROBJECT_HPP */

