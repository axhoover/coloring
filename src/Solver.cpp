#include "hoovergrapher/coloring/Solver.h"
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <memory>
#include <iostream>

using namespace hoovergrapher;
using namespace hoovergrapher::coloring;

class Solver::Impl {
public:
  graphing::Graph graph;
  int num_colors;
  bool is_solved;
  std::vector<Color> colors;

  bool graph_solved() {
    std::set<graphing::Edge> e = graph.edges();
    for(std::set<graphing::Edge>::iterator i = e.begin(); i!=e.end(); i++){
      graphing::Edge ed = *i;
      if(ed.vertex1().color() == ed.vertex2().color())
        return false;
    };
    return true;
  }

  bool solve_graph() {
    std::set<graphing::Vertex> v = graph.vertices();
    int size = v.size();
    if(v.empty()) {
      return false;
    }
    if (colors.size() < size) {
      std::cout << "NOT ENOUGH COLORS SPECIFIED" << std::endl;
      return false;
    }
    // Bruteforce
    int *col_array = new int[size];
    for(int i = 0; i < size; i++) {col_array[i] = 0;}
    for(int i = 0; i < pow(colors.size() - 1, size); i++) {
      if(graph_solved()) {
        delete[] col_array;
        return true;
      }
      else {
        col_array[size-1]++;
        for(int q = size-1; q > 0; q--) {
          if(col_array[q] > colors.size()-2) {
            col_array[q] = 0;
            col_array[q-1]++;
          }
        }
      }
    }
    delete[] col_array;
    return false;
  }
};

Solver::Solver() : mImpl(new Impl) {
  mImpl->graph = graphing::Graph();
  mImpl->num_colors = -1;
  mImpl->is_solved = false;
}

Solver::Solver(const graphing::Graph &g) : mImpl(new Impl) {
  mImpl->graph = graphing::Graph(g);
  mImpl->num_colors = -1;
  mImpl->is_solved = false;
}

Solver::Solver(const Solver &other) : mImpl(new Impl) {
  mImpl->graph = other.mImpl->graph;
  mImpl->num_colors = other.mImpl->num_colors;
  mImpl->is_solved = other.mImpl->is_solved;
}

Solver Solver::operator=(const Solver &other) {
  if (this != &other) {
    mImpl->graph = other.mImpl->graph;
    mImpl->num_colors = other.mImpl->num_colors;
    mImpl->is_solved = other.mImpl->is_solved;
  }
  return *this;
}

void Solver::set_colors(const std::vector<Color> &colors) {
  mImpl->colors = colors;
}

int Solver::num_colors() const {
  if(mImpl->is_solved) return mImpl->num_colors;
  else return -1;
}

graphing::Graph Solver::solution_graph() {
  if(mImpl->is_solved) return mImpl->graph;
  else {
    solve();
    return mImpl->graph;
  }
}

bool Solver::solve() {
  mImpl->solve_graph();
  if(mImpl->num_colors == -1) return false;
  else mImpl->is_solved = true;
  return mImpl->is_solved;
}

bool Solver::solve(graphing::Graph &g, const std::vector<Color> &colors) {
  Solver s(g);
  s.set_colors(colors);
  bool r = s.solve();
  g = s.solution_graph();
  return r;
}

Solver::~Solver() {}
