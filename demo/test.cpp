#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include <sstream>

#include "hoovergrapher/graphing/Vertex.h"
#include "hoovergrapher/graphing/Edge.h"
#include "hoovergrapher/graphing/Graph.h"

#include "hoovergrapher/coloring/Color.h"
//#inlcude "hoovergrapher/coloring/Solver.h"

using namespace hoovergrapher::graphing;
using namespace hoovergrapher::coloring;

int main(int argc, char* argv[]) {
  Graph g = Graph();
  Vertex v0 = Vertex(0);
  Vertex v1(1);
  g.addVertex(v0);
  g.addVertex(v1);
  g.addEdge(v0, v1);
  std::cout << g << std::endl;
  return 0;
}
