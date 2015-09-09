#include "gldata/VertexBuffer.h"
#include <gtc/type_ptr.hpp>

VertexBuffer::VertexBuffer()
{
    //ctor
}

VertexBuffer::~VertexBuffer()
{
    //dtor
}

void VertexBuffer::bind(){
    glBindBuffer(GL_ARRAY_BUFFER, bufferId);
}

void VertexBuffer::unbind(){
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

//add functions add values to this vertex buffer, when the flush function is called
//this objects storage buffer gets transferred over to the GPU as a vertex buffer storage

//primitive types
inline void VertexBuffer::add(float value){
    data.push_back(value & 0xff);
    data.push_back((value >> 8) & 0xff);
    data.push_back((value >> 16) & 0xff);
    data.push_back((value >> 24) & 0xff);
}

inline void VertexBuffer::add(double value){
    data.push_back(value & 0xff);
    data.push_back((value >> 8) & 0xff);
    data.push_back((value >> 16) & 0xff);
    data.push_back((value >> 24) & 0xff);
    data.push_back((value >> 32) & 0xff);
    data.push_back((value >> 40) & 0xff);
    data.push_back((value >> 48) & 0xff);
    data.push_back((value >> 56) & 0xff);
}

//different vector types
void VertexBuffer::add(glm::vec2& value){
    this->add(value.x);
    this->add(value.y);
}
void VertexBuffer::add(glm::vec3& value){
    this->add(value.x);
    this->add(value.y);
    this->add(value.z);
}
void VertexBuffer::add(glm::vec4& value){
    this->add(value.x);
    this->add(value.y);
    this->add(value.z);
    this->add(value.w);
}

void VertexBuffer::add(glm::dvec2& value){
    this->add(value.x);
    this->add(value.y);
}
void VertexBuffer::add(glm::dvec3& value){
    this->add(value.x);
    this->add(value.y);
    this->add(value.z);
}
void VertexBuffer::add(glm::dvec4& value){
    this->add(value.x);
    this->add(value.y);
    this->add(value.z);
    this->add(value.w);
}

//different float matrix types, (columns x rows)
void VertexBuffer::add(glm::mat2& value){
    this->add(value[0]);
    this->add(value[1]);
}
void VertexBuffer::add(glm::mat2x3& value){
    this->add(value[0]);
    this->add(value[1]);
}
void VertexBuffer::add(glm::mat2x4& value){
    this->add(value[0]);
    this->add(value[1]);
}

void VertexBuffer::add(glm::mat3& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
}
void VertexBuffer::add(glm::mat3x2& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
}
void VertexBuffer::add(glm::mat3x4& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
}

void VertexBuffer::add(glm::mat4& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
    this->add(value[3]);
}
void VertexBuffer::add(glm::mat4x2& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
    this->add(value[3]);
}
void VertexBuffer::add(glm::mat4x3& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
    this->add(value[3]);
}

//double matrix types
void VertexBuffer::add(glm::dmat2& value){
    this->add(value[0]);
    this->add(value[1]);
}
void VertexBuffer::add(glm::dmat2x3& value){
    this->add(value[0]);
    this->add(value[1]);
}
void VertexBuffer::add(glm::dmat2x4& value){
    this->add(value[0]);
    this->add(value[1]);
}

void VertexBuffer::add(glm::dmat3& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
}
void VertexBuffer::add(glm::dmat3x2& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
}
void VertexBuffer::add(glm::dmat3x4& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
}

void VertexBuffer::add(glm::dmat4& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
    this->add(value[3]);
}
void VertexBuffer::add(glm::dmat4x2& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
    this->add(value[3]);
}
void VertexBuffer::add(glm::dmat4x3& value){
    this->add(value[0]);
    this->add(value[1]);
    this->add(value[2]);
    this->add(value[3]);
}

void VertexBuffer::add(Vertex& value){
    value.store(data);
}

//sets the value of the vertex buffer data store that is on the GPU
//primitive data types
void VertexBuffer::set(int byteOffset, float value){
    glNamedBufferSubData(bufferId, byteOffset, 4, &value);
}
void VertexBuffer::set(int byteOffset, double value){
    glNamedBufferSubData(bufferId, byteOffset, 8, &value);
}

//different vector types
void VertexBuffer::set(int byteOffset, glm::vec2& value){
    glNamedBufferSubData(bufferId, byteOffset, 8, glm::value_ptr(value));
}
void VertexBuffer::set(int byteOffset, glm::vec3& value){
    glNamedBufferSubData(bufferId, byteOffset, 12, glm::value_ptr(value));
}
void VertexBuffer::set(int byteOffset, glm::vec4& value){
    glNamedBufferSubData(bufferId, byteOffset, 16, glm::value_ptr(value));
}

void VertexBuffer::set(int byteOffset, glm::dvec2& value){
    glNamedBufferSubData(bufferId, byteOffset, 16, glm::value_ptr(value));
}
void VertexBuffer::set(int byteOffset, glm::dvec3& value){
    glNamedBufferSubData(bufferId, byteOffset, 24, glm::value_ptr(value));
}
void VertexBuffer::set(int byteOffset, glm::dvec4& value){
    glNamedBufferSubData(bufferId, byteOffset, 32, glm::value_ptr(value));
}

//different float matrix types
void VertexBuffer::set(int byteOffset, glm::mat2& value){
    glNamedBufferSubData(bufferId, byteOffset, 16, glm::value_ptr(value));
}
void VertexBuffer::set(int byteOffset, glm::mat2x3& value){
    glNamedBufferSubData(bufferId, byteOffset, 24, glm::value_ptr(value));
}
void VertexBuffer::set(int byteOffset, glm::mat2x4& value){
    glNamedBufferSubData(bufferId, byteOffset, 32, glm::value_ptr(value));
}

void VertexBuffer::set(int byteOffset, glm::mat3& value){
    glNamedBufferSubData(bufferId, byteOffset, 36, glm::value_ptr(value));
}
void VertexBuffer::set(int byteOffset, glm::mat3x2& value){
    glNamedBufferSubData(bufferId, byteOffset, 24, glm::value_ptr(value));
}
void VertexBuffer::set(int byteOffset, glm::mat3x4& value){
    glNamedBufferSubData(bufferId, byteOffset, 48, glm::value_ptr(value));
}

void VertexBuffer::set(int byteOffset, glm::mat4& value){
    glNamedBufferSubData(bufferId, byteOffset, 64, glm::value_ptr(value));
}
void VertexBuffer::set(int byteOffset, glm::mat4x2& value){
    glNamedBufferSubData(bufferId, byteOffset, 32, glm::value_ptr(value));
}
void VertexBuffer::set(int byteOffset, glm::mat4x3& value){
    glNamedBufferSubData(bufferId, byteOffset, 48, glm::value_ptr(value));
}

//double matrix types
void VertexBuffer::set(int byteOffset, glm::dmat2& value){
    glNamedBufferSubData(bufferId, byteOffset, 32, glm::value_ptr(value));
}
void VertexBuffer::set(int byteOffset, glm::dmat2x3& value){
    glNamedBufferSubData(bufferId, byteOffset, 48, glm::value_ptr(value));
}
void VertexBuffer::set(int byteOffset, glm::dmat2x4& value){
    glNamedBufferSubData(bufferId, byteOffset, 64, glm::value_ptr(value));
}

void VertexBuffer::set(int byteOffset, glm::dmat3& value){
    glNamedBufferSubData(bufferId, byteOffset, 72, glm::value_ptr(value));
}
void VertexBuffer::set(int byteOffset, glm::dmat3x2& value){
    glNamedBufferSubData(bufferId, byteOffset, 48, glm::value_ptr(value));
}
void VertexBuffer::set(int byteOffset, glm::dmat3x4& value){
    glNamedBufferSubData(bufferId, byteOffset, 96, glm::value_ptr(value));
}

void VertexBuffer::set(int byteOffset, glm::dmat4& value){
    glNamedBufferSubData(bufferId, byteOffset, 104, glm::value_ptr(value));
}
void VertexBuffer::set(int byteOffset, glm::dmat4x2& value){
    glNamedBufferSubData(bufferId, byteOffset, 64, glm::value_ptr(value));
}
void VertexBuffer::set(int byteOffset, glm::dmat4x3& value){
    glNamedBufferSubData(bufferId, byteOffset, 96, glm::value_ptr(value));
}

void VertexBuffer::set(int byteOffset, Vertex& value){
    glNamedBufferSubData(bufferId, byteOffset, 12, glm::value_ptr(value));
    glNamedBufferSubData(bufferId, byteOffset+12, 12, glm::value_ptr(value));
    glNamedBufferSubData(bufferId, byteOffset+24, 8, glm::value_ptr(value));
}
