#include "Shader.h"

/*
    GLuint shaderId;
	GLenum type;
	ShaderParser parser;
	std::string filename;
*/
Shader::Shader(std::string fileName, GLenum shaderType) : parser(fileName), type(shaderType), filename(fileName)
{
	shaderId = glCreateShader(shaderType);
}


Shader::~Shader()
{
    glDeleteShader(shaderId);
}

Shader::Shader(Shader&& moveTarget) : shaderId(std::move(moveTarget.shaderId)), type(std::move(moveTarget.type)),
                                      shaderParser(std::move(moveTarget.shaderParser)), filename(std::move(moveTarget.filename))
{

}

Shader& Shader::operator=(Shader&& moveTarget)
{
    shaderId = std::move(moveTarget.shaderId);
    type = std::move(moveTarget.type);
    shaderParser = std::move(moveTarget.shaderParser);
    filename = std::move(moveTarget.filename);

    return *this;
}

void Shader::attach(GLuint program)
{
    glAttachShader(program, shaderId);
}

void Shader::detach(GLuint program)
{
    glDetachShader(program, shaderId);
}

void Shader::erase()
{
    glDeleteShader(shaderId);
}

bool Shader::compile()
{
    glCompileShader(shaderId);
    GLint status;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &status);

    return status;
}

std::string Shader::getErrorLog()
{
    GLint logLength;
    glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &logLength);

    GLchar* logBuffer;
    glGetShaderInfoLog(shaderId, logLength, NULL, logBuffer);
    return std::string(logBuffer);
}

std::vector<std::string>& Shader::getUniforms()
{
    return uniforms;
}
