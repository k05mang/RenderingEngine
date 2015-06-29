#include "Shader.h"

Shader::Shader(std::string fileName, GLenum shaderType) : parser(fileName), type(shaderType)
{
	shaderId = glCreateShader(type);
}


Shader::~Shader()
{
}

Shader::Shader(const Shader& copy)
{

}

Shader& Shader::operator= (const Shader& copy)
{

}

Shader::Shader(Shader&& moveTarget)
{

}

Shader& Shader::operator=(Shader&& moveTarget)
{

}

void Shader::detach(GLuint program)
{

}

void Shader::erase()
{

}

bool Shader::compile()
{

}

void Shader::parse()
{

}

std::string Shader::getErrorLog()
{

}

std::vector<std::string>& Shader::getUniforms()
{

}
