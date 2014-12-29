#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <memory>
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
      void addVertex(const Vertex &);
      void addEdge(const Edge &);
      void addEdge(const Vertex &, const Vertex &);
      std::vector<Edge> edges() const;
      std::vector<Vertex> vertecies() const;

      // Used for information about the graph
      bool isConnected() const;

    private:
      class Impl;
      std::shared_ptr<Impl> mImpl;
    };
  }
}

#endif // __GRAPH_H__
