#pragma once
#include "BufferObject.h"
#include <vector>

using namespace std;

class IndexBuffer : public BufferObject
{
    public:
        IndexBuffer(vector<unsigned char>& data);
        IndexBuffer(vector<unsigned short>& data);
        IndexBuffer(vector<unsigned int>& data);

        ~IndexBuffer();

        IndexBuffer(const IndexBuffer&) = delete;
        IndexBuffer& operator=(const IndexBuffer&) = delete;
        IndexBuffer(IndexBuffer&&) = delete;
        IndexBuffer& operator=(IndexBuffer&&) = delete;

        void bind();
        void unbind();

        void reset(vector<unsigned char>& data, GLenum usage);
        void reset(vector<unsigned short>& data, GLenum usage);
        void reset(vector<unsigned int>& data, GLenum usage);

        //add the setting data with offset feature
        void set(vector<unsigned char>& data, int offset);
        void set(vector<unsigned short>& data, int offset);
        void set(vector<unsigned int>& data, int offset);
};
