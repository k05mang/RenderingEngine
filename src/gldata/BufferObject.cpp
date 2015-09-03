#include "BufferObject.h"

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

void BufferObject::add(int value){}
void BufferObject::add(char value){}
void BufferObject::add(short value){}
void BufferObject::add(unsigned int value){}
void BufferObject::add(unsigned char value){}
void BufferObject::add(unsigned short value){}

//different vector types
void BufferObject::add(glm::uvec2& value){}
void BufferObject::add(glm::uvec3& value){}
void BufferObject::add(glm::uvec4& value){}

void BufferObject::add(glm::ivec2& value){}
void BufferObject::add(glm::ivec3& value){}
void BufferObject::add(glm::ivec4& value){}

//sets the value of the vertex buffer data store that is on the GPU
//primitive data types
void BufferObject::set(int byteOffset, int value){}
void BufferObject::set(int byteOffset, char value){}
void BufferObject::set(int byteOffset, short value){}
void BufferObject::set(int byteOffset, unsigned int value){}
void BufferObject::set(int byteOffset, unsigned char value){}
void BufferObject::set(int byteOffset, unsigned short value){}

//different vector types
void BufferObject::set(int byteOffset, glm::uvec2& value){}
void BufferObject::set(int byteOffset, glm::uvec3& value){}
void BufferObject::set(int byteOffset, glm::uvec4& value){}

void BufferObject::set(int byteOffset, glm::ivec2& value){}
void BufferObject::set(int byteOffset, glm::ivec3& value){}
void BufferObject::set(int byteOffset, glm::ivec4& value){}
