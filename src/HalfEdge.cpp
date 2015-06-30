#include "HalfEdge.h"

HalfEdge::HalfEdge(int eVert) : emitVert(eVert), parent(nullptr), adj(nullptr), next(nullptr), opposite(nullptr)
{
	
}


HalfEdge::~HalfEdge()
{
}
