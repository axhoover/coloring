#include "hoovergrapher/graphing/Graph.h"
#include <algorithm>

using namespace hoovergrapher;
using namespace hoovergrapher::graphing;

class Graph::Impl {
public:
  std::set<std::shared_ptr<Vertex>> v;
  std::set<std::shared_ptr<Edge>> e;
};

Graph::Graph() : mImpl(new Impl) {}

Graph::Graph(const Graph &other) {
  mImpl->v = other.mImpl->v;
  mImpl->e = other.mImpl->e;
}

Graph Graph::operator=(const Graph &other) {
  if (this != &other) {
    mImpl->v = other.mImpl->v;
    mImpl->e = other.mImpl->e;
  }
  return *this;
}

bool Graph::addVertex(const Vertex &ver) {
  std::shared_ptr<Vertex> ver_ptr(new Vertex(ver));
  if(mImpl->v.find(ver_ptr) != mImpl->v.end()) {
    mImpl->v.insert(ver_ptr);
    return true;
  }
  else {
    return false;
  }
}

bool Graph::addEdge(const Edge &ed) {
  std::shared_ptr<Edge> ed_ptr(new Edge(ed));
  if(mImpl->e.find(ed_ptr) != mImpl->e.end()) {
    mImpl->e.insert(ed_ptr);
    return true;
  }
  else {
    return false;
  }
}

bool Graph::addEdge(const Vertex &v1, const Vertex &v2) {
  Edge ed(v1, v2);
  return addEdge(ed);
}

std::set<std::shared_ptr<Edge>> Graph::edges() const {
  return mImpl->e;
}

std::set<std::shared_ptr<Vertex>> Graph::vertecies() const {
  return mImpl->v;
}

bool Graph::isConnected() const {
  return false;
}

Graph::~Graph() {}
