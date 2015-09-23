#include "primitives/Face.h"
using namespace std;

Face::Face(int v1, int v2, int v3) : e1(v1), e2(v2), e3(v3)
{
	e1.parent = e2.parent = e3.parent = this;//set the halfedges parent face to this face
	//set the halfedges to point to each other forming a winding for this face
	//this is strictly based on how the vertex indices were passed to the face
	e1.next = &e2;
	e2.next = &e3;
	e3.next = &e1;
}

Face::~Face()
{

}

Face(const Face& copyTarget) : e1(moveTarget.e1), e2(moveTarget.e2), e3(moveTarget.e3)
{

}

Face& operator= (const Face& rhs)
{
      if(this == &rhs) return *this;//handle self assignment
	e1(moveTarget.e1);
	e2(moveTarget.e2);
	e3(moveTarget.e3);

	return *this;
}

Face::Face(Face&& moveTarget) : e1(move(moveTarget.e1)), e2(move(moveTarget.e2)), e3(move(moveTarget.e3))
{

}

Face& Face::operator= (Face&& moveTarget)
{
	e1 = move(moveTarget.e1);
	e2 = move(moveTarget.e2);
	e3 = move(moveTarget.e3);

	return *this;
}

void Face::storePrim(VertexArray& buffer)
{
	buffer.add(e1.emitVert);
	buffer.add(e2.emitVert);
	buffer.add(e3.emitVert);
}

void Face::storePrimAdj(VertexArray& buffer)
{
	buffer.add(e1.emitVert);
	buffer.add(e1.opposite->emitVert);

	buffer.add(e2.emitVert);
	buffer.add(e2.opposite->emitVert);

	buffer.add(e3.emitVert);
	buffer.add(e3.opposite->emitVert);
}
