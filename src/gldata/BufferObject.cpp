#include "gldata/BufferObject.h"
#include <gtc/type_ptr.hpp>

/*
      shared_ptr<GLuint> bufferId;
      unsigned int numBytes;
      vector<unsigned char> data;
      GLenum type;
*/
BufferObject::BufferObject(GLenum type) : numBytes(0), type(type)
{
    GLuint buffer[1];
    glGenBuffers(1, buffer);
    bufferId(new GLuint(buffer[0]));
}

BufferObject::~BufferObject()
{
      if(bufferId.unique()){
            GLuint buffer[]{*bufferId};
            glDeleteBuffers(1, buffer);
      }
}

BufferObject(const BufferObject& copyTarget) : bufferId(copyTarget.bufferId), numBytes(copyTarget.numBytes), type(copyTarget.type){

}

BufferObject& operator=(const BufferObject& rhs){
      if(this == &rhs) return *this;
      bufferId(rhs.bufferId);
      numBytes(rhs.numBytes);
      type(rhs.type);
      return *this;
}

void BufferObject::bind(){
    glBindBuffer(type, *bufferId);
}

void BufferObject::unbind(){
    glBindBuffer(type, 0);
}

void BufferObject::erase()
{
    GLuint buffer[] {*bufferId};
    glDeleteBuffers(1, buffer);
}

int BufferObject::size()
{
    return numBytes;
}

void flush(GLenum usage){
    glNamedBufferData(*bufferId, data.size(), data.data(), usage);
    //clear the data store since it has been buffered onto the GPU
    data.clear();
    data.shrink_to_fit();
}

inline void BufferObject::add(float value){

    unsigned char const * bytes = reinterpret_cast<unsigned char const *>(&value);
    data.push_back(bytes[0]);
    data.push_back(bytes[1]);
    data.push_back(bytes[2]);
    data.push_back(bytes[3]);

    numBytes += 4;
}

inline void BufferObject::add(double value){

    unsigned char const * bytes = reinterpret_cast<unsigned char const *>(&value);
    data.push_back(bytes[0]);
    data.push_back(bytes[1]);
    data.push_back(bytes[2]);
    data.push_back(bytes[3]);
    data.push_back(bytes[4]);
    data.push_back(bytes[5]);
    data.push_back(bytes[6]);
    data.push_back(bytes[7]);

    numBytes += 8;
}

inline void BufferObject::add(char value){
    data.push_back(value & 0xff);

    numBytes++;
}
inline void BufferObject::add(short value){
    data.push_back(value & 0xff);
    data.push_back((value >> 8) & 0xff);

    numBytes += 2;
}
inline void BufferObject::add(int value){
    data.push_back(value & 0xff);
    data.push_back((value >> 8) & 0xff);
    data.push_back((value >> 16) & 0xff);
    data.push_back((value >> 24) & 0xff);

    numBytes += 4;
}
inline void BufferObject::add(unsigned char value){
    data.push_back(value);

    numBytes++;
}
inline void BufferObject::add(unsigned short value){
    data.push_back(value & 0xff);
    data.push_back((value >> 8) & 0xff);

    numBytes += 2;
}
inline void BufferObject::add(unsigned int value){
    data.push_back(value & 0xff);
    data.push_back((value >> 8) & 0xff);
    data.push_back((value >> 16) & 0xff);
    data.push_back((value >> 24) & 0xff);

    numBytes += 4;
}

//different vector types
void BufferObject::add(glm::uvec2& value){
    this->add(value.x);
    this->add(value.y);
}
void BufferObject::add(glm::uvec3& value){
    this->add(value.x);
    this->add(value.y);
    this->add(value.z);
}
void BufferObject::add(glm::uvec4& value){
    this->add(value.x);
    this->add(value.y);
    this->add(value.z);
    this->add(value.w);
}

