#include "ShaderUniform.h"

ShaderUniform::ShaderUniform()
{
    //ctor
}

ShaderUniform::~ShaderUniform()
{
    //dtor
}

ShaderUniform::ShaderUniform(const ShaderUniform& other)
{
    //copy ctor
}

ShaderUniform& ShaderUniform::operator=(const ShaderUniform& rhs)
{
    if (this != &rhs){// handle self assignment

    }

    return *this;
}

ShaderUniform(ShaderUniform&& moveTarget)
{

}

ShaderUniform& operator= (ShaderUniform&& rhs)
{

}
