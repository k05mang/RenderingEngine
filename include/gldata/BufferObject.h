#pragma once
#include <windows.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glcorearb.h>
#include <vector>
#include <glm.hpp>
#include "primitives/Vertex.h"
#include <memory>
 using namespace std;
class BufferObject
{
    private:
        shared_ptr<GLuint> bufferId;
        unsigned int numBytes;
        vector<unsigned char> data;
        GLenum type;
    public:
        BufferObject(GLenum type);
        ~BufferObject();
        BufferObject(const BufferObject& copyTarget);
        BufferObject& operator=(const BufferObject& rhs);
        BufferObject(BufferObject&&) = delete;
        BufferObject& operator=(BufferObject&&) = delete;

        int size();
        void bind();
        void unbind();
        void flush(GLenum usage);
        void erase();

        //primitive types
        inline void add(float value);
        inline void add(double value);
        inline void add(char value);
        inline void add(short value);
        inline void add(int value);
        inline void add(unsigned char value);
        inline void add(unsigned short value);
        inline void add(unsigned int value);

        //different vector types
        void add(glm::uvec2& value);
        void add(glm::uvec3& value);
        void add(glm::uvec4& value);

        void add(glm::ivec2& value);
        void add(glm::ivec3& value);
        void add(glm::ivec4& value);

        void add(glm::vec2& value);
        void add(glm::vec3& value);
        void add(glm::vec4& value);

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
        void set(int byteOffset, glm::uvec2& value);
        void set(int byteOffset, glm::uvec3& value);
        void set(int byteOffset, glm::uvec4& value);

        void set(int byteOffset, glm::ivec2& value);
        void set(int byteOffset, glm::ivec3& value);
        void set(int byteOffset, glm::ivec4& value);

        void set(int byteOffset, glm::vec2& value);
        void set(int byteOffset, glm::vec3& value);
        void set(int byteOffset, glm::vec4& value);

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
