#ifndef GL_GLEXT_PROTOTYPES
#define GL_GLEXT_PROTOTYPES
#endif // GL_GLEXT_PROTOTYPES

#include "shaders/Shader.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>
using namespace std;

/*
    GLuint shaderId;
	GLenum type;
*/
Shader::Shader(string fileName, GLenum shaderType) : type(shaderType)
{
    ifstream shaderFile(fileName);
    int curline = 0;
    int count = 10;
    char** source = new char*[count];
    int* lengths = new int[count];

	if(shaderFile.is_open()){
        while(!shaderFile.eof()){
			string line;//string storing the line of text from the file
			getline(shaderFile, line);
			if(curline == count){
                count += 10;
                //increase the size of the arrays to account for more data
                realloc(source, count*sizeof(char*));
                realloc(lengths, count*sizeof(int));
			}
			int lineLength = line.length();
			//record data into new positions in arrays
			lengths[curline] = lineLength;
            source[curline] = new char[lineLength];
            line.copy(source[curline], lineLength);
			curline++;
        }
	}else{
		cout << "Failed to open file: " << fileName;
	}

	shaderFile.close();

	shaderId = glCreateShader(shaderType);
	glShaderSource(shaderId, curline-1, source, lengths);

	//clean up the dynamically allocated arrays source and lengths
	for(int cur = 0; cur < curline; cur++){
        delete[] source[cur];
	}
	delete[] source;
	delete[] lengths;
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
      if(this == &rhs) return *this;
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

    GLchar* logBuffer = new GLchar[logLength];
    glGetShaderInfoLog(shaderId, logLength, NULL, logBuffer);
    string log(logBuffer, logLength);
    delete[] logBuffer;
    return log;
}
