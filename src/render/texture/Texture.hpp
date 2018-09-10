/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Texture.hpp
 * Author: cameron
 *
 * Created on May 14, 2018, 9:34 PM
 */

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <stdio.h>
#include <string>
#include "../../Open_Libs.hpp"

class Texture
{
    public:
        // Default constuctor and destructor
        Texture();
        ~Texture();

        // Load the image for the texture from the file path
        bool loadTextureFromFile( std::string path );

        bool loadTextureFromPixels32( GLuint* pixels, GLuint width, GLuint height );
        /*
        Pre Condition:
         -A valid OpenGL context
        Post Condition:
         -Creates a texture from the given pixels
         -Reports error to console if texture could not be created
        Side Effects:
         -Binds a NULL texture
        */

        // Free the texture
        void freeTexture();

        void render( GLfloat x, GLfloat y );
        /*
        Pre Condition:
         -A valid OpenGL context
         -Active modelview matrix
        Post Condition:
         -Translates to given position and renders textured quad
        Side Effects:
         -Binds member texture ID
        */

        // Get the ID
        GLuint getID();

        // Get the dimensions
        GLuint getWidth();
        GLuint getHeight();

    private:
        // The ID
        GLuint id;

        // The dimensions
        GLuint width;
        GLuint height;
};

#endif /* TEXTURE_HPP */

