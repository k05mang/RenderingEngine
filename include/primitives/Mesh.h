#pragma once
#include "Vertex.h"
#include "Face.h"
#inlcude "gldata/VertexArray.h"


#include <windows.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glcorearb.h>

#include <vector>

using namespace std;
class Mesh
{
      private:
            bool finished;
            vector<Vertex> vertices; //holds the vertices for the mesh
            vector<Face> faces; //holds the faces of the mesh
            vector<vector<Face::HalfEdge*>> edgeMap;//mapping of the halfEdges for the mesh
            //each index of outer most array indicates the index of a vertex in the mesh
            //the inner vector for each of these, indicates the halfedges that eminate from that vertex
            //this map is used to create a halfedge data structure
      public:
            /** Default constructor */
            Mesh();

            /** Default destructor */
            ~Mesh();

            /** Copy constructor
             *  \param other Object to copy from
             */
            Mesh(const Mesh& copyTarget);

            /** Copy Assignment operator
             *  \param other Object to assign from
             *  \return A reference to this
             */
            Mesh& operator=(const Mesh& rhs);

            /** Move constructor
             *  \param other Object to move from
             */
            Mesh(Mesh&& moveTarget);

            /** Move Assignment operator
             *  \param other Object to assign from
             *  \return A reference to this
             */
            Mesh& operator=(Mesh&& rhs);

            /** Add a vertex to this mesh
             *  \param Vertex to add to the mesh
             */
            void add(Vertex& vert);

            /** Add a face to this mesh
             *  \param Face to add to the mesh
             */
            void add(Face& face);

            void addIndices(VertexArray& vao, GLenum type);

            //clears the edgeMap variable to alleviate memory and restricts new additions to this meshes faces or vertices
            void finalize();
};
