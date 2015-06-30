#pragma once

#include <string>
#include <vector>
#include <memory>

class ShaderParser
{
private:
	std::string filename;
	std::vector<std::string> uniforms, sourceVector;
	std::unique_ptr<char*> source;
public:
	ShaderParser(std::string fileName);
	~ShaderParser();
	//copy and move constructors are not needed for this class
	ShaderParser(const ShaderParser&) = delete;
	ShaderParser(ShaderParser&&) = delete;
	ShaderParser& operator= (const ShaderParser&) = delete;
	ShaderParser& operator= (ShaderParser&&) = delete;

	/*
		Parses the shader code stored in the file given through the constructor and stores the extracted information
	*/
	void parse();

	/*
		Gets the source code as an OpenGL compliant 2D array
	*/
	char** getSource();

	/*
		Gets the vector from this parser that contains the information for the uniforms connected with this shader
	*/
	std::vector<std::string>& getUniforms();

	/*
		Gets the length of the array for the source code stored by this class
	*/
	int getLength();
};

