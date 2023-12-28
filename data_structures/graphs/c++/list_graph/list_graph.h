#ifndef _LIST_GRAPH_H_
#define _LIST_GRAPH_H_

#include <list>
#include <map>

#include "graph.h"

#include <iostream>

class ListGraph : public Graph {
private:
    std::list<int> *graph;
    std::map<int, bool> visited;
    int vertexNumber;
public:
    ListGraph(int n);
    ~ListGraph();

    void AddEdge(int from, int to) override;
    bool HasEdge(int from, int to) override;
    int CountVertex() const override;
    void dfs(int v) override;
    void PrintGraph() const override;
};

#endif  /* _LIST_GRAPH_H_ */