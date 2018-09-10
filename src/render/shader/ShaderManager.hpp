/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ShaderManager.hpp
 * Author: cameron
 *
 * Created on September 8, 2018, 3:04 PM
 */

#ifndef SHADERMANAGER_HPP
#define SHADERMANAGER_HPP

#include "ShaderProgram.hpp"

class ShaderManager {
public:
    
    // Constructor and destructor
    ShaderManager();
    ~ShaderManager();
    
    // Initialize the shader manager and load the default shaders
    bool init();
    
    // Load the default pair of shaders
    GLuint loadShaders();
    
    // Load a pair of shaders
    GLuint loadShaders(std::string vs_path, std::string fs_path);
    
    // Switch the active vertex shader
    bool bindVShader(GLuint vsID);
    
    // Switch the active fragment shader
    bool bindFShader(GLuint fsID);
    
private:
    // The arrays of vertex and fragment shader programs
    GLuint *vertex_shaders;
    GLuint *fragment_shaders;
};

#endif /* SHADERMANAGER_HPP */

