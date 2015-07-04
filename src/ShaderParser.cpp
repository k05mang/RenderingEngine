#include "ShaderParser.h"
#include <fstream>

/*
	std::vector<std::string> uniforms, sourceVector;
	std::unique_ptr<char*> source;
*/
ShaderParser::ShaderParser(std::string fileName) : filename(fileName), source(nullptr)
{
	std::ifstream shaderFile
}


ShaderParser::~ShaderParser()
{

}

ShaderParser(ShaderParser&& moveTarget) : filename(std::move(moveTarget.filename)), uniforms(std::move(moveTarget.uniforms)),
										  sourceVector(std::move(moveTarget.sourceVector)), source(std::move(moveTarget.source))
{

}

ShaderParser& operator= (ShaderParser&& rhs)
{
		filename = std::move(rhs.filename);
		uniforms = std::move(rhs.uniforms);
		sourceVector = std::move(rhs.sourceVector);
		source = std::move(rhs.source);

		return *this;
}

char** ShaderParser::getSource()
{
	return source.get();
}

std::vector<std::string>& ShaderParser::getUniforms()
{

}

int ShaderParser::getLength()
{

}
