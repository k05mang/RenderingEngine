#pragma once
#include <vector>
#include "HalfEdge.h"

class Face
{
private:
	HalfEdge e1, e2, e3;
public:
	Face(int v1, int v2, int v3);
	~Face();
	Face(const Face& copy) = delete;
	Face& operator= (const Face& copy) = delete;
	Face(Face&& moveTarget);
	Face& operator= (Face&& moveTarget);

	void storePrim(std::vector<int>& storage);
	void storePrimAdj(std::vector<int>& storage);
};

