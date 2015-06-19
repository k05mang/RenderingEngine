#include "Face.h"

Face::Face(int v1, int v2, int v3) : e1(v1), e2(v2), e3(v3)
{
	e1.parent = e2.parent = e3.parent = this;
	e1.next = &e2;
	e2.next = &e3;
	e3.next = &e1;
}

Face::~Face()
{

}

Face::Face(Face&& moveTarget) : e1(std::move(moveTarget.e1)), e2(std::move(moveTarget.e2)), e3(std::move(moveTarget.e3))
{

}

Face& Face::operator= (Face&& moveTarget)
{
	e1 = std::move(moveTarget.e1);
	e2 = std::move(moveTarget.e2);
	e3 = std::move(moveTarget.e3);
}

void Face::storePrim(std::vector<int>& storage)
{
	storage.push_back();
}

void Face::storePrimAdj(std::vector<int>& storage)
{

}
