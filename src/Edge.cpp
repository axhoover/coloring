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

Vertex Edge::vertex1() const {
  return mImpl->v1;
}

Vertex Edge::vertex2() const {
  return mImpl->v2;
}

bool Edge::operator==(const Edge &other) const {
  if(mImpl->v1 == (other.mImpl->v1) &&  mImpl->v2 == (other.mImpl->v2))
    return true;
  if(mImpl->v1 == (other.mImpl->v2) &&  mImpl->v2 == (other.mImpl->v1))
    return true;
  return false;
}

bool Edge::operator<(const Edge &other) const {
  return !(*this == other);
}

std::ostream& hoovergrapher::graphing::operator<<(std::ostream &os, const Edge &e) {
  os << "(" << e.vertex1().num() << ", " << e.vertex2().num() << ")";
  return os;
}

Edge::~Edge() {}
