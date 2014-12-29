#ifndef __COLOR_H__
#define __COLOR_H__

#include <memory>

namespace hoovergrapher {
  namespace coloring {
    class Color {
    public:
      Color();
      Color(const Color &);
      Color operator=(const Color &);
      ~Color();

    private:
      class Impl;
      std::shared_ptr<Impl> mImpl;
    };
  }
}

#endif // __COLOR_H__
