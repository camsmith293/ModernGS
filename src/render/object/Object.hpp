/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Object.hpp
 * Author: cameron
 *
 * Created on August 23, 2018, 5:16 PM
 */

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "../Position3D.hpp"
#include "../../Open_Libs.hpp"
#include "../texture/Texture.hpp"
#include "../shader/SimplePolygonShader.hpp"

class Object {
protected:
    
    // The id of the square in the world
    GLuint shape_id;
    
    // The vertex count of an object
    GLuint v_count;
    
    // The index count of an object
    GLuint i_count;
    
    // The default z-plane rendered
    GLfloat defaultZ = 0.f;
    
    // The texture of the object
    Texture* texture;
    
public:
    
    // Get the number of vertices
    virtual GLuint getVCount() = 0;
    
    // Get the number of indices
    virtual GLuint getICount() = 0;
    
    // Get the number triangles in the object
    virtual GLuint getTriangleCount();
    
        // The location of object
    Position3D pos;
    
    // The vertices of the object
    Position3D* vertices;
    
    // The indices of the object
    GLuint* indices;
    
    // VBO names
    GLuint objectVBO = NULL;
    GLuint objectRGBYVBO = NULL;
    GLuint objectCYMWVBO = NULL;
    GLuint objectGrayVBO = NULL;
    GLuint objectIBO = NULL;
    
    // A pointer to the Vertex Array Object corresponding to this object
    GLuint objectVAO = NULL;
    
    // The shader used to shade this object
    SimplePolygonShader* shader;
    
};

#endif /* OBJECT_HPP */

