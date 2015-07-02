#pragma once

#include <glm>

class ShaderUniform
{
    private:
        enum BaseType(
                INT,
                FLOAT,
                UINT
        ) base;

        enum UniformType{
                VEC1,
                VEC2,
                VEC3,
                VEC4,

                MAT2,
                MAT3,
                MAT4,

                MAT2x3,
                MAT3x2,

                MAT2x4,
                MAT4x2,

                MAT3x4,
                MAT4x3

        } uniformType;
        GLint location;
    public:
        ShaderUniform(GLuint program, std::string& type);
        ~ShaderUniform();
        ShaderUniform(const ShaderUniform& other);
        ShaderUniform& operator=(const ShaderUniform& other);
        ShaderUniform(ShaderUniform&& moveTarget);
        ShaderUniform& operator= (ShaderUniform&& rhs);

        void set(GLuint program, const GLfloat* values);
        void set(GLuint program, const GLint* values);
        void set(GLuint program, const GLuint* values);
        void set(GLuint program, const GLboolean* values);

        void set(GLuint program, bool transpose, const GLfloat* values);
        void set(GLuint program, bool transpose, const GLint* values);
        void set(GLuint program, bool transpose, const GLuint* values);
        void set(GLuint program, bool transpose, const GLboolean* values);
};
