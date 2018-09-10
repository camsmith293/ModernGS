/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Triangle.hpp"

//Create a nonexistent triangle
Triangle::Triangle() {
    this->vertices[ 0 ].x = 0;
    this->vertices[ 0 ].y = 0;

    this->vertices[ 1 ].x = 0;
    this->vertices[ 1 ].y = 0;

    this->vertices[ 2 ].x = 0;
    this->vertices[ 2 ].y = 0;
}

//Create the triangle
Triangle::Triangle(Position3D x, Position3D y, Position3D z)
{
    
    //Set quad vertices
    this->vertices[ 0 ] = x;
    this->vertices[ 1 ] = y;
    this->vertices[ 2 ] = z;
        
}

bool Triangle::loadToVBuffer(Position3D vBuffer[], GLuint v0_index)
{
    for (int i = 0; i < 3; i++) {
        vBuffer[v0_index + i].x = this->vertices[i].x;
        vBuffer[v0_index + i].y = this->vertices[i].y;
    }
    
    return true;
}

bool Triangle::loadToIBuffer(GLuint iBuffer[], GLuint i0_index, GLuint v0_index)
{
    for (int i = 0; i < 3; i++) {
        iBuffer[i0_index + i] = v0_index + i;
    }
    
    return true;
}

//Load the texture for the square
bool Triangle::loadTexture()
{
    //Load texture
    if( !texture.loadTextureFromFile( "06_loading_a_texture/texture.png" ) )
    {
        printf( "Unable to load file texture!\n" );
        return false;
    }

    return true;
}

GLuint Triangle::getVCount() {
    return this->v_count;
}

GLuint Triangle::getICount() {
    return this->i_count;
}

//Destroy the square
Triangle::~Triangle() {
    //texture.freeTexture();
    delete [] this->vertices;
}

