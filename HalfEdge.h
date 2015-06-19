#pragma once
#include "Face.h"

class HalfEdge
{
public:
	int emitVert;
	Face* parent, adj;
	HalfEdge* next, opposite;

	HalfEdge(int eVert);
	~HalfEdge();
};

