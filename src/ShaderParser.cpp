#include "ShaderParser.h"
#include "ShaderStruct.h"
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <regex>
using namespace std;

/*
	vector<pair<string, ShaderUniform>> uniforms;
	vector<string> sourceVector;
	unique_ptr<char*> source;
*/
ShaderParser::ShaderParser(string fileName) : source(nullptr)
{
	ifstream shaderFile(fileName);

	if(shaderFile.is_open()){
        while(!shaderFile.eof()){
			unordered_map<string, ShaderStruct> structures;//hashmap for storing the structures defined in the shader that could be used as uniforms
			string line;//string storing the line of text from the file
			getline(shaderFile, line);
			sourceVector.push_back(line+"\n");
			//is the line we are on the start of a uniform declaration
			if(line.find("uniform") != line::npos)){
				//determine if the uniform has been broken up between multiple lines
				if(line.find(";") != line::npos){
					//if the line doesn't have the struct keyword continue
					if(line.find("struct") == line::npos){
						//since it does we know the struct is anonymous and defined across multiple lines
					}else{
						//one or more declarations of uniform values on a single line
						//get the uniform type and the names only
						regex_token_iterator<string::iterator> info{line.begin(), line.end(), regex(layoutQualifier+"\\s*uniform\\s*"), -1};
						//split the names from the uniform type
						vector<string> splitInfo = ShaderStruct::split(*info, regex("\\w+\\s+\\w+"));
					}
				}else{
					/*
						there is a small possibility that the struct qualifier is declared on the next line
						however this is bad coding style and likely not the case so this will not be checked
						Example:

						uniform
						struct
						{
						...
						} [declarations];
					*/
					//the likely case is that the uniform has a list of uniform declarations that was broken
					//onto multiple lines for readability

				}
			}else if(line.find("struct") != line::npos){
				//determine if the struct is an anonymous type or not
				if(){

				}
			}
        }
	}else{
		cout << "Failed to open file: " << fileName;
	}

	shaderFile.close();
}


ShaderParser::~ShaderParser()
{

}

ShaderParser::ShaderParser(ShaderParser&& moveTarget) : uniforms(move(moveTarget.uniforms)),
										  sourceVector(move(moveTarget.sourceVector)), source(move(moveTarget.source))
{

}

ShaderParser& ShaderParser::operator= (ShaderParser&& rhs)
{
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
