#include "ShaderParser.h"
#include <fstream>

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
			getline(fileShader, line);
			sourceVector.push_back(line);
        }
	}else{
		std::cout << "Failed to open file: "+fileName;
	}

	shaderFile.close();
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
