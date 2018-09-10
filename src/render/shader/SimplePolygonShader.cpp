/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "SimplePolygonShader.hpp"

SimplePolygonShader::SimplePolygonShader()
{
	vertexPos3DLocation = 0;
	multiColor1Location = 0;
	multiColor2Location = 0;

	projectionMatrixLocation = 0;
	modelViewMatrixLocation = 0;
}

bool SimplePolygonShader::loadProgram() {
    //Generate program
    programID = glCreateProgram();

    //Load vertex shader
    GLuint vertexShader = loadShaderFromFile( "src/render/shader/glsl/SimplePolygonShader.glvs", GL_VERTEX_SHADER );

    //Check for errors
    if( vertexShader == 0 )
    {
        glDeleteProgram( programID );
        programID = 0;
        return false;
    }

    //Attach vertex shader to program
    glAttachShader( programID, vertexShader );

    //Create fragment shader
    GLuint fragmentShader = loadShaderFromFile( "src/render/shader/glsl/SimplePolygonShader.glfs", GL_FRAGMENT_SHADER );

    //Check for errors
    if( fragmentShader == 0 )
    {
        glDeleteShader( vertexShader );
        glDeleteProgram( programID );
        programID = 0;
        return false;
    }

    //Attach fragment shader to program
    glAttachShader( programID, fragmentShader );

    //Link program
    glLinkProgram( programID );

    //Check for errors
    GLint programSuccess = GL_TRUE;
    glGetProgramiv( programID, GL_LINK_STATUS, &programSuccess );
    if( programSuccess != GL_TRUE )
    {
        printf( "Error linking program %d!\n", programID );
        printProgramLog( programID );
        glDeleteShader( vertexShader );
        glDeleteShader( fragmentShader );
        glDeleteProgram( programID );
        programID = 0;
        return false;
    }

    //Clean up excess shader references
    glDeleteShader( vertexShader );
    glDeleteShader( fragmentShader );

    //Get variable locations
    vertexPos3DLocation = glGetAttribLocation( programID, "VertexPos3D" );
    if( vertexPos3DLocation == -1 )
    {
        printf( "%s is not a valid glsl program variable!\n", "VertexPos3D" );
    }

    multiColor1Location = glGetAttribLocation( programID, "MultiColor1" );
    if( multiColor1Location == -1 )
    {
        printf( "%s is not a valid glsl program variable!\n", "MultiColor1" );
    }

    multiColor2Location = glGetAttribLocation( programID, "MultiColor2" );
    if( multiColor2Location == -1 )
    {
        printf( "%s is not a valid glsl program variable!\n", "MultiColor2" );
    }

    projectionMatrixLocation = glGetUniformLocation( programID, "ProjectionMatrix" );
    if( projectionMatrixLocation == -1 )
    {
        printf( "%s is not a valid glsl program variable!\n", "ProjectionMatrix" );
    }

    modelViewMatrixLocation = glGetUniformLocation( programID, "ModelViewMatrix" );
    if( modelViewMatrixLocation == -1 )
    {
        printf( "%s is not a valid glsl program variable!\n", "ModelViewMatrix" );
    }

    return true;
}

void SimplePolygonShader::setVertexPointer( GLsizei stride, const GLvoid* data )
{
    glVertexAttribPointer( vertexPos3DLocation, 2, GL_FLOAT, GL_FALSE, stride, data );
}

void SimplePolygonShader::setColor1Pointer( GLsizei stride, const GLvoid* data )
{
    glVertexAttribPointer( multiColor1Location, 4, GL_FLOAT, GL_FALSE, stride, data );
}

void SimplePolygonShader::setColor2Pointer( GLsizei stride, const GLvoid* data )
{
    glVertexAttribPointer( multiColor2Location, 4, GL_FLOAT, GL_FALSE, stride, data );
}

void SimplePolygonShader::enableDataPointers()
{
    glEnableVertexAttribArray( vertexPos3DLocation );
    glEnableVertexAttribArray( multiColor1Location );
    glEnableVertexAttribArray( multiColor2Location );
}

void SimplePolygonShader::disableDataPointers()
{
    glDisableVertexAttribArray( multiColor2Location );
    glDisableVertexAttribArray( multiColor1Location );
    glDisableVertexAttribArray( vertexPos3DLocation );
}

void SimplePolygonShader::setProjection( glm::mat4 matrix )
{
    projectionMatrix = matrix;
}

void SimplePolygonShader::setModelView( glm::mat4 matrix )
{
    modelViewMatrix = matrix;
}

void SimplePolygonShader::leftMultProjection( glm::mat4 matrix )
{
    projectionMatrix = matrix * projectionMatrix;
}

void SimplePolygonShader::leftMultModelView( glm::mat4 matrix )
{
    modelViewMatrix = matrix * modelViewMatrix;
}

void SimplePolygonShader::updateProjection()
{
    glUniformMatrix4fv(	projectionMatrixLocation, 1, GL_FALSE, glm::value_ptr( projectionMatrix ) );
}

void SimplePolygonShader::updateModelView()
{
    glUniformMatrix4fv( modelViewMatrixLocation, 1, GL_FALSE, glm::value_ptr( modelViewMatrix ) );
}

