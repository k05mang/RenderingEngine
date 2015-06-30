#pragma once
#include <vector>
#include "HalfEdge.h"

class Face
{
private:
	HalfEdge e1, e2, e3;//edges of this face
public:
	Face(int v1, int v2, int v3);
	~Face();
	Face(const Face& copy) = delete;
	Face& operator= (const Face& copy) = delete;
	Face(Face&& moveTarget);
	Face& operator= (Face&& moveTarget);

	/*
		Stores the indices of this face that represent just the triangle primitive
	*/
	void storePrim(std::vector<int>& storage);

	/*
		Stores the indices of this face that represent this triangle and it's adjacent faces
		in a manner complient with OpenGL TRIANGLE_ADJACENCY
	*/
	void storePrimAdj(std::vector<int>& storage);
};

