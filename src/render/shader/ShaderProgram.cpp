/* 
 * File:   ShaderProgram.cpp
 * Author: cameron
 *
 * Created on May 18, 2018, 3:52 AM
 */

#include "ShaderProgram.hpp"
#include <fstream>

ShaderProgram::ShaderProgram()
{
    programID = NULL;
}

ShaderProgram::~ShaderProgram()
{
    //Free program if it exists
    freeProgram();
}

void ShaderProgram::freeProgram()
{
    //Delete program
    glDeleteProgram( programID );
}

bool ShaderProgram::bind()
{
    //Use shader
    glUseProgram( programID );

    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error binding shader! %s\n", gluErrorString( error ) );
        printProgramLog( programID );
        return false;
    }

    return true;
}

void ShaderProgram::unbind()
{
    //Use default program
    glUseProgram( NULL );
}

GLuint ShaderProgram::getProgramID()
{
    return programID;
}

void ShaderProgram::printProgramLog( GLuint program )
{
    //Make sure name is shader
    if( glIsProgram( program ) )
    {
        //Program log length
        int infoLogLength = 0;
        int maxLength = infoLogLength;

        //Get info string length
        glGetProgramiv( program, GL_INFO_LOG_LENGTH, &maxLength );

        //Allocate string
        char* infoLog = new char[ maxLength ];

        //Get info log
        glGetProgramInfoLog( program, maxLength, &infoLogLength, infoLog );
        if( infoLogLength > 0 )
        {
            //Print Log
            printf( "%s\n", infoLog );
        }

        //Deallocate string
        delete[] infoLog;
    }
    else
    {
        printf( "Name %d is not a program\n", program );
    }
}

void ShaderProgram::printShaderLog( GLuint shader )
{
    //Make sure name is shader
    if( glIsShader( shader ) )
    {
        //Shader log length
        int infoLogLength = 0;
        int maxLength = infoLogLength;

        //Get info string length
        glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &maxLength );

        //Allocate string
        char* infoLog = new char[ maxLength ];

        //Get info log
        glGetShaderInfoLog( shader, maxLength, &infoLogLength, infoLog );
        if( infoLogLength > 0 )
        {
            //Print Log
            printf( "%s\n", infoLog );
        }

        //Deallocate string
        delete[] infoLog;
    }
    else
    {
        printf( "Name %d is not a shader\n", shader );
    }
}

GLuint ShaderProgram::loadShaderFromFile( std::string path, GLenum shaderType )
{
    //Open file
    GLuint shaderID = 0;
    std::string shaderString;
    std::ifstream sourceFile( path.c_str() );

    //Source file loaded
    if( sourceFile )
    {
        //Get shader source
        shaderString.assign( ( std::istreambuf_iterator< char >( sourceFile ) ), std::istreambuf_iterator< char >() );

        //Create shader ID
        shaderID = glCreateShader( shaderType );

        //Set shader source
        const GLchar* shaderSource = shaderString.c_str();
        glShaderSource( shaderID, 1, (const GLchar**)&shaderSource, NULL );

        //Compile shader source
        glCompileShader( shaderID );

        //Check shader for errors
        GLint shaderCompiled = GL_FALSE;
        glGetShaderiv( shaderID, GL_COMPILE_STATUS, &shaderCompiled );
        if( shaderCompiled != GL_TRUE )
        {
            printf( "Unable to compile shader %d!\n\nSource:\n%s\n", shaderID, shaderSource );
            printShaderLog( shaderID );
            glDeleteShader( shaderID );
            shaderID = 0;
        }
    } else {
        printf( "Unable to open file %s\n", path.c_str() );
    }

    return shaderID;
}
