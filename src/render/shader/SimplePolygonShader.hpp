/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimplePolygonShader.hpp
 * Author: cameron
 *
 * Created on September 8, 2018, 4:32 PM
 */

#ifndef SIMPLEPOLYGONSHADER_HPP
#define SIMPLEPOLYGONSHADER_HPP

#include "ShaderProgram.hpp"

class SimplePolygonShader: public ShaderProgram {
public:
    // Initializes the shader
    SimplePolygonShader();
    
    // Load the vertex and fragment shaders for this shader program
    bool loadProgram();

    // Sets the vertex attribute pointer for the currently bound simple shader
    void setVertexPointer( GLsizei stride, const GLvoid* data );

    // Sets the first color attribute pointer for the currently bound simple shader
    void setColor1Pointer( GLsizei stride, const GLvoid* data );

    // Sets the second color attribute pointer for the currently bound simple shader
    void setColor2Pointer( GLsizei stride, const GLvoid* data );

    // Enables all attributes for the currently bound simple shader
    void enableDataPointers();

    // Disables all attributes for the currently bound simple shader
    void disableDataPointers();

    // Set the Model and Projection matrices
    void setProjection( glm::mat4 matrix );
    void setModelView( glm::mat4 matrix );

    // Left multiply the Model and Projection matrices
    void leftMultProjection( glm::mat4 matrix );
    void leftMultModelView( glm::mat4 matrix );

    // Update the Model and Projection matrices
    void updateProjection();
    void updateModelView();
    
private:
    //Attribute locations
    GLint vertexPos3DLocation;
    GLint multiColor1Location;
    GLint multiColor2Location;

    // Projection matrix
    glm::mat4 projectionMatrix;
    GLint projectionMatrixLocation;

    // Modelview matrix
    glm::mat4 modelViewMatrix;
    GLint modelViewMatrixLocation; 
};

#endif /* SIMPLEPOLYGONSHADER_HPP */

