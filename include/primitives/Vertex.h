#pragma once
#include <vec3.hpp>
#include <vec2.hpp>
#include <vector>

using namespace std;
class Vertex{
private:
	glm::vec3 pos;
	glm::vec3 normal;
	glm::vec2 uv;
public:
	Vertex(float x = 0.0f, float y = 0.0f, float z = 0.0f,
		float nx = 0.33f, float ny = 0.33f, float nz = 0.33f,
		float u = 0.0f, float v = 0.0f);
	~Vertex() = default;
	Vertex(const Vertex& copyTarget);
	Vertex& operator= (const Vertex& rhs);
	Vertex(Vertex&& moveTarget);
	Vertex& operator= (Vertex&& rhs);

	bool operator== (const Vertex& equal) const;

	/*
		Gets the position stored in this vertex
	*/
	glm::vec3& getPos();

	/*
		Sets the value of the position vector of this vertex with another vector
	*/
	void setPos(glm::vec3& newPos);
	/*
		Sets the value of the position vector of this vertex with 3 float values
	*/
	void setPos(float x, float y, float z);

	/*
		Gets the normal stored in this vertex
	*/
	glm::vec3& getNormal();
	/*
		Sets the value of the normal vector of this vertex with another vector
	*/
	void setNormal(glm::vec3& newNorm);
	/*
		Sets the value of the normal vector of this vertex with 3 float values
	*/
	void setNormal(float nx, float ny, float nz);

	/*
		Gets the texture corrdinates stored in this vertex
	*/
	glm::vec2& getUV();
	/*
		Sets the value of the UV vector of this vertex with another vector
	*/
	void setUV(glm::vec2& newUV);
	/*
		Sets the value of the UV vector of this vertex with 2 float values
	*/
	void setUV(float u, float v);

	void store(vector<float>& buffer);

	void store(vector<unsigned char>& buffer);
};
