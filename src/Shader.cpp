#include "Shader.h"
using namespace std;

/*
    GLuint shaderId;
	GLenum type;
	parser parser;
	string filename;
*/
Shader::Shader(string fileName, GLenum shaderType) : parser(fileName), type(shaderType), filename(fileName)
{
	shaderId = glCreateShader(shaderType);
}


Shader::~Shader()
{
    glDeleteShader(shaderId);
}

Shader::Shader(Shader&& moveTarget) : shaderId(move(moveTarget.shaderId)), type(move(moveTarget.type)),
                                      parser(move(moveTarget.parser)), filename(move(moveTarget.filename))
{

}

Shader& Shader::operator=(Shader&& moveTarget)
{
    shaderId = move(moveTarget.shaderId);
    type = move(moveTarget.type);
    parser = move(moveTarget.parser);
    filename = move(moveTarget.filename);

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

string Shader::getErrorLog()
{
    GLint logLength;
    glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &logLength);

    GLchar* logBuffer;
    glGetShaderInfoLog(shaderId, logLength, NULL, logBuffer);
    return string(logBuffer);
}

vector<pair<string, ShaderUniform>>& Shader::getUniforms()
{
    return parser.getUniforms();
}
