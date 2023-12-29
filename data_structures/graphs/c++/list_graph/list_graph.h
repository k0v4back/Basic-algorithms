#ifndef _LIST_GRAPH_H_
#define _LIST_GRAPH_H_

#include <iostream>

#include <list>
#include <map>
#include <vector>

#include "graph.h"

#define INF 1000000000UL

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
    std::vector<int> bfs(int start) override;
    void PrintGraph() const override;
};

#endif  /* _LIST_GRAPH_H_ */