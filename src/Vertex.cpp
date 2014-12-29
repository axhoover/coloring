#include "hoovergrapher/graphing/Vertex.h"
#include <sstream>

using namespace hoovergrapher;
using namespace hoovergrapher::graphing;

class Vertex::Impl {
public:
  coloring::Color color;
  int num;
};

Vertex::Vertex() : mImpl(new Impl) {
  mImpl->color = coloring::Color();
  mImpl->num = 0;
}

Vertex::Vertex(int n) : mImpl(new Impl) {
  mImpl->color = coloring::Color();
  mImpl->num = n;
}

Vertex::Vertex(const coloring::Color &c, int n) : mImpl(new Impl) {
  mImpl->color = c;
  mImpl->num = n;
}

Vertex::Vertex(const Vertex &other) : mImpl(new Impl) {
  mImpl->color = other.mImpl->color;
  mImpl->num = other.mImpl->num;
}

Vertex Vertex::operator=(const Vertex &other) {
  if (this != &other) {
    mImpl->color = other.mImpl->color;
    mImpl->num = other.mImpl->num;
  }
  return *this;
}

bool Vertex::operator==(const Vertex &other) {
  return mImpl->num == other.mImpl->num;
}

void Vertex::color(const coloring::Color &c) {
  mImpl->color = c;
}

coloring::Color Vertex::color() const {
  return mImpl->color;
}

int Vertex::num() const {
  return mImpl->num;
}

std::ostream& hoovergrapher::graphing::operator<<(std::ostream &os, const Vertex &v) {
  os << "(" << v.num() << ", " << v.color().name() << ")";
  return os;
}

Vertex::~Vertex() {}
