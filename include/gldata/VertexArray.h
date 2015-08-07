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
        unordered_map<string, BufferObject(> buffers;
        BufferObject* index;
    public:
        VertexArray();
        ~VertexArray();
};
