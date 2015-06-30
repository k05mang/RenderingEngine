#pragma once

class ShaderUniform
{
    private:
        unsigned int type;
        GLint location;
    public:
        ShaderUniform();
        ~ShaderUniform();
        ShaderUniform(const ShaderUniform& other);
        ShaderUniform& operator=(const ShaderUniform& other);
        ShaderUniform(ShaderUniform&& moveTarget);
        ShaderUniform& operator= (ShaderUniform&& rhs);
};
