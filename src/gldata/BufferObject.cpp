#include "BufferObject.h"
#include <gtc/type_ptr.hpp>

BufferObject::BufferObject() : size(0)
{
    GLuint buffer[1];
    glGenBuffers(1, buffer);
    bufferId = buffer[0];
}

BufferObject::~BufferObject()
{
    //dtor
}

void BufferObject::erase()
{
    GLuint buffer[] {bufferId};
    glDeleteBuffers(1, buffer);
}

int BufferObject::size()
{
    return size;
}

inline void BufferObject::add(char value){
    data.push_back(value & 0xff);
}
inline void BufferObject::add(short value){
    data.push_back(value & 0xff);
    data.push_back((value >> 8) & 0xff);
}
inline void BufferObject::add(int value){
    data.push_back(value & 0xff);
    data.push_back((value >> 8) & 0xff);
    data.push_back((value >> 16) & 0xff);
    data.push_back((value >> 24) & 0xff);
}
inline void BufferObject::add(unsigned char value){
    data.push_back(value);
}
inline void BufferObject::add(unsigned short value){
    data.push_back(value & 0xff);
    data.push_back((value >> 8) & 0xff);
}
inline void BufferObject::add(unsigned int value){
    data.push_back(value & 0xff);
    data.push_back((value >> 8) & 0xff);
    data.push_back((value >> 16) & 0xff);
    data.push_back((value >> 24) & 0xff);
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

void flush(GLenum usage){
    glNamedBufferData(bufferId, data.size(), data.data(), usage);
}

//sets the value of the vertex buffer data store that is on the GPU
//primitive data types
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
