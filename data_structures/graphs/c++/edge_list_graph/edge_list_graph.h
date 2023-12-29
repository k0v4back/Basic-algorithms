#ifndef _MATRIX_GRAPH_H_
#define _MATRIX_GRAPH_H_

#include <iostream>
#include <unordered_map>

#include "graph.h"

class EdgeListGraph : public Graph {
private:
    std::unordered_map<int, int> graph;
    int vertexNumber;

public:
    EdgeListGraph(int n);
    void AddEdge(int from, int to) override;
    bool HasEdge(int from, int to) override;
    int CountVertex() const override;
    void PrintGraph() const override;
};

#endif /* _MATRIX_GRAPH_H_ */
