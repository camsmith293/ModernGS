/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Renderer.hpp
 * Author: cameron
 *
 * Created on May 14, 2018, 6:29 PM
 */

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "../Open_Libs.hpp"
#include "World.hpp"
#include "shader/SimplePolygonShader.hpp"

//Viewport mode
enum ViewPortMode
{
    VIEWPORT_MODE_FULL,
    VIEWPORT_MODE_HALF_CENTER,
    VIEWPORT_MODE_HALF_TOP,
    VIEWPORT_MODE_QUAD,
    VIEWPORT_MODE_RADAR
};

class Renderer {
public:
    Renderer();
    
    // Initializes the renderer
    bool init();
    
    // Initializes OpenGL
    bool initGL();
    
    // Loads the shader programs
    bool loadShaders();
    
    // Load the contents of the world
    bool loadWorld();
    
    // Render the scene
    void render();
    
    // Change the viewing mode
    void setViewportMode(int mode);
    
    // Deallocates internals
    void free();
    
private:
    // Render flag
    bool gRenderQuad = true;
    
    // The viewport mode
    int viewportMode = VIEWPORT_MODE_FULL;
    
    // Graphics program
    GLuint programID = 0;
    GLuint VertexArrayID = 0;
    GLint vertexPos2DLocation = -1;
    GLuint VBO = 0;
    GLuint IBO = 0;
    
    // The world of things to be rendered
    World world;
    
    // A simple shader for rendering a polygon
    SimplePolygonShader simplePolygonShader;
};

#endif /* RENDERER_HPP */

