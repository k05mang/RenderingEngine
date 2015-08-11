#pragma once
#include <windows.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glcorearb.h>

class BufferObject
{
    private:
        GLuint bufferId;
        unsigned int size;
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
        void erase();
};
