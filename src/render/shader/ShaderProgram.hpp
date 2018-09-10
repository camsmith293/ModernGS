/* 
 * File:   ShaderProgram.hpp
 * Author: cameron
 *
 * Created on May 18, 2018, 3:52 AM
 */

#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

#include "../../Open_Libs.hpp"

#include <stdio.h>
#include <string>

class ShaderProgram
{
public:
    
    // The constructor and destructor    
    ShaderProgram();
    virtual ~ShaderProgram();

    // Function template to load a shader, must be implemented
    virtual bool loadProgram() = 0;

    // Function template to free the shader
    virtual void freeProgram();

    // Sets the loaded shader program as the current program
    bool bind();

    // Restores the default shader program as the current program
    void unbind();

    GLuint getProgramID();

protected:
    
    // Print the logs of the program and shader
    void printProgramLog( GLuint program );
    void printShaderLog( GLuint shader );

    // Compiles the specified file of the specified shader type and returns
    // its program ID
    GLuint loadShaderFromFile( std::string path, GLenum shaderType );

    //Program ID
    GLuint programID;
};

#endif /* SHADER_HPP */

