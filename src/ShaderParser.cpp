#include "ShaderParser.h"
#include "ShaderStruct.h"
#include <fstream>
#include <iostream>
#include <unordered_map>
using namespace std;

/*
	vector<string> uniforms, sourceVector;
	unique_ptr<char*> source;
*/
ShaderParser::ShaderParser(string fileName) : filename(fileName), source(nullptr)
{
	ifstream shaderFile(fileName);

	if(shaderFile.is_open()){
        while(!shaderFile.eof()){
			unordered_map<string, ShaderStruct> structures;//hashmap for storing the structures defined in the shader that could be used as uniforms
			string line;//string storing the line of text from the file
			getline(shaderFile, line);
			sourceVector.push_back(line);

			if()
        }
	}else{
		cout << "Failed to open file: " << fileName;
	}

	shaderFile.close();
}


ShaderParser::~ShaderParser()
{

}

ShaderParser::ShaderParser(ShaderParser&& moveTarget) : filename(move(moveTarget.filename)), uniforms(move(moveTarget.uniforms)),
										  sourceVector(move(moveTarget.sourceVector)), source(move(moveTarget.source))
{

}

ShaderParser& ShaderParser::operator= (ShaderParser&& rhs)
{
		filename = move(rhs.filename);
		uniforms = move(rhs.uniforms);
		sourceVector = move(rhs.sourceVector);
		source = move(rhs.source);

		return *this;
}

char** ShaderParser::getSource()
{
	return source.get();
}

vector<string>& ShaderParser::getUniforms()
{
	return uniforms;
}

int ShaderParser::getSrcLength()
{
	return sourceVector.size();
}
