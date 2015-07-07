#include "ShaderStruct.h"

/*
    std::vector<std::string> fields;
*/
ShaderStruct::ShaderStruct(std::string& file)
{

}

ShaderStruct::~ShaderStruct()
{

}

ShaderStruct(ShaderStruct&& moveTarget) : name(std::move(moveTarget.name)), fields(std::move(moveTarget.fields))
{

}

ShaderStruct& operator= (ShaderStruct&& rhs)
{
    name(std::move(moveTarget.name);
    fields = std::move(moveTarget.fields);

    return *this;
}

std::vector<std::string> genNames(std::string& base)
{
    std::vector<std::string> names;
    for(std::string& field : fields){
        names.push_back(base+field);
    }

    return names;
}
