#include "Face.h"
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

void Face::storePrim(vector<int>& storage)
{
	storage.push_back(e1.emitVert);
	storage.push_back(e2.emitVert);
	storage.push_back(e3.emitVert);
}

void Face::storePrimAdj(vector<int>& storage)
{
	storage.push_back(e1.emitVert);
	storage.push_back(e1.opposite->emitVert);

	storage.push_back(e2.emitVert);
	storage.push_back(e2.opposite->emitVert);

	storage.push_back(e3.emitVert);
	storage.push_back(e3.opposite->emitVert);
}
