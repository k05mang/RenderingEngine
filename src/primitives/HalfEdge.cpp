#include "primitives/Face.h"

Face::HalfEdge::HalfEdge(int eVert) : emitVert(eVert), parent(nullptr), adj(nullptr), next(nullptr), prev(nullptr), opposite(nullptr)
{

}


~HalfEdge()
{
      parent = nullptr;
      adj = nullptr;
      next = nullptr;
      prev = nullptr;
      opposite = nullptr;
}

HalfEdge(const HalfEdge& copyTarget)
{
      parent = copyTarget.parent;
      adj = copyTarget.adj;
      next = copyTarget.next;
      prev = copyTarget.prev;
      opposite = copyTarget.opposite;
}

HalfEdge& operator= (const HalfEdge& rhs)
{
      if(this == &rhs) return *this;//handle self assignment
      parent = rhs.parent;
      adj = rhs.adj;
      next = rhs.next;
      prev = rhs.prev;
      opposite = rhs.opposite;
      return *this;
}

HalfEdge(HalfEdge&& moveTarget)
{
      parent = moveTarget.parent;
      adj = moveTarget.adj;
      next = moveTarget.next;
      prev = moveTarget.prev;
      opposite = moveTarget.opposite;

      //set the other objects values to null to prevent deletion of the pointers which is handled by the parent Face class
      moveTarget.parent = nullptr;
      moveTarget.adj = nullptr;
      moveTarget.next = nullptr;
      moveTarget.opposite = nullptr;
}

HalfEdge& operator= (HalfEdge&& rhs)
{
      parent = rhs.parent;
      adj = rhs.adj;
      next = rhs.next;
      prev = rhs.prev;
      opposite = rhs.opposite;

      //set the other objects values to null to prevent deletion of the pointers which is handled by the parent Face class
      rhs.parent = nullptr;
      rhs.adj = nullptr;
      rhs.next = nullptr;
      rhs.opposite = nullptr;
      return *this;
}
