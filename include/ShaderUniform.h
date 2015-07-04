#pragma once

#include <glm/glm.h>
#include <GL/gl.h>

class ShaderUniform
{
    private:
        enum Type{
                SINGLE,
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
        ShaderUniform(std::string& type);
        ~ShaderUniform() = default;

        void getLocation(GLuint program, std::string& name);

        /**
         *
         * Handles the data upload for uniforms that are float type vectors
         *
         * program: the shader program that this shader uniform is associated with
         * values: the values to pass to the OpenGL function to set the uniform to
         *
         */
        void set(GLuint program, const GLfloat* values);

        /**
         *
         * Handles the data upload for uniforms that are integer type vectors
         *
         * program: the shader program that this shader uniform is associated with
         * values: the values to pass to the OpenGL function to set the uniform to
         *
         */
        void set(GLuint program, const GLint* values);

        /**
         *
         * Handles the data upload for uniforms that are unsigned integer type vectors
         *
         * program: the shader program that this shader uniform is associated with
         * values: the values to pass to the OpenGL function to set the uniform to
         *
         */
        void set(GLuint program, const GLuint* values);

        /**
         *
         * Handles the data upload for uniforms that are matrix types
         *
         * program: the shader program that this shader uniform is associated with
         * transpose: tells the OpenGL function whether it should transpose the values when they are being uploaded
         * values: the values to pass to the OpenGL function to set the uniform to
         *
         */
        void set(GLuint program, bool transpose, const GLfloat* values);
};
