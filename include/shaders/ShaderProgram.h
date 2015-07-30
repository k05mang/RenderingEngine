#pragma once

#include "Shader.h"
#include <glm.hpp>
using namespace std;

class ShaderProgram
{
    private:
        GLuint programId;
    public:
        ShaderProgram();
        ~ShaderProgram();
        void bind();
        void unbind();
        void erase();
        void add(Shader shader);
        bool link();
        string getErrorLog();


        //TODO add some functions to possibly handle array uniforms

        //float uniforms
        void setUniform(float v1);
        void setUniform(float v1, float v2);
        void setUniform(float v1, float v2, float v3);
        void setUniform(float v1, float v2, float v3, float v4);
        void setUniform(const glm::vec2& vec);
        void setUniform(const glm::vec3& vec);
        void setUniform(const glm::vec4& vec);

        //int uniforms
        void setUniform(int v1);
        void setUniform(int v1, int v2);
        void setUniform(int v1, int v2, int v3);
        void setUniform(int v1, int v2, int v3, int v4);
        void setUniform(const glm::ivec2& vec);
        void setUniform(const glm::ivec3& vec);
        void setUniform(const glm::ivec4& vec);

        //unsigned int uniforms
        void setUniform(GLuint v1);
        void setUniform(GLuint v1, GLuint v2);
        void setUniform(GLuint v1, GLuint v2, GLuint v3);
        void setUniform(GLuint v1, GLuint v2, GLuint v3, GLuint v4);
        void setUniform(const glm::uvec2& vec);
        void setUniform(const glm::uvec3& vec);
        void setUniform(const glm::uvec4& vec);

        //boolean uniforms
        void setUniform(bool v1);
        void setUniform(bool v1, bool v2);
        void setUniform(bool v1, bool v2, bool v3);
        void setUniform(bool v1, bool v2, bool v3, bool v4);
        void setUniform(const glm::bvec2& vec);
        void setUniform(const glm::bvec3& vec);
        void setUniform(const glm::bvec4& vec);

        //standard square matrices
        void setUniform(bool transpose, const glm::mat2& mat);
        void setUniform(bool transpose, const glm::mat3& mat);
        void setUniform(bool transpose, const glm::mat4& mat);

        //non square matrices
        void setUniform(bool transpose, const glm::mat2x3& mat);
        void setUniform(bool transpose, const glm::mat3x2& mat);

        void setUniform(bool transpose, const glm::mat2x4& mat);
        void setUniform(bool transpose, const glm::mat4x2& mat);

        void setUniform(bool transpose, const glm::mat3x4& mat);
        void setUniform(bool transpose, const glm::mat4x3& mat);
};
