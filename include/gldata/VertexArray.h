#pragma once
#include <windows.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glcorearb.h>
#include <vector>
#include "BufferObject.h"
#include <glm.hpp>

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
                int divisor;

                VertexAttrib(int size, GLenum type, bool normalize, int stride, int offset, int divisor) :
                size(size), type(type), normalize(normalize), stride(stride), offset(offset), divisor(divisor)
                {}

                ~VertexAttrib() = default;
        };
        BufferObject buffer, indices;
        char vertStride;
        vector<VertexAttrib> attributes;
        enum AttribType{
                FLOAT,
                DOUBLE,
                BYTE,
                UBYTE,
                SHORT,
                USHORT,
                INT,
                UINT,

                VEC2,
                VEC3,
                VEC4,

                DVEC2,
                DVEC3,
                DVEC4,

                UVEC2,
                UVEC3,
                UVEC4,

                IVEC2,
                IVEC3,
                IVEC4,

                MAT2,
                MAT2x3,
                MAT2x4,

                MAT3,
                MAT3x2,
                MAT3x4,

                MAT4,
                MAT4x2,
                MAT4x3
        };
    public:
        //possibly make this take parameters to determine how the buffers should be used
        //such as dynamic draw vs static draw
        VertexArray();
        ~VertexArray();

        void finalize();
        void erase();
        void addAttrib(AttribType type, bool normalize, int divisor);

        inline void add(float value);
        inline void add(double value);
        inline void add(int value);
        inline void add(char value);
        inline void add(short value);
        inline void add(unsigned int value);
        inline void add(unsigned char value);
        inline void add(unsigned short value);

        //vectors
        inline void add(vec2& value);
        inline void add(vec3& value);
        inline void add(vec4& value);

        inline void add(dvec2& value);
        inline void add(dvec3& value);
        inline void add(dvec4& value);

        inline void add(uvec2& value);
        inline void add(uvec3& value);
        inline void add(uvec4& value);

        inline void add(ivec2& value);
        inline void add(ivec3& value);
        inline void add(ivec4& value);

        //matrices
        inline void add(mat2& value);
        inline void add(mat2x3& value);
        inline void add(mat2x4& value);

        inline void add(mat3& value);
        inline void add(mat3x2& value);
        inline void add(mat3x4& value);

        inline void add(mat4& value);
        inline void add(mat4x2& value);
        inline void add(mat4x3& value);

        //double matrices
        inline void add(dmat2& value);
        inline void add(dmat2x3& value);
        inline void add(dmat2x4& value);

        inline void add(dmat3& value);
        inline void add(dmat3x2& value);
        inline void add(dmat3x4& value);

        inline void add(dmat4& value);
        inline void add(dmat4x2& value);
        inline void add(dmat4x3& value);

        inline void add(Vertex& value);

        inline void addIndex(int value);
        inline void addIndex(char value);
        inline void addIndex(short value);
        inline void addIndex(unsigned int value);
        inline void addIndex(unsigned char value);
        inline void addIndex(unsigned short value);

        void setAttribute(int attribute, vector<float>& data);
        void setAttribute(int attribute, vector<double>& data);
        void setAttribute(int attribute, vector<int>& data);
        void setAttribute(int attribute, vector<char>& data);
        void setAttribute(int attribute, vector<short>& data);
        void setAttribute(int attribute, vector<unsigned int>& data);
        void setAttribute(int attribute, vector<unsigned char>& data);
        void setAttribute(int attribute, vector<unsigned short>& data);

        //vectors
        void setAttribute(int attribute, vector<vec2>& data);
        void setAttribute(int attribute, vector<vec3>& data);
        void setAttribute(int attribute, vector<vec4>& data);

        void setAttribute(int attribute, vector<dvec2>& data);
        void setAttribute(int attribute, vector<dvec3>& data);
        void setAttribute(int attribute, vector<dvec4>& data);

        void setAttribute(int attribute, vector<uvec2>& data);
        void setAttribute(int attribute, vector<uvec3>& data);
        void setAttribute(int attribute, vector<uvec4>& data);

        void setAttribute(int attribute, vector<ivec2>& data);
        void setAttribute(int attribute, vector<ivec3>& data);
        void setAttribute(int attribute, vector<ivec4>& data);

        //matrices
        void setAttribute(int attribute, vector<mat2>& data);
        void setAttribute(int attribute, vector<mat2x3>& data);
        void setAttribute(int attribute, vector<mat2x4>& data);

        void setAttribute(int attribute, vector<mat3>& data);
        void setAttribute(int attribute, vector<mat3x2>& data);
        void setAttribute(int attribute, vector<mat3x4>& data);

        void setAttribute(int attribute, vector<mat4>& data);
        void setAttribute(int attribute, vector<mat4x2>& data);
        void setAttribute(int attribute, vector<mat4x3>& data);

        //double matrices
        void setAttribute(int attribute, vector<dmat2>& data);
        void setAttribute(int attribute, vector<dmat2x3>& data);
        void setAttribute(int attribute, vector<dmat2x4>& data);

        void setAttribute(int attribute, vector<dmat3>& data);
        void setAttribute(int attribute, vector<dmat3x2>& data);
        void setAttribute(int attribute, vector<dmat3x4>& data);

        void setAttribute(int attribute, vector<dmat4>& data);
        void setAttribute(int attribute, vector<dmat4x2>& data);
        void setAttribute(int attribute, vector<dmat4x3>& data);

        void setAttribute(int attribute, vector<Vertex>& data);
};
