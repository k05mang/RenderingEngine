#include "ShaderStruct.h"
using namespace std;

/*
    vector<pair<string, string>> fields;
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

vector<pair<string, string>> genNames(string& base)
{
    vector<pair<string, string>> names;
    for(pair<string, string>& field : fields){
        names.push_back(pair<string, string>(base+"."+field.first, field.second));
    }

    return names;
}

vector<string> ShaderStruct::split(string target, regex delimiter)
{
    //original idea from
    //http://www.cplusplus.com/reference/regex/regex_token_iterator/regex_token_iterator/

    regex_token_iterator<std::string::iterator> seqEnd{};//end of sequence value to compare with

    regex_token_iterator<std::string::iterator> values(target.begin(), target.end(), delimiter, -1);

    vector<string> result{};

    //push all the values into a vector from the iterator
    while(values != seqEnd){
        result.push_back(*values++);
    }

    return result;
}
