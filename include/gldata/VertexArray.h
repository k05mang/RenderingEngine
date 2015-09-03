#pragma once
#include <windows.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glcorearb.h>
#include <unordered_map>
#include "BufferObject.h"

using namespace std;
class VertexArray
{
    private:
        GLuint vaoId;
        class VertexAttrib
        {
            public:
                int size;
                GLenum type;
                bool normalize;
                int stride;
                int offset;

                VertexAttrib(int size, GLenum type, bool normalize, int stride, int offset) :
                size(size), type(type), normalize(normalize), stride(stride), offset(offset)
                {}

                ~VertexAttrib() = default;
        };
        unordered_map<string, BufferObject(> buffers;
        BufferObject* index;
    public:
        VertexArray();
        ~VertexArray();
};
