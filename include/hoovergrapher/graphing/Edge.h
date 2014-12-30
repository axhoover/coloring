#ifndef __EDGE_H__
#define __EDGE_H__

#include <memory>
#include "hoovergrapher/graphing/Vertex.h"

namespace hoovergrapher {
  namespace graphing {
    class Edge {
    public:
      // Canonical Form
      Edge();
      Edge(const Vertex &, const Vertex &);
      Edge(const Edge &);
      Edge operator=(const Edge &);
      ~Edge();
      bool operator==(const Edge &) const;
      // Required for std::set in Graph
      bool operator<(const Edge &) const;

      Vertex vertex1() const;
      Vertex vertex2() const;

      // Prints the two vertices connected to it
      friend std::ostream& operator<<(std::ostream &os, const Edge &e);

    private:
      class Impl;
      std::shared_ptr<Impl> mImpl;
    };
  }
}

#endif // __EDGE_H__
