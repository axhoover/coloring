#include "hoovergrapher/graphing/Graph.h"
#include <algorithm>
#include <set>
#include <iterator>
#include <iostream>
#include <sstream>

using namespace hoovergrapher;
using namespace hoovergrapher::graphing;

class Graph::Impl {
public:
  std::set<Vertex> v;
  std::set<Edge> e;
};

Graph::Graph() : mImpl(new Impl) {
  mImpl->v = std::set<Vertex>();
  mImpl->e = std::set<Edge>();
}

Graph::Graph(const Graph &other) : mImpl(new Impl) {
  mImpl->v = other.vertices();
  mImpl->e = other.edges();
}

Graph Graph::operator=(const Graph &other) {
  if (this != &other) {
    mImpl->v = other.vertices();
    mImpl->e = other.edges();
  }
  return *this;
}

bool Graph::addVertex(const Vertex &ver) {
  if(mImpl->v.find(ver) == mImpl->v.end()) {
    mImpl->v.insert(ver);
    return true;
  }
  else {
    return false;
  }
}

bool Graph::addEdge(const Edge &ed) {
  if(mImpl->e.find(ed) == mImpl->e.end()) {
    mImpl->e.insert(ed);
    if(mImpl->v.find(ed.vertex1()) == mImpl->v.end())
      mImpl->v.insert(ed.vertex1());
    if(mImpl->v.find(ed.vertex2()) == mImpl->v.end())
      mImpl->v.insert(ed.vertex2());
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

std::set<Edge> Graph::edges() const {
  return mImpl->e;
}

std::set<Vertex> Graph::vertices() const {
  return mImpl->v;
}

bool Graph::isConnected() const {
  // Placeholder will be implemented
  return false;
}

std::ostream& hoovergrapher::graphing::operator<<(std::ostream &os, const Graph &g) {
  std::set<Vertex> v = g.vertices();
  std::set<Edge> e = g.edges();
  os << std::endl << "Vertices: ";
  for(std::set<Vertex>::iterator i = v.begin(); i!=v.end(); i++){
    os << *i << ", ";
  }
  os << std::endl << "Edges: ";
  for(std::set<Edge>::iterator i = e.begin(); i!=e.end(); i++){
    os << *i << ", ";
  }
  os << std::endl;
  return os;
}

Graph::~Graph() {}
