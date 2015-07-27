#pragma once

#include "ShaderUniform.h"
#include <string>
#include <vector>
#include <memory>
#include <utility>
using namespace std;

class ShaderParser
{
private:
	vector<pair<string, ShaderUniform>> uniforms;
	vector<string> sourceVector;
	unique_ptr<char*> source;
public:
	static const string shaderTypes("int|uint|float|double|bool|(d|b|i|u)?vec(2|3|4){1}|d?mat(2|3|4){1}(x(2|3|4){1})?|(u|i)?(sampler|image)(\\d{1}D)?\\w*");//regular expression for determining a basic shader primitive type
									//either basic primitives,or a vector type might be prefixed,or a matrix type which could be prefixed for doubles and could be followed by a dimension qualifier
	static const string layoutQualifier("layout\\(\\s*(\\w+|\\w+\\s*=\\s*\\d+)\\s*\\)");//used for layout qualifier detection when parsing

	ShaderParser(string fileName);
	~ShaderParser();
	ShaderParser(const ShaderParser&) = delete;
	ShaderParser& operator= (const ShaderParser&) = delete;
	ShaderParser(ShaderParser&& moveTarget);
	ShaderParser& operator= (ShaderParser&& rhs);

	/*
		Gets the source code as an OpenGL compliant 2D array
	*/
	char** getSource();

	/*
		Gets the vector from this parser that contains the information for the uniforms connected with this shader
	*/
	vector<pair<string, ShaderUniform>>& getUniforms();

	/*
		Gets the length of the array for the source code stored by this class
	*/
	int getSrcLength();
};

