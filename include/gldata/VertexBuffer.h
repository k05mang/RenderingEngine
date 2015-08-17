#pragma once
#include "BufferObject.h"

class VertexBuffer : public BufferObject
{
    public:
        VertexBuffer();
        ~VertexBuffer();

        VertexBuffer(const VertexBuffer&) = delete;
        VertexBuffer& operator=(const VertexBuffer&) = delete;
        VertexBuffer(VertexBuffer&&) = delete;
        VertexBuffer& operator=(VertexBuffer&&) = delete;

        void bind();
        void unbind();
};