void BufferObject::add(glm::ivec2& value){
    this->add(value.x);
    this->add(value.y);
}
void BufferObject::add(glm::ivec3& value){
    this->add(value.x);
    this->add(value.y);
    this->add(value.z);
}
void BufferObject::add(glm::ivec4& value){
    this->add(value.x);
    this->add(value.y);
    this->add(value.z);
    this->add(value.w);
}

void BufferObject::add(glm::vec2& value){
    this->add(value.x);
    this->add(value.y);
}
void BufferObject::add(glm::vec3& value){
    this->add(value.x);
    this->add(value.y);
    this->add(value.z);
}
void BufferObject::add(glm::vec4& value){
    this->add(value.x);
    this->add(value.y);
    this->add(value.z);
    this->add(value.w);
}

void BufferObject::add(glm::dvec2& value){
    this->add(value.x);
    this->add(value.y);
}
void BufferObject::add(glm::dvec3& value){
    this->add(value.x);
    this->add(value.y);
    this->add(value.z);
}
void BufferObject::add(glm::dvec4& value){
    this->add(value.x);
    this->add(value.y);
    this->add(value.z);
    this->add(value.w);
}

//different float matrix types, (columns x rows)
void BufferObject::add(glm::mat2& value){
    this->add(value[0]);
    this->add(value[1]);
}
void BufferObject::add(glm::mat2x3& value){
    this->add(value[0]);
    this->add(value[1]);
}
void BufferObject::add(glm::mat2x4& value){
    this->add(value[0]);
    this->add(value[1]);
}

void BufferObject::add(glm::mat3& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
}
void BufferObject::add(glm::mat3x2& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
}
void BufferObject::add(glm::mat3x4& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
}

void BufferObject::add(glm::mat4& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
    this->add(value[3]);
}
void BufferObject::add(glm::mat4x2& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
    this->add(value[3]);
}
void BufferObject::add(glm::mat4x3& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
    this->add(value[3]);
}

//double matrix types
void BufferObject::add(glm::dmat2& value){
    this->add(value[0]);
    this->add(value[1]);
}
void BufferObject::add(glm::dmat2x3& value){
    this->add(value[0]);
    this->add(value[1]);
}
void BufferObject::add(glm::dmat2x4& value){
    this->add(value[0]);
    this->add(value[1]);
}

void BufferObject::add(glm::dmat3& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
}
void BufferObject::add(glm::dmat3x2& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
}
void BufferObject::add(glm::dmat3x4& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
}

void BufferObject::add(glm::dmat4& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
    this->add(value[3]);
}
void BufferObject::add(glm::dmat4x2& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
    this->add(value[3]);
}
void BufferObject::add(glm::dmat4x3& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
    this->add(value[3]);
}

void BufferObject::add(Vertex& value){
    value.store(data);
}

//sets the value of the vertex buffer data store that is on the GPU
//primitive data types
void BufferObject::set(int byteOffset, float value){
    glNamedBufferSubData(bufferId, byteOffset, 4, &value);
}
void BufferObject::set(int byteOffset, double value){
    glNamedBufferSubData(bufferId, byteOffset, 8, &value);
}
void BufferObject::set(int byteOffset, char value){
    glNamedBufferSubData(bufferId, byteOffset, 1, &value);
}
void BufferObject::set(int byteOffset, short value){
    glNamedBufferSubData(bufferId, byteOffset, 2, &value);
}
void BufferObject::set(int byteOffset, int value){
    glNamedBufferSubData(bufferId, byteOffset, 4, &value);
}
void BufferObject::set(int byteOffset, unsigned char value){
    glNamedBufferSubData(bufferId, byteOffset, 1, &value);
}
void BufferObject::set(int byteOffset, unsigned short value){
    glNamedBufferSubData(bufferId, byteOffset, 2, &value);
}
void BufferObject::set(int byteOffset, unsigned int value){
    glNamedBufferSubData(bufferId, byteOffset, 4, &value);
}

