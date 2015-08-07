#include "VertexPointers.h"

VertexPointers::VertexPointers()
{
    //ctor
}

VertexPointers::~VertexPointers()
{
    //dtor
}

void VertexPointers::addAttrib(Types type, bool normalize)
{
    //lambda function for performing the data update and adding the new variable to the list
    void addData = [attributes&, stride&, normalize](int size, int increment, GLenum type){
        stride += increment;
        for(VertexAttrib attrib : atrributes){
            attrib.stride = stride;
        }
        attributes.push_back(VertexAttrib(size, type, normalize, stride, stride-increment));
    };
    switch(type){
        case Types::BYTE:
            addData(1, sizeof(byte), GL_BYTE);
            break;
        case Types::UBYTE:
            addData(1, sizeof(unsigned byte), GL_UNSIGNED_BYTE);
            break;
        case Types::SHORT:
            addData(1, sizeof(short), GL_SHORT);
            break;
        case Types::USHORT:
            addData(1, sizeof(unsigned short), GL_UNSIGNED_SHORT);
            break;
        case Types::INT:
            addData(1, sizeof(int), GL_INT);
            break;
        case Types::UINT:
            addData(1, sizeof(unsigned int), GL_UNSIGNED_INT);
            break;
        case Types::FLOAT:
            addData(1, sizeof(float), GL_FLOAT);
            break;
        case Types::BOOL:
            addData(1, sizeof(bool), GL_BOOL);
            break;
        case Types::VEC2:
            addData(2, sizeof(float), GL_FLOAT);
            break;
        case Types::VEC3:
            addData(3, sizeof(float), GL_FLOAT);
            break;
        case Types::VEC4:
            addData(4, sizeof(float), GL_FLOAT);
            break;
        case Types::IVEC2:
            addData(2, sizeof(int), GL_INT);
            break;
        case Types::IVEC3:
            addData(3, sizeof(int), GL_INT);
            break;
        case Types::IVEC4:
            addData(4, sizeof(int), GL_INT);
            break;
        case Types::UVEC2:
            addData(2, sizeof(unsigned int), GL_UNSIGNED_INT);
            break;
        case Types::UVEC3:
            addData(3, sizeof(unsigned int), GL_UNSIGNED_INT);
            break;
        case Types::UVEC4:
            addData(4, sizeof(unsigned int), GL_UNSIGNED_INT);;
            break;
        case Types::BVEC2:
            addData(2, sizeof(bool), GL_BOOL);
            break;
        case Types::BVEC3:
            addData(3, sizeof(bool), GL_BOOL);
            break;
        case Types::BVEC4:
            addData(4, sizeof(bool), GL_BOOL);
            break;
    }
}

void VertexPointers::bindAttribs()
{
    for(int attrib = 0; attrib < attributes.size(); attrib++){
        VertexAttrib& current = attributes[attrib];
        glVertexAttribPointer(attrib, current.size, current.type, current.normalize, current.stride, current.offset);
    }
}
