#pragma once
#include "gldata/VertexArray.h"
#include <vector>
using namespace std;

class Face
{
public:
      class HalfEdge
	{
	public:
		int emitVert;
		Face *parent, *adj;
		HalfEdge *next, *opposite;

		HalfEdge(int eVert);
		~HalfEdge();
		HalfEdge(const HalfEdge& copyTarget);
            HalfEdge& operator= (const HalfEdge& rhs);
            HalfEdge(HalfEdge&& moveTarget);
            HalfEdge& operator= (HalfEdge&& moveTarget);
	}e1, e2, e3;//edges of this face

	Face(int v1, int v2, int v3);
	~Face();
	Face(const Face& copyTarget);
	Face& operator= (const Face& rhs);
	Face(Face&& moveTarget);
	Face& operator= (Face&& moveTarget);

	/*
		Stores the indices of this face that represent just the triangle primitive
	*/
	void storePrim(VertexArray& buffer);

	/*
		Stores the indices of this face that represent this triangle and it's adjacent faces
		in a manner complient with OpenGL TRIANGLE_ADJACENCY
	*/
	void storePrimAdj(VertexArray& buffer);
};

