/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Renderer.hpp"
#include "../global.hpp"

using namespace glm;

Renderer::Renderer() {
    
}

bool Renderer::initGL()
{
    //Initialize GLEW
    GLenum glewError = glewInit();
    if( glewError != GLEW_OK )
    {
        printf( "Error initializing GLEW! %s\n", glewGetErrorString( glewError ) );
        return false;
    }

    //Make sure OpenGL 3.0 is supported
    if( !GLEW_VERSION_3_0 )
    {
        printf( "OpenGL 3.0 not supported!\n" );
        return false;
    }

    //Set the viewport
    glViewport( 0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT );

    //Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );

    //Enable texturing
    glEnable( GL_TEXTURE_2D );

    //Set blending
    glEnable( GL_BLEND );
    glDisable( GL_DEPTH_TEST );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        return false;
    }

    //Initialize DevIL and DevILU
    ilInit();
    iluInit();
    ilClearColour( 255, 255, 255, 000 );

    //Check for error
    ILenum ilError = ilGetError();
    if( ilError != IL_NO_ERROR )
    {
        printf( "Error initializing DevIL! %s\n", iluErrorString( ilError ) );
        return false;
    }

    return true;
}

bool Renderer::loadShaders() {
    //Load double multicolor shader program
    if( !simplePolygonShader.loadProgram() )
    {
        printf( "Unable to load double multicolor shader!\n" );
        return false;
    }

    //Bind double multicolor shader program
    simplePolygonShader.bind();

    //Initialize projection
    simplePolygonShader.setProjection( glm::ortho<GLfloat>( 0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0 ) );
    simplePolygonShader.updateProjection();

    //Initialize modelview
    simplePolygonShader.setModelView( glm::mat4() );
    simplePolygonShader.updateModelView();
    
    return true;
}

bool Renderer::loadWorld() {
    // Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );
    
    // Initialize the world
    if ( !this->world.init() ) {
        printf( "Failed to initialize the world!" );
    }
    
    // Add the objects to the world
    this->world.addTestObjects();
    
    for (ObjectList::iterator 
        it=world.getObjects().begin();
        it != world.getObjects().end();
        ++it)
    {
        Object* object = *it;
        object->shader->setModelView( glm::translate<GLfloat>( glm::vec3(
            object->pos.x, 
            object->pos.y, 
            object->pos.z
        )));
        object->shader->updateModelView();
        
        glBindVertexArray( object->objectVAO );
        glDrawElements( GL_TRIANGLES, object->getVCount(), GL_UNSIGNED_INT, NULL);
    }
    
    return true;
}

bool Renderer::init() {
    if( !initGL() )
    {
        printf( "Error initializing OpenGL! %s\n");
        return false;
    }
    
    //Load graphics programs
    if( !loadShaders() )
    {
        printf( "Unable to load shader programs!\n" );
        return false;
    }
    
    if( !loadWorld() ) {
        printf( "Unable to load the objects of the world!\n" );
        return false;
    }
    
    return true;
}

void Renderer::render() {
    // Clear the color buffer
    glClear( GL_COLOR_BUFFER_BIT );
    
    /* Translate each objects shader to the objects location,
    bind its VAO, enable its attributes, and draw */
    for (ObjectList::iterator 
        it=world.getObjects().begin();
        it != world.getObjects().end();
        ++it)
    {
        Object* object = *it;
        object->shader->setModelView( glm::translate<GLfloat>( glm::vec3(
            object->pos.x, 
            object->pos.y, 
            object->pos.z
        )));
        object->shader->updateModelView();
        
        glBindVertexArray( object->objectVAO );
        glDrawElements( GL_TRIANGLES, object->getVCount(), GL_UNSIGNED_INT, NULL);
    }
}

//Deallocates internals
void Renderer::free()
{
    // Cleanup the VBO
    glDeleteBuffers(1, &VBO);
    
    // Deallocate program
    glDeleteProgram( programID );
    
    // Clear the world
    this->world.free();
}