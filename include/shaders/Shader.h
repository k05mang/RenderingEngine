#pragma once

#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glcorearb.h>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class Shader
{
private:
	GLuint shaderId;
	GLenum type;
public:
	Shader(string fileName, GLenum shaderType);
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
	string getErrorLog();

};

