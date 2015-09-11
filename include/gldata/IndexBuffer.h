#pragma once
#include "gldata/BufferObject.h"
#include <vector>

using namespace std;

class IndexBuffer : public BufferObject
{
    public:
        IndexBuffer();

        IndexBuffer(const IndexBuffer&) = delete;
        IndexBuffer& operator=(const IndexBuffer&) = delete;
        IndexBuffer(IndexBuffer&&) = delete;
        IndexBuffer& operator=(IndexBuffer&&) = delete;

        void bind();
        void unbind();
};
