#include "ShaderParser.h"
#include <fstream>
#include <iostream>

/*
	std::vector<std::string> uniforms, sourceVector;
	std::unique_ptr<char*> source;
*/
ShaderParser::ShaderParser(std::string fileName) : filename(fileName), source(nullptr)
{
	std::ifstream shaderFile(fileName);

	if(shaderFile.is_open()){
        while(!shaderFile.eof()){
			std::string line;
			getline(shaderFile, line);
			sourceVector.push_back(line);
        }
	}else{
		std::cout << "Failed to open file: " << fileName;
	}

	shaderFile.close();
}


ShaderParser::~ShaderParser()
{

}

ShaderParser::ShaderParser(ShaderParser&& moveTarget) : filename(std::move(moveTarget.filename)), uniforms(std::move(moveTarget.uniforms)),
										  sourceVector(std::move(moveTarget.sourceVector)), source(std::move(moveTarget.source))
{

}

ShaderParser& ShaderParser::operator= (ShaderParser&& rhs)
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
	return uniforms;
}

int ShaderParser::getSrcLength()
{
	return sourceVector.size();
}

std::vector<std::string> ShaderParser::split(std::string target, std::regex& splitter)
{
	//gotten from http://www.cplusplus.com/reference/regex/regex_token_iterator/regex_token_iterator/
	// default constructor = end-of-sequence:
	std::regex_token_iterator<std::string::iterator> rend;
	std::regex_token_iterator<std::string::iterator> values ( target.begin(), target.end(), splitter, -1 );

	std::vector<std::string> splitValues;
	while (values != rend){
		splitValues.push_back(*values++);
	}

	return splitValues;
}
