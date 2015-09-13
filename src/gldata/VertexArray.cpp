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
void VertexArray::addAttrib(AttribType type, bool normalize, int divisor){
        switch(type){
                case AttribType::FLOAT:
                        break;
                case AttribType::DOUBLE:
                        break;
                case AttribType::BYTE:
                        break;
                case AttribType::UBYTE:
                        break;
                case AttribType::SHORT:
                        break;
                case AttribType::USHORT:
                        break;
                case AttribType::INT:
                        break;
                case AttribType::UINT:
                        break;

                case AttribType::VEC2:
                        break;
                case AttribType::VEC3:
                        break;
                case AttribType::VEC4:
                        break;

                case AttribType::DVEC2:
                        break;
                case AttribType::DVEC3:
                        break;
                case AttribType::DVEC4:
                        break;

                case AttribType::UVEC2:
                        break;
                case AttribType::UVEC3:
                        break;
                case AttribType::UVEC4:
                        break;

                case AttribType::IVEC2:
                        break;
                case AttribType::IVEC3:
                        break;
                case AttribType::IVEC4:
                        break;

                case AttribType::MAT2:
                        break;
                case AttribType::MAT2x3:
                        break;
                case AttribType::MAT2x4:
                        break;

                case AttribType::MAT3:
                        break;
                case AttribType::MAT3x2:
                        break;
                case AttribType::MAT3x4:
                        break;

                case AttribType::MAT4:
                        break;
                case AttribType::MAT4x2:
                        break;
                case AttribType::MAT4x3:
                        break;
        }
}

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

inline void VertexArray::addIndex(unsigned int value){indices.add(value);}

bool VertexArray::setAttribute(int attribute, vector<float>& data){
      if(attribute >= attributes.length()){
            cerr << "Requested attribute out of bounds for vertex array attributes" << endl;
            return false;
      }else{

      }
}
bool VertexArray::setAttribute(int attribute, vector<double>& data);
bool VertexArray::setAttribute(int attribute, vector<int>& data);
bool VertexArray::setAttribute(int attribute, vector<char>& data);
bool VertexArray::setAttribute(int attribute, vector<short>& data);
bool VertexArray::setAttribute(int attribute, vector<unsigned int>& data);
bool VertexArray::setAttribute(int attribute, vector<unsigned char>& data);
bool VertexArray::setAttribute(int attribute, vector<unsigned short>& data);

//vectors
bool VertexArray::setAttribute(int attribute, vector<vec2>& data);
bool VertexArray::setAttribute(int attribute, vector<vec3>& data);
bool VertexArray::setAttribute(int attribute, vector<vec4>& data);

bool VertexArray::setAttribute(int attribute, vector<dvec2>& data);
bool VertexArray::setAttribute(int attribute, vector<dvec3>& data);
bool VertexArray::setAttribute(int attribute, vector<dvec4>& data);

bool VertexArray::setAttribute(int attribute, vector<uvec2>& data);
bool VertexArray::setAttribute(int attribute, vector<uvec3>& data);
bool VertexArray::setAttribute(int attribute, vector<uvec4>& data);

bool VertexArray::setAttribute(int attribute, vector<ivec2>& data);
bool VertexArray::setAttribute(int attribute, vector<ivec3>& data);
bool VertexArray::setAttribute(int attribute, vector<ivec4>& data);

//matrices
bool VertexArray::setAttribute(int attribute, vector<mat2>& data);
bool VertexArray::setAttribute(int attribute, vector<mat2x3>& data);
bool VertexArray::setAttribute(int attribute, vector<mat2x4>& data);

bool VertexArray::setAttribute(int attribute, vector<mat3>& data);
bool VertexArray::setAttribute(int attribute, vector<mat3x2>& data);
bool VertexArray::setAttribute(int attribute, vector<mat3x4>& data);

bool VertexArray::setAttribute(int attribute, vector<mat4>& data);
bool VertexArray::setAttribute(int attribute, vector<mat4x2>& data);
bool VertexArray::setAttribute(int attribute, vector<mat4x3>& data);

//double matrices
bool VertexArray::setAttribute(int attribute, vector<dmat2>& data);
bool VertexArray::setAttribute(int attribute, vector<dmat2x3>& data);
bool VertexArray::setAttribute(int attribute, vector<dmat2x4>& data);

bool VertexArray::setAttribute(int attribute, vector<dmat3>& data);
bool VertexArray::setAttribute(int attribute, vector<dmat3x2>& data);
bool VertexArray::setAttribute(int attribute, vector<dmat3x4>& data);

bool VertexArray::setAttribute(int attribute, vector<dmat4>& data);
bool VertexArray::setAttribute(int attribute, vector<dmat4x2>& data);
bool VertexArray::setAttribute(int attribute, vector<dmat4x3>& data);

bool VertexArray::setAttribute(int attribute, vector<Vertex>& data);

bool setindex(int index, unsigned int value);
bool setIndices(int indexOffset, vector<unsigned int>& data);
