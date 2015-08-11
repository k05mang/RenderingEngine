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
