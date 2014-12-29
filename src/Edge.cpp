#include "hoovergrapher/graphing/Edge.h"
#include <sstream>

using namespace hoovergrapher;
using namespace hoovergrapher::graphing;

class Edge::Impl {
public:
  Vertex v1;
  Vertex v2;
  float weight;
};

Edge::Edge() : mImpl(new Impl) {
  mImpl->v1 = Vertex();
  mImpl->v2 = Vertex();
  mImpl->weight = 1;
}

Edge::Edge(const Vertex &ver1, const Vertex &ver2) : mImpl(new Impl) {
  mImpl->v1 = ver1;
  mImpl->v2 = ver2;
  mImpl->weight = 1;
}

Edge::Edge(const Edge &other) : mImpl(new Impl) {
  mImpl->v1 = other.mImpl->v1;
  mImpl->v2 = other.mImpl->v2;
  mImpl->weight = other.mImpl->weight;
}

Edge Edge::operator=(const Edge &other) {
  if (this != &other) {
    mImpl->v1 = other.mImpl->v1;
    mImpl->v2 = other.mImpl->v2;
    mImpl->weight = other.mImpl->weight;
  }
  return *this;
}

bool Edge::operator==(const Edge &other) {
  if(mImpl->v1 == (other.mImpl->v1) &&  mImpl->v2 == (other.mImpl->v2))
    return true;
  if(mImpl->v1 == (other.mImpl->v2) &&  mImpl->v2 == (other.mImpl->v1))
    return true;
  return false;
}

std::ostream& Edge::operator<<(std::ostream &os, const Edge &e) {
  os << "(" << e.mImpl->v1.num() << ", " << e.mImpl->v2.num() << ")";
  return os;
}

Edge::~Edge() {}
