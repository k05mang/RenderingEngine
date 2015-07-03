#include "ShaderUniform.h"

/*
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
*/
ShaderUniform::ShaderUniform(std::string& type)
{
    //determine the variable type
    if(type == "float"){
        uniformType = Type::SINGLE;
    }else if(type == "int"){
        uniformType = Type::SINGLE;
    }else if(type == "uint"){
        uniformType = Type::SINGLE;
    }else if(type == "bool"){
        uniformType = Type::SINGLE;
    }else{
        switch(type.front()){
            case 'v'://basic vector type which is a float type
                switch(type.back()){
                    case '2':
                        uniformType = Type::VEC2;
                        break;
                    case '3':
                        uniformType = Type::VEC3;
                        break;
                    case '4':
                        uniformType = Type::VEC4;
                        break;
                }
                break;
            case 'm'://basic matrix type which is a float type
                if(type.length() > 5){//this checks whether the matrix has more than one dimension specifier i.e. 2x3
                    switch(type.at(type.length()-3)){
                        case '2':
                            switch(type.at(type.length()-1)){
                                case '2':
                                    uniformType = Type::MAT2;
                                    break;
                                case '3':
                                    uniformType = Type::MAT2x3;
                                    break;
                                case '4':
                                    uniformType = Type::MAT2x4;
                                    break;
                            }
                            break;
                        case '3':
                            switch(type.at(type.length()-1)){
                                case '2':
                                    uniformType = Type::MAT3x2;
                                    break;
                                case '3':
                                    uniformType = Type::MAT3;
                                    break;
                                case '4':
                                    uniformType = Type::MAT3x4;
                                    break;
                            }
                            break;
                        case '4':
                            switch(type.at(type.length()-1)){
                                case '2':
                                    uniformType = Type::MAT2x4;
                                    break;
                                case '3':
                                    uniformType = Type::MAT4x3;
                                    break;
                                case '4':
                                    uniformType = Type::MAT4;
                                    break;
                            }
                            break;
                    }
                }else{
                   switch(type.back()){
                    case '2':
                        uniformType = Type::MAT2;
                        break;
                    case '3':
                        uniformType = Type::MAT3;
                        break;
                    case '4':
                        uniformType = Type::MAT4;
                        break;
                    }
                }
                break;
            case 'd'://indicates a double type

                //even though it is a double type we designate it as a float
                //the reason is because OpenGL doesn't provide any interface for modifying uniform values
                //using doubles only floats are accepted

                switch(type.at(1)){//since a double can be associated with either a vector or matrix we must determine which it is
                    case 'v'://basic vector type which is a float type
                        switch(type.back()){
                            case '2':
                                uniformType = Type::VEC2;
                                break;
                            case '3':
                                uniformType = Type::VEC3;
                                break;
                            case '4':
                                uniformType = Type::VEC4;
                                break;
                        }
                        break;
                    case 'm'://basic matrix type which is a float type
                        if(type.length() > 5){//this checks whether the matrix has more than one dimension specifier i.e. 2x3
                            switch(type.at(type.length()-3)){
                                case '2':
                                    switch(type.at(type.length()-1)){
                                        case '2':
                                            uniformType = Type::MAT2;
                                            break;
                                        case '3':
                                            uniformType = Type::MAT2x3;
                                            break;
                                        case '4':
                                            uniformType = Type::MAT2x4;
                                            break;
                                    }
                                    break;
                                case '3':
                                    switch(type.at(type.length()-1)){
                                        case '2':
                                            uniformType = Type::MAT3x2;
                                            break;
                                        case '3':
                                            uniformType = Type::MAT3;
                                            break;
                                        case '4':
                                            uniformType = Type::MAT3x4;
                                            break;
                                    }
                                    break;
                                case '4':
                                    switch(type.at(type.length()-1)){
                                        case '2':
                                            uniformType = Type::MAT2x4;
                                            break;
                                        case '3':
                                            uniformType = Type::MAT4x3;
                                            break;
                                        case '4':
                                            uniformType = Type::MAT4;
                                            break;
                                    }
                                    break;
                                }
                            }else{
                               switch(type.back()){
                                case '2':
                                    uniformType = Type::MAT2;
                                    break;
                                case '3':
                                    uniformType = Type::MAT3;
                                    break;
                                case '4':
                                    uniformType = Type::MAT4;
                                    break;
                                }
                            }
                            break;
                }
                break;
            case 'i'://integer version of vector
                switch(type.back()){
                    case '2':
                        uniformType = Type::VEC2;
                        break;
                    case '3':
                        uniformType = Type::VEC3;
                        break;
                    case '4':
                        uniformType = Type::VEC4;
                        break;
                }
                break;
            case 'u'://unsigned integer version of vector
                switch(type.back()){
                    case '2':
                        uniformType = Type::VEC2;
                        break;
                    case '3':
                        uniformType = Type::VEC3;
                        break;
                    case '4':
                        uniformType = Type::VEC4;
                        break;
                }
                break;
            case 'b'://boolean version of vector
                switch(type.back()){
                    case '2':
                        uniformType = Type::VEC2;
                        break;
                    case '3':
                        uniformType = Type::VEC3;
                        break;
                    case '4':
                        uniformType = Type::VEC4;
                        break;
                }
                break;
        }
    }
}

void getLocation(GLuint program, std::string& name)
{
    glGetUniformLocation(program, name.data());
}

void set(GLuint program, const GLfloat* values)
{
    switch(uniformType){
        case Type::SINGLE:
            glUniform1fv(location, 1, values);
            break;
        case Type::VEC2:
            glUniform2fv(location, 1, values);
            break;
        case Type::VEC3:
            glUniform3fv(location, 1, values);
            break;
        case Type::VEC4:
            glUniform4fv(location, 1, values);
            break;
    }
}

void set(GLuint program, const GLint* values)
{
    switch(uniformType){
        case Type::SINGLE:
            glUniform1iv(location, 1, values);
            break;
        case Type::VEC2:
            glUniform2iv(location, 1, values);
            break;
        case Type::VEC3:
            glUniform3iv(location, 1, values);
            break;
        case Type::VEC4:
            glUniform4iv(location, 1, values);
            break;
    }
}

void set(GLuint program, const GLuint* values)
{
    switch(uniformType){
        case Type::SINGLE:
            glUniform1uiv(location, 1, values);
            break;
        case Type::VEC2:
            glUniform2uiv(location, 1, values);
            break;
        case Type::VEC3:
            glUniform3uiv(location, 1, values);
            break;
        case Type::VEC4:
            glUniform4uiv(location, 1, values);
            break;
    }
}


void set(GLuint program, bool transpose, const GLfloat* values)
{
    switch(uniformType){
        case MAT2:
            glUniformMatrix2fv(location, 1, transpose, values);
            break:
        case MAT3:
            glUniformMatrix3fv(location, 1, transpose, values);
            break:
        case MAT4:
            glUniformMatrix4fv(location, 1, transpose, values);
            break:

        case MAT2x3:
            glUniformMatrix2x3fv(location, 1, transpose, values);
            break:
        case MAT3x2:
            glUniformMatrix3x2fv(location, 1, transpose, values);
            break:

        case MAT2x4:
            glUniformMatrix2x4fv(location, 1, transpose, values);
            break:
        case MAT4x2:
            glUniformMatrix4x2fv(location, 1, transpose, values);
            break:

        case MAT3x4:
            glUniformMatrix3x4fv(location, 1, transpose, values);
            break:
        case MAT4x3:
            glUniformMatrix4x3fv(location, 1, transpose, values);
            break:
    }
}

