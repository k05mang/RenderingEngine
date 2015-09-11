#include "gldata/IndexBuffer.h"

IndexBuffer()
{

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

