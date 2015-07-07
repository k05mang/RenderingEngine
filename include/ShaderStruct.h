#pragma once

#include <string>
#include <vector>

class ShaderStruct
{
    private:
        std::vector<std::string> fields;
    public:
        ShaderStruct(std::string& file);
        ~ShaderStruct();

        ShaderStruct(const ShaderStruct&) = delete;
        ShaderStruct& operator= (const ShaderStruct&) = delete;

        ShaderStruct(ShaderStruct&& moveTarget);
        ShaderStruct& operator= (ShaderStruct&& rhs);

        std::vector<std::string> genNames(std::string& base);
};
