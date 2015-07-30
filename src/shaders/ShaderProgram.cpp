
#ifndef GL_GLEXT_PROTOTYPES
#define GL_GLEXT_PROTOTYPES
#endif // GL_GLEXT_PROTOTYPES

#include "shaders/ShaderProgram.h"
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glcorearb.h>

ShaderProgram::ShaderProgram()
{
    programId = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(programId);
}

void ShaderProgram::bind()
{
    glUseProgram(programId);
}

void ShaderProgram::unbind()
{
    glUseProgram(0);
}

void ShaderProgram::erase()
{
    glDeleteProgram(programId);
    programId = 0;
}

void ShaderProgram::add(Shader shader)
{
    shader.attach(programId);
}

bool ShaderProgram::link()
{
    GLint status;
    glLinkProgram(programId);
    glGetProgramiv(programId, GL_LINK_STATUS, &status);

    return status;
}

string ShaderProgram::getErrorLog()
{
    GLint logLength;
    glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &logLength);

    GLchar* logBuffer = new GLchar[logLength];
    glGetProgramInfoLog(programId, logLength, NULL, logBuffer);
    string log(logBuffer, logLength);
    delete[] logBuffer;
}
