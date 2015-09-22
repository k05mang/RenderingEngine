#include "Mesh.h"
#include <vector>

Mesh::Mesh()
{
      //ctor
}

Mesh::~Mesh()
{
      //dtor
}

Mesh::Mesh(const Mesh& copyTarget) : vertices(copyTarget.vertices), faces(copyTarget.faces)
{
      //copy ctor
}

Mesh& Mesh::operator=(const Mesh& rhs)
{
      if (this == &rhs) return *this; // handle self assignment
      vertices(rhs.vertices);
      faces(rhs.faces);
      return *this;
}

Mesh(Mesh&& moveTarget) : vertices(move(moveTarget.vertices)), faces(move(moveTarget.faces))
{

}

Mesh& operator=(Mesh&& rhs)
{
      if (this == &rhs) return *this; // handle self assignment
      vertices(move(rhs.vertices));
      faces(move(rhs.faces));
      return *this;
}

void add(Vertex vert)
{
      vertices.add(vert);
}

void add(Face face)
{
      faces.add(face);
}
