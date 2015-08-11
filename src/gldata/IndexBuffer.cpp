#include "IndexBuffer.h"

IndexBuffer(vector<byte>)
{

}

IndexBuffer(vector<unsigned byte>)
{

}

IndexBuffer(vector<short>)
{

}

IndexBuffer(vector<unsigned short>)
{

}

IndexBuffer(vector<int>)
{

}

IndexBuffer::~IndexBuffer()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    GLuint buffer[]{bufferId};
    glDeleteBuffers(1, buffer);
}

/*Binding and unbinding the buffer for use outside of the internal functions of this class*/
void IndexBuffer::bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
}

void IndexBuffer::unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

//methods for reseting the data in the buffer and re-initializing it
void IndexBuffer::reset(vector<byte> data, GLenum usage)
(

 data, GLenum usage)

void IndexBuffer::reset(vector<unsigned byte> data, GLenum usage)
(

 data, GLenum usage)

void IndexBuffer::reset(vector<short> data, GLenum usage)
(

 data, GLenum usage)

void IndexBuffer::reset(vector<unsigned short> data, GLenum usage)
(

 data, GLenum usage)

void IndexBuffer::reset(vector<int> data, GLenum usage)
(

 data, GLenum usage)

void IndexBuffer::reset(vector<unsigned int>)
(

)
