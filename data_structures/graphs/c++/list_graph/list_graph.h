#ifndef _LIST_GRAPH_H_
#define _LIST_GRAPH_H_

#include <list>

#include "graph.h"

#include <iostream>

class ListGraph : public Graph {
private:
    std::list<int> *graph;
    int vertexNumber;
public:
    ListGraph(int n);
    ~ListGraph();

    void AddEdge(int from, int to) override;
    bool HasEdge(int from, int to) override;
    int CountVertex() const override;
};

#endif  /* _LIST_GRAPH_H_ */