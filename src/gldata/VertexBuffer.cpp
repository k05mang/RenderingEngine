#include "gldata/VertexBuffer.h"

VertexBuffer::VertexBuffer()
{
    //ctor
}

VertexBuffer::~VertexBuffer()
{
    //dtor
}

void VertexBuffer::bind(){}
void VertexBuffer::unbind(){}

//add functions add values to this vertex buffer, when the flush function is called
//this objects storage buffer gets transferred over to the GPU as a vertex buffer storage

//primitive types
void VertexBuffer::add(float value){

}
void VertexBuffer::add(double value){}

//different vector types
void VertexBuffer::add(glm::vec2& value){}
void VertexBuffer::add(glm::vec3& value){}
void VertexBuffer::add(glm::vec4& value){}

void VertexBuffer::add(glm::dvec2& value){}
void VertexBuffer::add(glm::dvec3& value){}
void VertexBuffer::add(glm::dvec4& value){}

//different float matrix types
void VertexBuffer::add(glm::mat2& value){}
void VertexBuffer::add(glm::mat2x3& value){}
void VertexBuffer::add(glm::mat2x4& value){}

void VertexBuffer::add(glm::mat3& value){}
void VertexBuffer::add(glm::mat3x2& value){}
void VertexBuffer::add(glm::mat3x4& value){}

void VertexBuffer::add(glm::mat4& value){}
void VertexBuffer::add(glm::mat4x2& value){}
void VertexBuffer::add(glm::mat4x3& value){}

//double matrix types
void VertexBuffer::add(glm::dmat2& value){}
void VertexBuffer::add(glm::dmat2x3& value){}
void VertexBuffer::add(glm::dmat2x4& value){}

void VertexBuffer::add(glm::dmat3& value){}
void VertexBuffer::add(glm::dmat3x2& value){}
void VertexBuffer::add(glm::dmat3x4& value){}

void VertexBuffer::add(glm::dmat4& value){}
void VertexBuffer::add(glm::dmat4x2& value){}
void VertexBuffer::add(glm::dmat4x3& value){}

void VertexBuffer::add(Vertex& value){}

//sets the value of the vertex buffer data store that is on the GPU
//primitive data types
void VertexBuffer::set(int byteOffset, float value){}
void VertexBuffer::set(int byteOffset, double value){}

//different vector types
void VertexBuffer::set(int byteOffset, glm::vec2& value){}
void VertexBuffer::set(int byteOffset, glm::vec3& value){}
void VertexBuffer::set(int byteOffset, glm::vec4& value){}

void VertexBuffer::set(int byteOffset, glm::dvec2& value){}
void VertexBuffer::set(int byteOffset, glm::dvec3& value){}
void VertexBuffer::set(int byteOffset, glm::dvec4& value){}

//different float matrix types
void VertexBuffer::set(int byteOffset, glm::mat2& value){}
void VertexBuffer::set(int byteOffset, glm::mat2x3& value){}
void VertexBuffer::set(int byteOffset, glm::mat2x4& value){}

void VertexBuffer::set(int byteOffset, glm::mat3& value){}
void VertexBuffer::set(int byteOffset, glm::mat3x2& value){}
void VertexBuffer::set(int byteOffset, glm::mat3x4& value){}

void VertexBuffer::set(int byteOffset, glm::mat4& value){}
void VertexBuffer::set(int byteOffset, glm::mat4x2& value){}
void VertexBuffer::set(int byteOffset, glm::mat4x3& value){}

//double matrix types
void VertexBuffer::set(int byteOffset, glm::dmat2& value){}
void VertexBuffer::set(int byteOffset, glm::dmat2x3& value){}
void VertexBuffer::set(int byteOffset, glm::dmat2x4& value){}

void VertexBuffer::set(int byteOffset, glm::dmat3& value){}
void VertexBuffer::set(int byteOffset, glm::dmat3x2& value){}
void VertexBuffer::set(int byteOffset, glm::dmat3x4& value){}

void VertexBuffer::set(int byteOffset, glm::dmat4& value){}
void VertexBuffer::set(int byteOffset, glm::dmat4x2& value){}
void VertexBuffer::set(int byteOffset, glm::dmat4x3& value){}

void VertexBuffer::set(int byteOffset, Vertex& value){}
