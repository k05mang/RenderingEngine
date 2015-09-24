#include "Mesh.h"
#include <stdexcept>

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
            //edges in the opposite winding direction for this face
            //these are the edges we want from the edge map
            //if these are in the edge map then we can get the half edge
            //needed for this faces half edge related to that edge
            pair<int, int> revEdge1(face.e1.emitVert, face.e3.emitVert);
            pair<int, int> revEdge2(face.e3.emitVert, face.e2.emitVert);
            pair<int, int> revEdge3(face.e2.emitVert, face.e1.emitVert);

            auto find = [&edgeMap](pair<int, int>& target){
                  try{
                        FaceHalfEdge* value = edgeMap.at(target);
                        return value;
                  }catch(out_of_range& e){
                        return nullptr;
                  }
            }

            //try finding the first edge
            Face::HalfEdge* found = find(revEdge1);
            //if found set the appropriate half edge in the face to the found value
            if(found){
                  face.e3->opposite = found;
            }else{//otherwise add this to the edge map
                  edgeMap.insert(pair<pair<int, int>, Face::HalfEdge*>
                                 (make_pair(face.e3.emitVert, face.e1.emitVert), face.e3));
            }

            //try finding the second edge
            Face::HalfEdge* found = find(revEdge2);
            //if found set the appropriate half edge in the face to the found value
            if(found){
                  face.e2->opposite = found;
            }else{//otherwise add this to the edge map
                  edgeMap.insert(pair<pair<int, int>, Face::HalfEdge*>
                                 (make_pair(face.e2.emitVert, face.e3.emitVert), face.e2));
            }

            //try finding the third edge
            Face::HalfEdge* found = find(revEdge3);
            //if found set the appropriate half edge in the face to the found value
            if(found){
                  face.e1->opposite = found;
            }else{//otherwise add this to the edge map
                  edgeMap.insert(pair<pair<int, int>, Face::HalfEdge*>
                                 (make_pair(face.e1.emitVert, face.e2.emitVert), face.e1));
            }
            faces.add(face);
      }
}

void addIndices(VertexArray& vao, GLenum type)
{
      switch(type){
            //set indices for rendering points
            case GL_POINT:
                  break;

            //set indices for rendering different line types
            case GL_LINES:
                  break;
            case GL_LINE_STRIP:
                  break;
            case GL_LINE_LOOP:
                  break;
            case GL_LINES_ADJACENCY:
                  break;
            case GL_LINE_STRIP_ADJACENCY:
                  break;

            case GL_TRIANGLES:
                  break;
            case GL_TRIANGLE_STRIP:
                  break;
            case GL_TRIANGLE_FAN:
                  break;
            case GL_TRIANGLES_ADJACENCY:
                  break;
            case GL_TRIANGLE_STRIP_ADJACENCY:
                  break;
      }
      indexOrder = type;
}

void finalize()
{
      edgeMap.clear();
      finished = true;
}
