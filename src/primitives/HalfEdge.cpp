#include "primitives/Face.h"

Face::HalfEdge::HalfEdge(int eVert) : emitVert(eVert), parent(nullptr), adj(nullptr), next(nullptr), opposite(nullptr)
{

}


~HalfEdge()
{
      parent = nullptr;
      adj = nullptr;
      next = nullptr;
      opposite = nullptr;
}

HalfEdge(const HalfEdge& copyTarget)
{
      parent = copyTarget.parent;
      adj = copyTarget.adj;
      next = copyTarget.next;
      opposite = copyTarget.opposite;
}

HalfEdge& operator= (const HalfEdge& rhs)
{
      if(this == &rhs) return *this;//handle self assignment
      parent = rhs.parent;
      adj = rhs.adj;
      next = rhs.next;
      opposite = rhs.opposite;
      return *this;
}

HalfEdge(HalfEdge&& moveTarget)
{
      parent = move(moveTarget.parent);
      adj = move(moveTarget.adj);
      next = move(moveTarget.next);
      opposite = move(moveTarget.opposite);

      //set the other objects values to null to prevent deletion of the pointers which is handled by the parent Face class
      moveTarget.parent = nullptr;
      moveTarget.adj = nullptr;
      moveTarget.next = nullptr;
      moveTarget.opposite = nullptr;
}

HalfEdge& operator= (HalfEdge&& rhs)
{
      parent = move(rhs.parent);
      adj = move(rhs.adj);
      next = move(rhs.next);
      opposite = move(rhs.opposite);

      //set the other objects values to null to prevent deletion of the pointers which is handled by the parent Face class
      rhs.parent = nullptr;
      rhs.adj = nullptr;
      rhs.next = nullptr;
      rhs.opposite = nullptr;
      return *this;
}
