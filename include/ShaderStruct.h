#pragma once

#include <string>
#include <vector>
#include <unordered_map>

class ShaderStruct
{
    private:
        std::vector<std::string> fields;
    public:
        ShaderStruct(std::string& structure, std::unordered_map<std::string, ShaderStruct>& knownStructs);
        ~ShaderStruct();

        ShaderStruct(const ShaderStruct&) = delete;
        ShaderStruct& operator= (const ShaderStruct&) = delete;

        ShaderStruct(ShaderStruct&& moveTarget);
        ShaderStruct& operator= (ShaderStruct&& rhs);

        std::vector<std::string> genNames(std::string& base);
};
