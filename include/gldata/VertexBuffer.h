#pragma once
#include "gldata/BufferObject.h"
#include <vector>
#include <glm.hpp>

using namespace std;

class VertexBuffer : public BufferObject
{
    private:
        vector<char> data;
    //boolean, opaque, and structs are forbidden with attributes
    public:
        VertexBuffer();
        ~VertexBuffer();

        VertexBuffer(const VertexBuffer&) = delete;
        VertexBuffer& operator=(const VertexBuffer&) = delete;
        VertexBuffer(VertexBuffer&&) = delete;
        VertexBuffer& operator=(VertexBuffer&&) = delete;

        void bind();
        void unbind();

        //add functions add values to this vertex buffer, when the flush function is called
        //this objects storage buffer gets transferred over to the GPU as a vertex buffer storage

        //primitive types
        void add(float value);
        void add(double value);
        void add(int value);
        void add(char value);
        void add(short value);
        void add(unsigned int value);
        void add(unsigned char value);
        void add(unsigned short value);

        //different vector types
        void add(glm::vec2& value);
        void add(glm::vec3& value);
        void add(glm::vec4& value);

        void add(glm::uvec2& value);
        void add(glm::uvec3& value);
        void add(glm::uvec4& value);

        void add(glm::ivec2& value);
        void add(glm::ivec3& value);
        void add(glm::ivec4& value);

        void add(glm::dvec2& value);
        void add(glm::dvec3& value);
        void add(glm::dvec4& value);

        //different float matrix types
        void add(glm::mat2& value);
        void add(glm::mat2x3& value);
        void add(glm::mat2x4& value);

        void add(glm::mat3& value);
        void add(glm::mat3x2& value);
        void add(glm::mat3x4& value);

        void add(glm::mat4& value);
        void add(glm::mat4x2& value);
        void add(glm::mat4x3& value);

        //double matrix types
        void add(glm::dmat2& value);
        void add(glm::dmat2x3& value);
        void add(glm::dmat2x4& value);

        void add(glm::dmat3& value);
        void add(glm::dmat3x2& value);
        void add(glm::dmat3x4& value);

        void add(glm::dmat4& value);
        void add(glm::dmat4x2& value);
        void add(glm::dmat4x3& value);

        void add(Vertex& value);

        //sends the data accumulated through the add functions to the vertex buffer object on the GPU
        void flush(GLenum value);

        //sets the value of the vertex buffer data store that is on the GPU
        //primitive data types
        void set(int byteOffset, float value);
        void set(int byteOffset, double value);
        void set(int byteOffset, int value);
        void set(int byteOffset, char value);
        void set(int byteOffset, short value);
        void set(int byteOffset, unsigned int value);
        void set(int byteOffset, unsigned char value);
        void set(int byteOffset, unsigned short value);

        //different vector types
        void set(int byteOffset, glm::vec2& value);
        void set(int byteOffset, glm::vec3& value);
        void set(int byteOffset, glm::vec4& value);

        void set(int byteOffset, glm::uvec2& value);
        void set(int byteOffset, glm::uvec3& value);
        void set(int byteOffset, glm::uvec4& value);

        void set(int byteOffset, glm::ivec2& value);
        void set(int byteOffset, glm::ivec3& value);
        void set(int byteOffset, glm::ivec4& value);

        void set(int byteOffset, glm::dvec2& value);
        void set(int byteOffset, glm::dvec3& value);
        void set(int byteOffset, glm::dvec4& value);

        //different float matrix types
        void set(int byteOffset, glm::mat2& value);
        void set(int byteOffset, glm::mat2x3& value);
        void set(int byteOffset, glm::mat2x4& value);

        void set(int byteOffset, glm::mat3& value);
        void set(int byteOffset, glm::mat3x2& value);
        void set(int byteOffset, glm::mat3x4& value);

        void set(int byteOffset, glm::mat4& value);
        void set(int byteOffset, glm::mat4x2& value);
        void set(int byteOffset, glm::mat4x3& value);

        //double matrix types
        void set(int byteOffset, glm::dmat2& value);
        void set(int byteOffset, glm::dmat2x3& value);
        void set(int byteOffset, glm::dmat2x4& value);

        void set(int byteOffset, glm::dmat3& value);
        void set(int byteOffset, glm::dmat3x2& value);
        void set(int byteOffset, glm::dmat3x4& value);

        void set(int byteOffset, glm::dmat4& value);
        void set(int byteOffset, glm::dmat4x2& value);
        void set(int byteOffset, glm::dmat4x3& value);

        void set(int byteOffset, Vertex& value);
};
