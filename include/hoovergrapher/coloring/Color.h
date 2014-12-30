#ifndef __COLOR_H__
#define __COLOR_H__

#include <memory>
#include <string>

namespace hoovergrapher {
  namespace coloring {
    class Color {
    public:
      // Canonical Form
      Color();
      Color(const std::string &);
      Color(const Color &);
      Color operator=(const Color &);
      bool operator==(const Color &);
      ~Color();
      std::string name() const;

    private:
      class Impl;
      std::shared_ptr<Impl> mImpl;
    };
  }
}

#endif // __COLOR_H__
