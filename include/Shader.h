#pragma once

#include "ShaderParser.h"
#include <GL/gl.h>
#include <glm.hpp>

class Shader
{
private:
	GLuint shaderId;
	GLenum type;
	ShaderParser parser;
	std::string filename;
public:
	Shader(std::string fileName, GLenum shaderType);
	~Shader();
	Shader(const Shader& copy) = delete;
	Shader& operator= (const Shader& copy) = delete;
	Shader(Shader&& moveTarget);
	Shader& operator=(Shader&& moveTarget);

	/*
		Attach this shader to the specified shader program

		program: The handle of the shader program generated by OpenGL
	*/
	void attach(GLuint program);

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
		Retrieves the error log associated with this shader if an error occurred during the compilation process
	*/
	std::string getErrorLog();

	/*
		Gets the list of strings that represent the uniforms parsed from the shader source code
	*/
	std::vector<std::string>& getUniforms();

};

