#include "primitives/Face.h"

Face::HalfEdge::HalfEdge(int eVert) : emitVert(eVert), parent(nullptr), adj(nullptr), next(nullptr), opposite(nullptr)
{

}


Face::HalfEdge::~HalfEdge()
{
}
