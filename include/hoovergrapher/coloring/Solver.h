#ifndef __SOLVER_H__
#define __SOLVER_H__

#include <memory>
#include <vector>
#include "hoovergrapher/graphing/Vertex.h"
#include "hoovergrapher/graphing/Edge.h"
#include "hoovergrapher/graphing/Graph.h"
#include "hoovergrapher/coloring/Color.h"

namespace hoovergrapher {
  namespace coloring {
    class Solver {
    public:
      // Canonical Form
      Solver();
      Solver(const graphing::Graph &);
      Solver(const Solver &);
      Solver operator=(const Solver &);
      ~Solver();

      // Sets the colors that the user would like to use for the colorring
      void set_colors(std::vector<Color> colors);
      // Finds a solution for the graph with the fewest colors
      bool solve();
      // Return colorred graph. Calls solve if not already solved
      graphing::Graph solution_graph();
      // Returns the number of colors required or the number specified
      int num_colors() const;

    private:
      class Impl;
      std::shared_ptr<Impl> mImpl;
    };
  }
}

#endif // __SOLVER_H__
