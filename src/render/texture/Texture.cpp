/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Texture.hpp"

Texture::Texture()
{
    //Initialize texture ID
    this->id = 0;

    //Initialize the dimensions
    this->width = 0;
    this->height = 0;
}

Texture::~Texture()
{
    //Free texture data if needed
    freeTexture();
}

bool Texture::loadTextureFromFile( std::string path )
{
    //Texture loading success
    bool textureLoaded = false;

    //Generate and set current image ID
    ILuint imgID = 0;
    ilGenImages( 1, &imgID );
    ilBindImage( imgID );

    //Load image
    ILboolean success = ilLoadImage( path.c_str() );

    //Image loaded successfully
    if( success == IL_TRUE )
    {
        //Convert image to RGBA
        success = ilConvertImage( IL_RGBA, IL_UNSIGNED_BYTE );
        if( success == IL_TRUE )
        {
            //Create texture from file pixels
            textureLoaded = loadTextureFromPixels32( (GLuint*)ilGetData(), (GLuint)ilGetInteger( IL_IMAGE_WIDTH ), (GLuint)ilGetInteger( IL_IMAGE_HEIGHT ) );
        }

        //Delete file from memory
        ilDeleteImages( 1, &imgID );
    }

    //Report error
    if( !textureLoaded )
    {
        printf( "Unable to load %s\n", path.c_str() );
    }

    return textureLoaded;
}

bool Texture::loadTextureFromPixels32( GLuint* pixels, GLuint width, GLuint height )
{
    //Free texture if it exists
    freeTexture();

    //Get texture dimensions
    width = width;
    height = height;

    //Generate texture ID
    glGenTextures( 1, &this->id );

    //Bind texture ID
    glBindTexture( GL_TEXTURE_2D, this->id );

    //Generate texture
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels );

    //Set texture parameters
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

    //Unbind texture
    glBindTexture( GL_TEXTURE_2D, NULL );

    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error loading texture from %p pixels! %s\n", pixels, gluErrorString( error ) );
        return false;
    }

    return true;
}

void Texture::freeTexture()
{
    //Delete texture
    if( this->id != 0 )
    {
        glDeleteTextures( 1, &this->id );
        this->id = 0;
    }

    width = 0;
    height = 0;
}

void Texture::render( GLfloat x, GLfloat y )
{
    //If the texture exists
    if( this->id != 0 )
    {
        //Remove any previous transformations
        glLoadIdentity();

        //Move to rendering point
        glTranslatef( x, y, 0.f );

        //Set texture ID
        glBindTexture( GL_TEXTURE_2D, this->id );

        //Render textured quad
        glBegin( GL_QUADS );
            glTexCoord2f( 0.f, 0.f ); glVertex2f(  0.f, 0.f );
            glTexCoord2f( 1.f, 0.f ); glVertex2f( width, 0.f );
            glTexCoord2f( 1.f, 1.f ); glVertex2f( width, height );
            glTexCoord2f( 0.f, 1.f ); glVertex2f( 0.f, height );
        glEnd();
    }
}

GLuint Texture::getID()
{
    return this->id;
}

GLuint Texture::getWidth()
{
    return this->width;
}

GLuint Texture::getHeight()
{
    return this->height;
}
