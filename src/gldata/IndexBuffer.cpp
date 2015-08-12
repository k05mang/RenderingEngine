#include "IndexBuffer.h"

IndexBuffer(vector<unsigned byte> data, GLenum usage)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size(), data.data(), usage);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

IndexBuffer(vector<unsigned short> data, GLenum usage)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size()*sizeof(unsigned short), data.data(), usage);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


IndexBuffer(vector<unsigned int> data, GLenum usage)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size()*sizeof(unsigned int), data.data(), usage);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
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

void IndexBuffer::reset(vector<unsigned byte> data, GLenum usage)
(
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size(), data.data(), usage);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::reset(vector<unsigned short> data, GLenum usage)
(
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size()*sizeof(unsigned short), data.data(), usage);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::reset(vector<unsigned int> data, GLenum usage)
(
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size()*sizeof(unsigned int), data.data(), usage);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
)

//methods to change a section of data in the buffer
void IndexBuffer::set(vector<unsigned byte> data, int offset)
(
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset, data.size(), data.data());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::set(vector<unsigned short> data, int offset)
(
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset, data.size()*sizeof(unsigned short), data.data());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::set(vector<unsigned int> data, int offset)
(
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset, data.size()*sizeof(unsigned int), data.data());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
)
