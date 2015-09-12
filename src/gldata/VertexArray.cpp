#include "VertexArray.h"

/*
        GLuint vaoId;
        BufferObject buffer, indices;
        char vertStride;
        vector<VertexAttrib> attributes;
*/
VertexArray::VertexArray()
{
    //ctor
}

VertexArray::~VertexArray()
{
    //dtor
}

void finalize();
void VertexArray::erase();
void VertexArray::addAttrib(AttribType type, bool normalize, int divisor);

inline void VertexArray::add(float value){buffer.add(value);}
inline void VertexArray::add(double value){buffer.add(value);}
inline void VertexArray::add(int value){buffer.add(value);}
inline void VertexArray::add(char value){buffer.add(value);}
inline void VertexArray::add(short value){buffer.add(value);}
inline void VertexArray::add(unsigned int value){buffer.add(value);}
inline void VertexArray::add(unsigned char value){buffer.add(value);}
inline void VertexArray::add(unsigned short value){buffer.add(value);}

//vectors
inline void VertexArray::add(vec2& value){buffer.add(value);}
inline void VertexArray::add(vec3& value){buffer.add(value);}
inline void VertexArray::add(vec4& value){buffer.add(value);}

inline void VertexArray::add(dvec2& value){buffer.add(value);}
inline void VertexArray::add(dvec3& value){buffer.add(value);}
inline void VertexArray::add(dvec4& value){buffer.add(value);}

inline void VertexArray::add(uvec2& value){buffer.add(value);}
inline void VertexArray::add(uvec3& value){buffer.add(value);}
inline void VertexArray::add(uvec4& value){buffer.add(value);}

inline void VertexArray::add(ivec2& value){buffer.add(value);}
inline void VertexArray::add(ivec3& value){buffer.add(value);}
inline void VertexArray::add(ivec4& value){buffer.add(value);}

//matrices
inline void VertexArray::add(mat2& value){buffer.add(value);}
inline void VertexArray::add(mat2x3& value){buffer.add(value);}
inline void VertexArray::add(mat2x4& value){buffer.add(value);}

inline void VertexArray::add(mat3& value){buffer.add(value);}
inline void VertexArray::add(mat3x2& value){buffer.add(value);}
inline void VertexArray::add(mat3x4& value){buffer.add(value);}

inline void VertexArray::add(mat4& value){buffer.add(value);}
inline void VertexArray::add(mat4x2& value){buffer.add(value);}
inline void VertexArray::add(mat4x3& value){buffer.add(value);}

//double matrices
inline void VertexArray::add(dmat2& value){buffer.add(value);}
inline void VertexArray::add(dmat2x3& value){buffer.add(value);}
inline void VertexArray::add(dmat2x4& value){buffer.add(value);}

inline void VertexArray::add(dmat3& value){buffer.add(value);}
inline void VertexArray::add(dmat3x2& value){buffer.add(value);}
inline void VertexArray::add(dmat3x4& value){buffer.add(value);}

inline void VertexArray::add(dmat4& value){buffer.add(value);}
inline void VertexArray::add(dmat4x2& value){buffer.add(value);}
inline void VertexArray::add(dmat4x3& value){buffer.add(value);}

inline void VertexArray::add(Vertex& value){buffer.add(value);}

inline void VertexArray::addIndex(int value){indices.add(value);}
inline void VertexArray::addIndex(char value){indices.add(value);}
inline void VertexArray::addIndex(short value){indices.add(value);}
inline void VertexArray::addIndex(unsigned int value){indices.add(value);}
inline void VertexArray::addIndex(unsigned char value){indices.add(value);}
inline void VertexArray::addIndex(unsigned short value){indices.add(value);}

void VertexArray::setAttribute(int attribute, vector<float>& data);
void VertexArray::setAttribute(int attribute, vector<double>& data);
void VertexArray::setAttribute(int attribute, vector<int>& data);
void VertexArray::setAttribute(int attribute, vector<char>& data);
void VertexArray::setAttribute(int attribute, vector<short>& data);
void VertexArray::setAttribute(int attribute, vector<unsigned int>& data);
void VertexArray::setAttribute(int attribute, vector<unsigned char>& data);
void VertexArray::setAttribute(int attribute, vector<unsigned short>& data);

//vectors
void VertexArray::setAttribute(int attribute, vector<vec2>& data);
void VertexArray::setAttribute(int attribute, vector<vec3>& data);
void VertexArray::setAttribute(int attribute, vector<vec4>& data);

void VertexArray::setAttribute(int attribute, vector<dvec2>& data);
void VertexArray::setAttribute(int attribute, vector<dvec3>& data);
void VertexArray::setAttribute(int attribute, vector<dvec4>& data);

void VertexArray::setAttribute(int attribute, vector<uvec2>& data);
void VertexArray::setAttribute(int attribute, vector<uvec3>& data);
void VertexArray::setAttribute(int attribute, vector<uvec4>& data);

void VertexArray::setAttribute(int attribute, vector<ivec2>& data);
void VertexArray::setAttribute(int attribute, vector<ivec3>& data);
void VertexArray::setAttribute(int attribute, vector<ivec4>& data);

//matrices
void VertexArray::setAttribute(int attribute, vector<mat2>& data);
void VertexArray::setAttribute(int attribute, vector<mat2x3>& data);
void VertexArray::setAttribute(int attribute, vector<mat2x4>& data);

void VertexArray::setAttribute(int attribute, vector<mat3>& data);
void VertexArray::setAttribute(int attribute, vector<mat3x2>& data);
void VertexArray::setAttribute(int attribute, vector<mat3x4>& data);

void VertexArray::setAttribute(int attribute, vector<mat4>& data);
void VertexArray::setAttribute(int attribute, vector<mat4x2>& data);
void VertexArray::setAttribute(int attribute, vector<mat4x3>& data);

//double matrices
void VertexArray::setAttribute(int attribute, vector<dmat2>& data);
void VertexArray::setAttribute(int attribute, vector<dmat2x3>& data);
void VertexArray::setAttribute(int attribute, vector<dmat2x4>& data);

void VertexArray::setAttribute(int attribute, vector<dmat3>& data);
void VertexArray::setAttribute(int attribute, vector<dmat3x2>& data);
void VertexArray::setAttribute(int attribute, vector<dmat3x4>& data);

void VertexArray::setAttribute(int attribute, vector<dmat4>& data);
void VertexArray::setAttribute(int attribute, vector<dmat4x2>& data);
void VertexArray::setAttribute(int attribute, vector<dmat4x3>& data);

void VertexArray::setAttribute(int attribute, vector<Vertex>& data);
