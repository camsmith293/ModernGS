/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Triangle.hpp
 * Author: cameron
 *
 * Created on July 1, 2018, 10:00 PM
 */

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "../../Open_Libs.hpp"
#include "Object.hpp"

class Triangle: public Object 
{
public:
    // Create and destroy the square
    Triangle();
    Triangle(Position3D x, Position3D y, Position3D z);
    ~Triangle();
    
    // Load the texture for the square
    bool loadTexture();
    
    // Load the square to the graphics buffers;
    bool loadToVBuffer(Position3D vBuffer[], GLuint v0_index);
    bool loadToIBuffer(GLuint iBuffer[], GLuint i0_index, GLuint v0_index);
    
    // Return how many vertices in the shape
    GLuint getVCount();
    
    // Return how many vertices in the shape
    GLuint getICount();
    
private:
    // The vertex count of a triangle
    GLuint v_count = 3;
    
    // The index count of a triangle
    GLuint i_count = 3;
    
    // The vertices of the triangle
    Position3D vertices[3];
    
    //The texture
    Texture texture;
};

#endif /* TRIANGLE_HPP */

