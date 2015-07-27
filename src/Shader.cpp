#include "Shader.h"
#include <fstream>
using namespace std;

/*
    GLuint shaderId;
	GLenum type;
*/
Shader::Shader(string fileName, GLenum shaderType) : type(shaderType), source(nullptr)
{
    ifstream shaderFile(fileName);

	if(shaderFile.is_open()){
        while(!shaderFile.eof()){
			string line;//string storing the line of text from the file
			getline(shaderFile, line);
			sourceVector.push_back(line+"\n");
        }
        source = unique_ptr<char**>(new char*[sourceVector.size()]);
        for(int curLine = 0; curLine < sourceVector.size(); curLine++){
            source[curLine] = sourceVector[curLine].data();
        }
	}else{
		cout << "Failed to open file: " << fileName;
	}

	shaderFile.close();
	shaderId = glCreateShader(shaderType);
	glShaderSource(shaderId, sourceVector.size(), source.get(), NULL);
}


Shader::~Shader()
{
    glDeleteShader(shaderId);
}

Shader::Shader(Shader&& moveTarget) : shaderId(move(moveTarget.shaderId)), type(move(moveTarget.type))
{

}

Shader& Shader::operator=(Shader&& moveTarget)
{
    shaderId = move(moveTarget.shaderId);
    type = move(moveTarget.type);

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
