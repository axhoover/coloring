#include "hoovergrapher/coloring/Color.h"

using namespace hoovergrapher;
using namespace hoovergrapher::coloring;

class Color::Impl {
public:
  std::string color_name;
};

Color::Color() : mImpl(new Impl) {
  mImpl->color_name = "None";
}

Color::Color(const std::string &name) : mImpl(new Impl) {
  mImpl->color_name = name;
}

Color::Color(const Color &other) : mImpl(new Impl) {
  mImpl->color_name = other.mImpl->color_name;
}

Color Color::operator=(const Color &other) {
  if (this != &other) {
    mImpl->color_name = other.mImpl->color_name;
  }
  return *this;
}

std::string Color::name() const {
  return mImpl->color_name;
}

Color::~Color() {}
