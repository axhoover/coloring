#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <memory>
#include <set>
#include "hoovergrapher/graphing/Vertex.h"
#include "hoovergrapher/graphing/Edge.h"
namespace hoovergrapher {
  namespace graphing {
    class Graph {
    public:
      // Canonical Form
      Graph();
      Graph(const Graph &);
      Graph operator=(const Graph &);
      ~Graph();

      // Used for editting the Graph
      bool addVertex(const Vertex &);
      bool addEdge(const Edge &);
      bool addEdge(const Vertex &, const Vertex &);
      std::set<std::shared_ptr<Edge>> edges() const;
      std::set<std::shared_ptr<Vertex>> vertecies() const;

      // Used for information about the graph
      bool isConnected() const;

    private:
      class Impl;
      std::shared_ptr<Impl> mImpl;
    };
  }
}

#endif // __GRAPH_H__
