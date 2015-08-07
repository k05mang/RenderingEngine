#pragma once
#include <windows.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glcorearb.h>
#include <vector>

using namespace std;

class VertexPointers
{
    private:
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
        vector<VertexAttrib> attributes;
        int stride;
    public:
        //TODO add other input types such as half_float
        static enum Types{
            BYTE,
            UBYTE,
            SHORT,
            USHORT,
            INT,
            UINT,
            FLOAT,
            BOOL,
            VEC2,
            VEC3,
            VEC4,
            IVEC2,
            IVEC3,
            IVEC4,
            UVEC2,
            UVEC3,
            UVEC4,
            BVEC2,
            BVEC3,
            BVEC4
        };
        VertexPointers();
        ~VertexPointers();

        void addAttrib(Types type, bool normalize);
        void bindAttribs();
};
