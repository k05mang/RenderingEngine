#pragma once
#include "Vertex.h"
#include "Face.h"
#include <vector>

using namespace std;
class Mesh
{
      private:
            vector<Vertex> vertices; //!< Member variable "vertices"
            vector<Face> faces; //!< Member variable "faces"
            vector<vector<Face::HalfEdge>> edgeMap;
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
            void add(Vertex vert);

            /** Add a face to this mesh
             *  \param Face to add to the mesh
             */
            void add(Face face);
};
