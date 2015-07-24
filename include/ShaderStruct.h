#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <regex>
using namespace std;

class ShaderStruct
{
    private:
        vector<string> fields;
    public:
        ShaderStruct(string& structure, unordered_map<string, ShaderStruct>& knownStructs);
        ~ShaderStruct();

        ShaderStruct(const ShaderStruct&) = delete;
        ShaderStruct& operator= (const ShaderStruct&) = delete;

        ShaderStruct(ShaderStruct&& moveTarget);
        ShaderStruct& operator= (ShaderStruct&& rhs);

        vector<string> genNames(string& base);
};
