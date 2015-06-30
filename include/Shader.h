#pragma once

#include "ShaderParser.h"
#include <gl/GL.h>

class Shader
{
private:
	GLuint shaderId;
	GLenum type;
	ShaderParser parser;
public:
	Shader(std::string fileName, GLenum shaderType);
	~Shader();
	Shader(const Shader& copy);
	Shader& operator= (const Shader& copy);
	Shader(Shader&& moveTarget);
	Shader& operator=(Shader&& moveTarget);

	/*
		Detach the current shader from the specified program
	*/
	void detach(GLuint program);

	/*
		Delete this shader from the GPU
	*/
	void erase();

	/*
		Compile the shader code for this shader.

		Returns whether or not the shader was compiled successfully
	*/
	bool compile();

	/*
		Parse the file specified by the string passed to this shader object
	*/
	void parse();

	/*
		Retrieves the error log associated with this shader if an error occurred during the compilation process
	*/
	std::string getErrorLog();

	/*
		Gets the list of strings that represent the uniforms parsed from the shader source code
	*/
	std::vector<std::string>& getUniforms();
};