//different vector types
void BufferObject::set(int byteOffset, glm::uvec2& value){
    glNamedBufferSubData(bufferId, byteOffset, 8, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::uvec3& value){
    glNamedBufferSubData(bufferId, byteOffset, 12, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::uvec4& value){
    glNamedBufferSubData(bufferId, byteOffset, 16, glm::value_ptr(value));
}


void BufferObject::set(int byteOffset, glm::ivec2& value){
    glNamedBufferSubData(bufferId, byteOffset, 8, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::ivec3& value){
    glNamedBufferSubData(bufferId, byteOffset, 12, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::ivec4& value){
    glNamedBufferSubData(bufferId, byteOffset, 16, glm::value_ptr(value));
}

void BufferObject::set(int byteOffset, glm::vec2& value){
    glNamedBufferSubData(bufferId, byteOffset, 8, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::vec3& value){
    glNamedBufferSubData(bufferId, byteOffset, 12, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::vec4& value){
    glNamedBufferSubData(bufferId, byteOffset, 16, glm::value_ptr(value));
}

void BufferObject::set(int byteOffset, glm::dvec2& value){
    glNamedBufferSubData(bufferId, byteOffset, 16, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::dvec3& value){
    glNamedBufferSubData(bufferId, byteOffset, 24, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::dvec4& value){
    glNamedBufferSubData(bufferId, byteOffset, 32, glm::value_ptr(value));
}

//different float matrix types
void BufferObject::set(int byteOffset, glm::mat2& value){
    glNamedBufferSubData(bufferId, byteOffset, 16, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::mat2x3& value){
    glNamedBufferSubData(bufferId, byteOffset, 24, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::mat2x4& value){
    glNamedBufferSubData(bufferId, byteOffset, 32, glm::value_ptr(value));
}

void BufferObject::set(int byteOffset, glm::mat3& value){
    glNamedBufferSubData(bufferId, byteOffset, 36, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::mat3x2& value){
    glNamedBufferSubData(bufferId, byteOffset, 24, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::mat3x4& value){
    glNamedBufferSubData(bufferId, byteOffset, 48, glm::value_ptr(value));
}

void BufferObject::set(int byteOffset, glm::mat4& value){
    glNamedBufferSubData(bufferId, byteOffset, 64, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::mat4x2& value){
    glNamedBufferSubData(bufferId, byteOffset, 32, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::mat4x3& value){
    glNamedBufferSubData(bufferId, byteOffset, 48, glm::value_ptr(value));
}

//double matrix types
void BufferObject::set(int byteOffset, glm::dmat2& value){
    glNamedBufferSubData(bufferId, byteOffset, 32, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::dmat2x3& value){
    glNamedBufferSubData(bufferId, byteOffset, 48, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::dmat2x4& value){
    glNamedBufferSubData(bufferId, byteOffset, 64, glm::value_ptr(value));
}

void BufferObject::set(int byteOffset, glm::dmat3& value){
    glNamedBufferSubData(bufferId, byteOffset, 72, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::dmat3x2& value){
    glNamedBufferSubData(bufferId, byteOffset, 48, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::dmat3x4& value){
    glNamedBufferSubData(bufferId, byteOffset, 96, glm::value_ptr(value));
}

void BufferObject::set(int byteOffset, glm::dmat4& value){
    glNamedBufferSubData(bufferId, byteOffset, 104, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::dmat4x2& value){
    glNamedBufferSubData(bufferId, byteOffset, 64, glm::value_ptr(value));
}
void BufferObject::set(int byteOffset, glm::dmat4x3& value){
    glNamedBufferSubData(bufferId, byteOffset, 96, glm::value_ptr(value));
}

void BufferObject::set(int byteOffset, Vertex& value){
    glNamedBufferSubData(bufferId, byteOffset, 12, glm::value_ptr(value));
    glNamedBufferSubData(bufferId, byteOffset+12, 12, glm::value_ptr(value));
    glNamedBufferSubData(bufferId, byteOffset+24, 8, glm::value_ptr(value));
}
