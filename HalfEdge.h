#include "Face.h"
#pragma once

class HalfEdge
{
public:
	int emitVert;
	Face* parent, adj;
	HalfEdge* next, opposite;

	HalfEdge(int eVert);
	~HalfEdge();
};

