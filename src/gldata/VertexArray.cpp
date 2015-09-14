#include "VertexArray.h"

/*
        shared_ptr<GLuint> vaoId;
        BufferObject buffer, indices;
        char vertStride;
        shared_ptr<vector<VertexAttrib>> attributes;
*/
VertexArray::VertexArray() : buffer(GL_ARRAY_BUFFER), indices(GL_ELEMENT_ARRAY_BUFFER), attributes(new vector<VertexAttrib>{})
{
    GLuint vao[1];
    glGenBuffers(1, vao);
    vaoId(new GLuint(vao[0]);
}

VertexArray::~VertexArray()
{
    if(vaoId.unique()){
      GLuint vao[]{*vaoId};
      glDeleteVertexArrays(1, vaoId);
    }
}
//add vertStride copy if it becomes more essential to the object functionality
VertexArray(const VertexArray& rhs) : vaoId(rhs.vaoId), buffer(rhs.buffer), indices(rhs.indices), attributes(rhs.attributes){

}

VertexArray& operator=(const VertexArray& rhs) : vaoId(rhs.vaoId), buffer(rhs.buffer), indices(rhs.indices), attributes(rhs.attributes){
      return *this;
}

void finalize(){

}

void VertexArray::erase(){
      GLuint vao[]{*vaoId};
      glDeleteVertexArrays(1, vaoId);
}

void VertexArray::addAttrib(AttribType type, bool normalize, int divisor){
        switch(type){
                case AttribType::FLOAT:
                        attributes->push_back(VertexAttrib(1, GL_FLOAT, normalize, attributes->back().offset+4, divisor));
                        //vertStride += 4;
                        break;
                case AttribType::DOUBLE:
                        attributes->push_back(VertexAttrib(1, GL_DOUBLE, normalize, attributes->back().offset+8, divisor));
                        //vertStride += 8;
                        break;
                case AttribType::BYTE:
                        attributes->push_back(VertexAttrib(1, GL_BYTE, normalize, attributes->back().offset+1, divisor));
                        //vertStride++;
                        break;
                case AttribType::UBYTE:
                        attributes->push_back(VertexAttrib(1, GL_UNSIGNED_BYTE, normalize, attributes->back().offset+1, divisor));
                        //vertStride++;
                        break;
                case AttribType::SHORT:
                        attributes->push_back(VertexAttrib(1, GL_SHORT, normalize, attributes->back().offset+2, divisor));
                        //vertStride += 2;
                        break;
                case AttribType::USHORT:
                        attributes->push_back(VertexAttrib(1, GL_UNSIGNED_SHORT, normalize, attributes->back().offset+2, divisor));
                        //vertStride += 2;
                        break;
                case AttribType::INT:
                        attributes->push_back(VertexAttrib(1, GL_INT, normalize, attributes->back().offset+4, divisor));
                        //vertStride += 4;
                        break;
                case AttribType::UINT:
                        attributes->push_back(VertexAttrib(1, GL_UNSIGNED_INT, normalize, attributes->back().offset+4, divisor));
                        //vertStride += 4;
                        break;

                case AttribType::VEC2:
                        attributes->push_back(VertexAttrib(2, GL_FLOAT, normalize, attributes->back().offset+8, divisor));
                        //vertStride += 8;
                        break;
                case AttribType::VEC3:
                        attributes->push_back(VertexAttrib(3, GL_FLOAT, normalize, attributes->back().offset+12, divisor));
                        //vertStride += 12;
                        break;
                case AttribType::VEC4:
                        attributes->push_back(VertexAttrib(4, GL_FLOAT, normalize, attributes->back().offset+16, divisor));
                        //vertStride += 16;
                        break;

                case AttribType::DVEC2:
                        attributes->push_back(VertexAttrib(2, GL_DOUBLE, normalize, attributes->back().offset+16, divisor));
                        //vertStride += 16;
                        break;
                case AttribType::DVEC3:
                        attributes->push_back(VertexAttrib(3, GL_DOUBLE, normalize, attributes->back().offset+24, divisor));
                        //vertStride += 24;
                        break;
                case AttribType::DVEC4:
                        attributes->push_back(VertexAttrib(4, GL_DOUBLE, normalize, attributes->back().offset+32, divisor));
                        //vertStride += 32;
                        break;

                case AttribType::UVEC2:
                        attributes->push_back(VertexAttrib(2, GL_UNSIGNED_INT, normalize, attributes->back().offset+8, divisor));
                        //vertStride += 8;
                        break;
                case AttribType::UVEC3:
                        attributes->push_back(VertexAttrib(3, GL_UNSIGNED_INT, normalize, attributes->back().offset+12, divisor));
                        //vertStride += 12;
                        break;
                case AttribType::UVEC4:
                        attributes->push_back(VertexAttrib(4, GL_UNSIGNED_INT, normalize, attributes->back().offset+16, divisor));
                        //vertStride += 16;
                        break;

                case AttribType::IVEC2:
                        attributes->push_back(VertexAttrib(2, GL_INT, normalize, attributes->back().offset+8, divisor));
                        //vertStride += 8;
                        break;
                case AttribType::IVEC3:
                        attributes->push_back(VertexAttrib(3, GL_INT, normalize, attributes->back().offset+12, divisor));
                        //vertStride += 12;
                        break;
                case AttribType::IVEC4:
                        attributes->push_back(VertexAttrib(4, GL_INT, normalize, attributes->back().offset+16, divisor));
                        //vertStride += 16;
                        break;

                case AttribType::MAT2:
                        int offset = attributes->back().offset+8;
                        attributes->push_back(VertexAttrib(2, GL_FLOAT, normalize, offset, divisor));
                        attributes->push_back(VertexAttrib(2, GL_FLOAT, normalize, offset+8, divisor));
                        //vertStride += 16;
                        break;
                case AttribType::MAT2x3:
                        int offset = attributes->back().offset+12;
                        attributes->push_back(VertexAttrib(3, GL_FLOAT, normalize, offset, divisor));
                        attributes->push_back(VertexAttrib(3, GL_FLOAT, normalize, offset+12, divisor));
                        //vertStride += 24;
                        break;
                case AttribType::MAT2x4:
                        int offset = attributes->back().offset+16;
                        attributes->push_back(VertexAttrib(4, GL_FLOAT, normalize, offset, divisor));
                        attributes->push_back(VertexAttrib(4, GL_FLOAT, normalize, offset+16, divisor));
                        //vertStride += 32;
                        break;

                case AttribType::MAT3:
                        int offset = attributes->back().offset+12;
                        attributes->push_back(VertexAttrib(3, GL_FLOAT, normalize, offset, divisor));
                        attributes->push_back(VertexAttrib(3, GL_FLOAT, normalize, offset+12, divisor));
                        attributes->push_back(VertexAttrib(3, GL_FLOAT, normalize, offset+24, divisor));
                        //vertStride += 36;
                        break;
                case AttribType::MAT3x2:
                        int offset = attributes->back().offset+8;
                        attributes->push_back(VertexAttrib(2, GL_FLOAT, normalize, offset, divisor));
                        attributes->push_back(VertexAttrib(2, GL_FLOAT, normalize, offset+8, divisor));
                        attributes->push_back(VertexAttrib(2, GL_FLOAT, normalize, offset+15, divisor));
                        //vertStride += 24;
                        break;
                case AttribType::MAT3x4:
                        int offset = attributes->back().offset+16;
                        attributes->push_back(VertexAttrib(4, GL_FLOAT, normalize, offset, divisor));
                        attributes->push_back(VertexAttrib(4, GL_FLOAT, normalize, offset+16, divisor));
                        attributes->push_back(VertexAttrib(4, GL_FLOAT, normalize, offset+32, divisor));
                        //vertStride += 48;
                        break;

                case AttribType::MAT4:
                        int offset = attributes->back().offset+16;
                        attributes->push_back(VertexAttrib(4, GL_FLOAT, normalize, offset, divisor));
                        attributes->push_back(VertexAttrib(4, GL_FLOAT, normalize, offset+16, divisor));
                        attributes->push_back(VertexAttrib(4, GL_FLOAT, normalize, offset+32, divisor));
                        attributes->push_back(VertexAttrib(4, GL_FLOAT, normalize, offset+48, divisor));
                        //vertStride += 64;
                        break;
                case AttribType::MAT4x2:
                        int offset = attributes->back().offset+8;
                        attributes->push_back(VertexAttrib(2, GL_FLOAT, normalize, offset, divisor));
                        attributes->push_back(VertexAttrib(2, GL_FLOAT, normalize, offset+8, divisor));
                        attributes->push_back(VertexAttrib(2, GL_FLOAT, normalize, offset+16, divisor));
                        attributes->push_back(VertexAttrib(2, GL_FLOAT, normalize, offset+24, divisor));
                        //vertStride += 32;
                        break;
                case AttribType::MAT4x3:
                        int offset = attributes->back().offset+12;
                        attributes->push_back(VertexAttrib(3, GL_FLOAT, normalize, offset, divisor));
                        attributes->push_back(VertexAttrib(3, GL_FLOAT, normalize, offset+12, divisor));
                        attributes->push_back(VertexAttrib(3, GL_FLOAT, normalize, offset+24, divisor));
                        attributes->push_back(VertexAttrib(3, GL_FLOAT, normalize, offset+36, divisor));
                        //vertStride += 48;
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
      if(attribute >= attributes->length()){
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
