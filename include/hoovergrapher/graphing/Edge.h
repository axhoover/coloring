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
      bool operator==(const Edge &);

    private:
      class Impl;
      std::shared_ptr<Impl> mImpl;
    };
  }
}

#endif // __EDGE_H__
