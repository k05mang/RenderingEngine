#include "ShaderParser.h"


ShaderParser::ShaderParser(std::string fileName) : filename(fileName), source(nullptr)
{
}


ShaderParser::~ShaderParser()
{
}

void ShaderParser::parse()
{

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
