#include "ShaderStruct.h"
using namespace std;

/*
    vector<string> fields;
*/
ShaderStruct::ShaderStruct(string& structure, unordered_map<string, ShaderStruct>& knownStructs)
{

}

ShaderStruct::~ShaderStruct()
{

}

ShaderStruct(ShaderStruct&& moveTarget) : name(move(moveTarget.name)), fields(move(moveTarget.fields))
{

}

ShaderStruct& operator= (ShaderStruct&& rhs)
{
    name(move(moveTarget.name);
    fields = move(moveTarget.fields);

    return *this;
}

vector<string> genNames(string& base)
{
    vector<string> names;
    for(string& field : fields){
        names.push_back(base+field);
    }

    return names;
}
