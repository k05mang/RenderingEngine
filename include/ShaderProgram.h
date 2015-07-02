#pragma once

#include "Shader.h"
#include "ShaderUniform.h"
#include <glm.h>

class ShaderProgram
{
    private:
        GLuint programId;
        std::unordered_map<std::string, ShaderUniform> uniforms;
    public:
        ShaderProgram();
        ~ShaderProgram();

        //TODO add some functions to possibly handle array uniforms

        //float uniforms
        void setUniform(float v1);
        void setUniform(float v1, float v2);
        void setUniform(float v1, float v2, float v3);
        void setUniform(float v1, float v2, float v3, float v4);
        void setUniform(const glm::vec1& vec);
        void setUniform(const glm::vec2& vec);
        void setUniform(const glm::vec3& vec);
        void setUniform(const glm::vec4& vec);

        //double uniforms
        void setUniform(double v1);
        void setUniform(double v1, double v2);
        void setUniform(double v1, double v2, double v3);
        void setUniform(double v1, double v2, double v3, double v4);
        void setUniform(const glm::dvec1& vec);
        void setUniform(const glm::dvec2& vec);
        void setUniform(const glm::dvec3& vec);
        void setUniform(const glm::dvec4& vec);

        //int uniforms
        void setUniform(int v1);
        void setUniform(int v1, int v2);
        void setUniform(int v1, int v2, int v3);
        void setUniform(int v1, int v2, int v3, int v4);
        void setUniform(const glm::ivec1& vec);
        void setUniform(const glm::ivec2)& vec;
        void setUniform(const glm::ivec3& vec);
        void setUniform(const glm::ivec4& vec);

        //unsigned int uniforms
        void setUniform(GLuint v1);
        void setUniform(GLuint v1, GLuint v2);
        void setUniform(GLuint v1, GLuint v2, GLuint v3);
        void setUniform(GLuint v1, GLuint v2, GLuint v3, GLuint v4);
        void setUniform(const glm::uvec1& vec);
        void setUniform(const glm::uvec2& vec);
        void setUniform(const glm::uvec3& vec);
        void setUniform(const glm::uvec4& vec);

        //boolean uniforms
        void setUniform(bool v1);
        void setUniform(bool v1, bool v2);
        void setUniform(bool v1, bool v2, bool v3);
        void setUniform(bool v1, bool v2, bool v3, bool v4);
        void setUniform(const glm::bvec1& vec);
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
