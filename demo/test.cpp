#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include <sstream>

#include "hoovergrapher/graphing/Vertex.h"
#include "hoovergrapher/graphing/Edge.h"
#include "hoovergrapher/graphing/Graph.h"

#include "hoovergrapher/coloring/Color.h"
#include "hoovergrapher/coloring/Solver.h"

using namespace hoovergrapher::graphing;
using namespace hoovergrapher::coloring;

int main(int argc, char* argv[]) {
  Graph g = Graph();
  Vertex v0 = Vertex(0);
  Vertex v1(1);
  Vertex v2(2);
  Vertex v3(3);
  g.addVertex(v0);
  g.addVertex(v1);
  g.addVertex(v2);
  g.addVertex(v3);
  g.addEdge(v0, v1);
  g.addEdge(v0, v2);
  g.addEdge(v1, v2);
  g.addEdge(v0, v3);
  g.addEdge(v1, v3);
  std::vector<Color> colors;
  colors.push_back(Color("Red"));
  colors.push_back(Color("Green"));
  colors.push_back(Color("Blue"));
  colors.push_back(Color("yellow"));
  std::cout << Solver::solve(g, colors) << std::endl;
  std::cout << &g << std::endl;
  return 0;
}
