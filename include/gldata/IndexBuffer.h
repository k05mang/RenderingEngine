#pragma once
#include "BufferObject.h"
#include <vector>

using namespace std;

class IndexBuffer : public BufferObject
{
    public:
        IndexBuffer(vector<byte>);
        IndexBuffer(vector<unsigned byte>);
        IndexBuffer(vector<short>);
        IndexBuffer(vector<unsigned short>);
        IndexBuffer(vector<int>);

        void reset(vector<unsigned int>);
        ~IndexBuffer();

        IndexBuffer(const IndexBuffer&) = delete;
        IndexBuffer& operator=(const IndexBuffer&) = delete;
        IndexBuffer(IndexBuffer&&) = delete;
        IndexBuffer& operator=(IndexBuffer&&) = delete;

        void bind();
        void unbind();

        void reset(vector<byte> data, GLenum usage);
        void reset(vector<unsigned byte> data, GLenum usage);
        void reset(vector<short> data, GLenum usage);
        void reset(vector<unsigned short> data, GLenum usage);
        void reset(vector<int> data, GLenum usage);
        void reset(vector<unsigned int> data, GLenum usage);

        //add the setting data with offset feature
};
