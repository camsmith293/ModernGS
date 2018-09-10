/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Square.hpp"
//Create a nonexistent square
Square::Square() {
    shape_id = -1;
    
    this->v_count = 4;
    this->i_count = 6;
    
    width = 0;
    height = 0;
}

//Create the square
Square::Square(GLfloat x,  GLfloat y, GLfloat width, GLfloat height) {
    this->pos = {x, y, defaultZ};
    
    this->width = width;
    this->height = height;
    
    this->v_count = 4;
    this->i_count = 6;
    
    //Set quad vertices
    this->vertices = new Position3D[ v_count ];
    Position3D vertex_0 = {0, 0, defaultZ};
    vertices[ 0 ] = vertex_0;

    Position3D vertex_1 = {width, 0, defaultZ};
    vertices[ 1 ] = vertex_1;

    Position3D vertex_2 = {width, -1.f * height, defaultZ};
    vertices[ 2 ] = vertex_2;

    Position3D vertex_3 = {0, -1.f * height, defaultZ};
    vertices[ 3 ] = vertex_3;
    
    //Set quad indices
    this->indices = new GLuint[ i_count ];
    indices[0] = 0;
    indices[1] = 1;
    indices[2] = 2;
    indices[3] = 0;
    indices[4] = 3;
    indices[5] = 2;
    
    
    
}

bool Square::loadToVBuffer(Position3D vBuffer[], GLuint v0_index)
{
    for (int i = 0; i < 4; i++) {
        vBuffer[v0_index + i].x = this->vertices[i].x;
        vBuffer[v0_index + i].y = this->vertices[i].y;
        vBuffer[v0_index + i].z = this->vertices[i].z;
    }
    
    return true;
}

bool Square::loadToIBuffer(GLuint iBuffer[], GLuint i0_index, GLuint v0_index)
{
    iBuffer[i0_index] = v0_index;
    iBuffer[i0_index + 1] = v0_index + 1;
    iBuffer[i0_index + 2] = v0_index + 2;
    iBuffer[i0_index + 3] = v0_index;
    iBuffer[i0_index + 4] = v0_index + 3;
    iBuffer[i0_index + 5] = v0_index + 2;
    
    return true;
}

//Load the texture for the square
bool Square::loadTexture()
{
    //Load texture
    if( !texture.loadTextureFromFile( "06_loading_a_texture/texture.png" ) )
    {
        printf( "Unable to load file texture!\n" );
        return false;
    }

    return true;
}

GLuint Square::getVCount() {
    return this->v_count;
}

GLuint Square::getICount() {
    return this->i_count;
}

GLuint Square::getTriangleCount() {
    return 2;
}

//Destroy the square
Square::~Square() {
    //texture.freeTexture();
    delete [] this->vertices;
}

