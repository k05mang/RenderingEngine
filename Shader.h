#pragma once

#include "ShaderParser.h"

class Shader
{
private:
	int shaderId;
	ShaderParser parser;
public:
	Shader();
	~Shader();

	void detach();
	void erase();
	bool compile();
	void parse();
	std::string getErrorLog();
	std::vector<std::string>& getUniforms();
};

