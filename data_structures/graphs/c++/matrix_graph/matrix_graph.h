#ifndef _MATRIX_GRAPH_H_
#define _MATRIX_GRAPH_H_

#include <iostream>
#include <vector>

#include "graph.h"

class MatrixGraph : public Graph {
private:
    std::vector<std::vector<int>> graph;
    int vertexNumber;

public:
    MatrixGraph(int n);
    void AddEdge(int from, int to) override;
    bool HasEdge(int from, int to) override;
    int CountVertex() const override;
    void PrintGraph() const override;
};

#endif /* _MATRIX_GRAPH_H_ */
