#pragma once
#include "BufferObject.h"

class VertexBuffer : public BufferObject
{
    public:
        VertexBuffer();
        ~VertexBuffer();

        void bind();
        void unbind();

        VertexBuffer(const VertexBuffer&) = delete;
        VertexBuffer& operator=(const VertexBuffer&) = delete;
        VertexBuffer(VertexBuffer&&) = delete;
        VertexBuffer& operator=(VertexBuffer&&) = delete;
};
