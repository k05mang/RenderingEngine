#include "primitives/Vertex.h"
#include <geometric.hpp>

Vertex::Vertex(float x, float y, float z,
	float nx, float ny, float nz,
	float u, float v) : pos(x,y,z), normal(nx,ny,nz), uv(u,v)
{
	normal / glm::length(normal);
}

Vertex::Vertex(const Vertex& copyTarget) : pos(copyTarget.pos), normal(copyTarget.normal), uv(copyTarget.uv)
{

}

Vertex& Vertex::operator= (const Vertex& copyTarget)
{
	if (this == &copyTarget) return *this;// handle self assignment
       pos(copyTarget.pos);
       normal(copyTarget.normal);
       uv(copyTarget.uv);

    return *this;
}

Vertex::Vertex(Vertex&& moveTarget) : pos(move(moveTarget.pos)), normal(move(moveTarget.normal)), uv(move(moveTarget.uv))
{

}

Vertex& Vertex::operator= (Vertex&& moveTarget)
{
	pos = move(moveTarget.pos);
	normal = move(moveTarget.normal);
	uv = move(moveTarget.uv);

	return *this;
}

bool Vertex::operator== (const Vertex& equal) const
{
	return pos == equal.pos &&
		normal == equal.normal &&
			uv == equal.uv;
}

glm::vec3& Vertex::getPos()
{
	return pos;
}

void Vertex::setPos(glm::vec3& newPos)
{
	pos = newPos;
}

void Vertex::setPos(float x, float y, float z)
{
	pos = glm::vec3(x, y, z);
}

glm::vec3& Vertex::getNormal()
{
	return normal;
}

void Vertex::setNormal(glm::vec3& newNorm)
{
	normal = glm::normalize(newNorm);
}

void Vertex::setNormal(float nx, float ny, float nz)
{
	normal = glm::normalize(glm::vec3(nx, ny, nz));
;}

glm::vec2& Vertex::getUV()
{
	return uv;
}

void Vertex::setUV(glm::vec2& newUV)
{
	uv = newUV;
}

void Vertex::setUV(float u, float v)
{
	uv = glm::vec2(u, v);
}

void Vertex::store(vector<float>& buffer)
{
	buffer.push_back(pos.x);
	buffer.push_back(pos.y);
	buffer.push_back(pos.z);

	buffer.push_back(normal.x);
	buffer.push_back(normal.y);
	buffer.push_back(normal.z);

	buffer.push_back(uv.x);
	buffer.push_back(uv.y);
}

//TODO change this to byte uploading
void Vertex::store(vector<unsigned char>& buffer)
{
	auto add = [&buffer](float target){

	    unsigned char const * bytes = reinterpret_cast<unsigned char const *>(&target);
	    buffer.push_back(bytes[0]);
	    buffer.push_back(bytes[1]);
	    buffer.push_back(bytes[2]);
	    buffer.push_back(bytes[3]);
	};

	add(pos.x);
	add(pos.y);
	add(pos.z);

	add(normal.x);
	add(normal.y);
	add(normal.z);

	add(uv.x);
	add(uv.y);
}
