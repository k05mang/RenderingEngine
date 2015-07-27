#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <regex>
#include <utility>
using namespace std;

class ShaderStruct
{
    private:
        vector<pair<string, string>> fields;//first value of the pair is the uniform name, the second value is the type of uniform
    public:
        ShaderStruct(string& structure, unordered_map<string, ShaderStruct>& knownStructs);
        ~ShaderStruct();

        ShaderStruct(const ShaderStruct&) = delete;
        ShaderStruct& operator= (const ShaderStruct&) = delete;

        ShaderStruct(ShaderStruct&& moveTarget);
        ShaderStruct& operator= (ShaderStruct&& rhs);

        vector<pair<string, string>> genNames(string& base);

        static vector<string> split(string target, regex delimiter);
};
