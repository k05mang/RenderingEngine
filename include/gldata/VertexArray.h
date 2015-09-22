#pragma once
#include <windows.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glcorearb.h>
#include <vector>
#include "BufferObject.h"
#include <glm.hpp>
#include <memory>

using namespace std;
class VertexArray
{
    private:
        class VertexAttrib
        {
            public:
                int size;//number of values for the attribute, value is 1-4
                GLenum type;
                bool normalize;
                int offset;//offset into the vertex for this attribute
                int divisor;//attribute divisor

                VertexAttrib(int size, GLenum type, bool normalize, int offset, int divisor) :
                size(size), type(type), normalize(normalize), offset(offset), divisor(divisor)
                {}

                ~VertexAttrib() = default;
        };
        shared_ptr<GLuint> vaoId;
        BufferObject buffer, indices;
        char vertStride;
        shared_ptr<vector<VertexAttrib>> attributes;

    public:
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
        //possibly make this take parameters to determine how the buffers should be used
        //such as dynamic draw vs static draw
        VertexArray();
        ~VertexArray();

        VertexArray(const VertexArray& copyTarget);
        VertexArray& operator=(const VertexArray& rhs);
        VertexArray(VertexArray&&) = delete;
        VertexArray& operator=(VertexArray&&) = delete;

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
        inline void add(glm::vec2& value);
        inline void add(glm::vec3& value);
        inline void add(glm::vec4& value);

        inline void add(glm::dvec2& value);
        inline void add(glm::dvec3& value);
        inline void add(glm::dvec4& value);

        inline void add(glm::uvec2& value);
        inline void add(glm::uvec3& value);
        inline void add(glm::uvec4& value);

        inline void add(glm::ivec2& value);
        inline void add(glm::ivec3& value);
        inline void add(glm::ivec4& value);

        //matrices
        inline void add(glm::mat2& value);
        inline void add(glm::mat2x3& value);
        inline void add(glm::mat2x4& value);

        inline void add(glm::mat3& value);
        inline void add(glm::mat3x2& value);
        inline void add(glm::mat3x4& value);

        inline void add(glm::mat4& value);
        inline void add(glm::mat4x2& value);
        inline void add(glm::mat4x3& value);

        //double matrices
        inline void add(glm::dmat2& value);
        inline void add(glm::dmat2x3& value);
        inline void add(glm::dmat2x4& value);

        inline void add(glm::dmat3& value);
        inline void add(glm::dmat3x2& value);
        inline void add(glm::dmat3x4& value);

        inline void add(glm::dmat4& value);
        inline void add(glm::dmat4x2& value);
        inline void add(glm::dmat4x3& value);

        inline void add(Vertex& value);

        inline void addIndex(unsigned int value);

//        bool setAttribute(int attribute, vector<float>& data);
//        bool setAttribute(int attribute, vector<double>& data);
//        bool setAttribute(int attribute, vector<int>& data);
//        bool setAttribute(int attribute, vector<char>& data);
//        bool setAttribute(int attribute, vector<short>& data);
//        bool setAttribute(int attribute, vector<unsigned int>& data);
//        bool setAttribute(int attribute, vector<unsigned char>& data);
//        bool setAttribute(int attribute, vector<unsigned short>& data);
//
//        //vectors
//        bool setAttribute(int attribute, vector<glm::vec2>& data);
//        bool setAttribute(int attribute, vector<glm::vec3>& data);
//        bool setAttribute(int attribute, vector<glm::vec4>& data);
//
//        bool setAttribute(int attribute, vector<glm::dvec2>& data);
//        bool setAttribute(int attribute, vector<glm::dvec3>& data);
//        bool setAttribute(int attribute, vector<glm::dvec4>& data);
//
//        bool setAttribute(int attribute, vector<glm::uvec2>& data);
//        bool setAttribute(int attribute, vector<glm::uvec3>& data);
//        bool setAttribute(int attribute, vector<glm::uvec4>& data);
//
//        bool setAttribute(int attribute, vector<glm::ivec2>& data);
//        bool setAttribute(int attribute, vector<glm::ivec3>& data);
//        bool setAttribute(int attribute, vector<glm::ivec4>& data);
//
//        //matrices
//        bool setAttribute(int attribute, vector<glm::mat2>& data);
//        bool setAttribute(int attribute, vector<glm::mat2x3>& data);
//        bool setAttribute(int attribute, vector<glm::mat2x4>& data);
//
//        bool setAttribute(int attribute, vector<glm::mat3>& data);
//        bool setAttribute(int attribute, vector<glm::mat3x2>& data);
//        bool setAttribute(int attribute, vector<glm::mat3x4>& data);
//
//        bool setAttribute(int attribute, vector<glm::mat4>& data);
//        bool setAttribute(int attribute, vector<glm::mat4x2>& data);
//        bool setAttribute(int attribute, vector<glm::mat4x3>& data);
//
//        //double matrices
//        bool setAttribute(int attribute, vector<glm::dmat2>& data);
//        bool setAttribute(int attribute, vector<glm::dmat2x3>& data);
//        bool setAttribute(int attribute, vector<glm::dmat2x4>& data);
//
//        bool setAttribute(int attribute, vector<glm::dmat3>& data);
//        bool setAttribute(int attribute, vector<glm::dmat3x2>& data);
//        bool setAttribute(int attribute, vector<glm::dmat3x4>& data);
//
//        bool setAttribute(int attribute, vector<glm::dmat4>& data);
//        bool setAttribute(int attribute, vector<glm::dmat4x2>& data);
//        bool setAttribute(int attribute, vector<glm::dmat4x3>& data);
//
//        bool setAttribute(int attribute, vector<Vertex>& data);
//
//        bool setindex(int index, unsigned int value);
//        bool setIndices(int indexOffset, vector<unsigned int>& data);
};
