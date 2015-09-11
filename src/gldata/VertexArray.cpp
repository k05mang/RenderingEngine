#include "VertexArray.h"

VertexArray::VertexArray()
{
    //ctor
}

VertexArray::~VertexArray()
{
    //dtor
}

void finalize();
VertexArray::erase();
VertexArray::addAttrib(AttribType type, bool normalize, int divisor);

inline VertexArray::add(float value);
inline VertexArray::add(double value);
inline VertexArray::add(int value);
inline VertexArray::add(char value);
inline VertexArray::add(short value);
inline VertexArray::add(unsigned int value);
inline VertexArray::add(unsigned char value);
inline VertexArray::add(unsigned short value);

//vectors
inline VertexArray::add(vec2& value);
inline VertexArray::add(vec3& value);
inline VertexArray::add(vec4& value);

inline VertexArray::add(dvec2& value);
inline VertexArray::add(dvec3& value);
inline VertexArray::add(dvec4& value);

inline VertexArray::add(uvec2& value);
inline VertexArray::add(uvec3& value);
inline VertexArray::add(uvec4& value);

inline VertexArray::add(ivec2& value);
inline VertexArray::add(ivec3& value);
inline VertexArray::add(ivec4& value);

//matrices
inline VertexArray::add(mat2& value);
inline VertexArray::add(mat2x3& value);
inline VertexArray::add(mat2x4& value);

inline VertexArray::add(mat3& value);
inline VertexArray::add(mat3x2& value);
inline VertexArray::add(mat3x4& value);

inline VertexArray::add(mat4& value);
inline VertexArray::add(mat4x2& value);
inline VertexArray::add(mat4x3& value);

//double matrices
inline VertexArray::add(dmat2& value);
inline VertexArray::add(dmat2x3& value);
inline VertexArray::add(dmat2x4& value);

inline VertexArray::add(dmat3& value);
inline VertexArray::add(dmat3x2& value);
inline VertexArray::add(dmat3x4& value);

inline VertexArray::add(dmat4& value);
inline VertexArray::add(dmat4x2& value);
inline VertexArray::add(dmat4x3& value);

inline VertexArray::add(Vertex& value);

inline VertexArray::addIndex(int value);
inline VertexArray::addIndex(char value);
inline VertexArray::addIndex(short value);
inline VertexArray::addIndex(unsigned int value);
inline VertexArray::addIndex(unsigned char value);
inline VertexArray::addIndex(unsigned short value);

VertexArray::setAttribute(int attribute, vector<float>& data);
VertexArray::setAttribute(int attribute, vector<double>& data);
VertexArray::setAttribute(int attribute, vector<int>& data);
VertexArray::setAttribute(int attribute, vector<char>& data);
VertexArray::setAttribute(int attribute, vector<short>& data);
VertexArray::setAttribute(int attribute, vector<unsigned int>& data);
VertexArray::setAttribute(int attribute, vector<unsigned char>& data);
VertexArray::setAttribute(int attribute, vector<unsigned short>& data);

//vectors
VertexArray::setAttribute(int attribute, vector<vec2>& data);
VertexArray::setAttribute(int attribute, vector<vec3>& data);
VertexArray::setAttribute(int attribute, vector<vec4>& data);

VertexArray::setAttribute(int attribute, vector<dvec2>& data);
VertexArray::setAttribute(int attribute, vector<dvec3>& data);
VertexArray::setAttribute(int attribute, vector<dvec4>& data);

VertexArray::setAttribute(int attribute, vector<uvec2>& data);
VertexArray::setAttribute(int attribute, vector<uvec3>& data);
VertexArray::setAttribute(int attribute, vector<uvec4>& data);

VertexArray::setAttribute(int attribute, vector<ivec2>& data);
VertexArray::setAttribute(int attribute, vector<ivec3>& data);
VertexArray::setAttribute(int attribute, vector<ivec4>& data);

//matrices
VertexArray::setAttribute(int attribute, vector<mat2>& data);
VertexArray::setAttribute(int attribute, vector<mat2x3>& data);
VertexArray::setAttribute(int attribute, vector<mat2x4>& data);

VertexArray::setAttribute(int attribute, vector<mat3>& data);
VertexArray::setAttribute(int attribute, vector<mat3x2>& data);
VertexArray::setAttribute(int attribute, vector<mat3x4>& data);

VertexArray::setAttribute(int attribute, vector<mat4>& data);
VertexArray::setAttribute(int attribute, vector<mat4x2>& data);
VertexArray::setAttribute(int attribute, vector<mat4x3>& data);

//double matrices
VertexArray::setAttribute(int attribute, vector<dmat2>& data);
VertexArray::setAttribute(int attribute, vector<dmat2x3>& data);
VertexArray::setAttribute(int attribute, vector<dmat2x4>& data);

VertexArray::setAttribute(int attribute, vector<dmat3>& data);
VertexArray::setAttribute(int attribute, vector<dmat3x2>& data);
VertexArray::setAttribute(int attribute, vector<dmat3x4>& data);

VertexArray::setAttribute(int attribute, vector<dmat4>& data);
VertexArray::setAttribute(int attribute, vector<dmat4x2>& data);
VertexArray::setAttribute(int attribute, vector<dmat4x3>& data);

VertexArray::setAttribute(int attribute, vector<Vertex>& data);
