#include "Mesh.h"
#include <vector>

Mesh::Mesh() : finished(false)
{
      //ctor
}

Mesh::~Mesh()
{
      //dtor
}

Mesh::Mesh(const Mesh& copyTarget) : vertices(copyTarget.vertices), faces(copyTarget.faces), edgeMap(copyTarget.edgeMap)
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

Mesh(Mesh&& moveTarget) : vertices(move(moveTarget.vertices)), faces(move(moveTarget.faces)), edgeMap(move(rhs.edgeMap))
{

}

Mesh& operator=(Mesh&& rhs)
{
      vertices(move(rhs.vertices));
      faces(move(rhs.faces));
      return *this;
}

void add(Vertex& vert)
{
      if(!finished){
            vertices.add(vert);
      }
}

void add(Face& face)
{
      if(!finished){
            faces.add(face);

      }
}

void addIndices(VertexArray& vao, GLenum type)
{

}

void finalize()
{
      edgeMap.clear();
      finished = true;
}
