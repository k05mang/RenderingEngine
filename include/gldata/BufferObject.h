#pragma once
#include <windows.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glcorearb.h>
#include <vector>
 using namespace std;
class BufferObject
{
    private:
        GLuint bufferId;
        unsigned int size;
        vector<unsigned char> data;
    public:
        BufferObject();
        virtual ~BufferObject();
        BufferObject(const BufferObject&) = delete;
        BufferObject& operator=(const BufferObject&) = delete;
        BufferObject(BufferObject&&) = delete;
        BufferObject& operator=(BufferObject&&) = delete;

        int size();
        virtual void bind() = 0;
        virtual void unbind() = 0;
        void flush();
        void erase();

        //primitive types
        void add(int value);
        void add(char value);
        void add(short value);
        void add(unsigned int value);
        void add(unsigned char value);
        void add(unsigned short value);

        //different vector types
        void add(glm::uvec2& value);
        void add(glm::uvec3& value);
        void add(glm::uvec4& value);

        void add(glm::ivec2& value);
        void add(glm::ivec3& value);
        void add(glm::ivec4& value);

        //sets the value of the vertex buffer data store that is on the GPU
        //primitive data types
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
};
