#ifndef __SOLVER_H__
#define __SOLVER_H__

#include <memory>
#include "hoovergrapher/graphing/Vertex.h"
#include "hoovergrapher/graphing/Edge.h"
#include "hoovergrapher/graphing/Graph.h"

namespace hoovergrapher {
  namespace coloring {
    class Solver {
    public:
      // Canonical Form
      Solver();
      Solver(const graphing::Graph &)
      Solver(const Solver &);
      Solver operator=(const Solver &);
      ~Solver();

      void solve();
      graphing::Graph solution();

    private:
      class Impl;
      std::shared_ptr<Impl> mImpl;
    };
  }
}

#endif // __SOLVER_H__
