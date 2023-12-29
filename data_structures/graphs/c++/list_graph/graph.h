#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <vector>

class Graph {
public:
    virtual ~Graph() {}
    virtual void AddEdge(int from, int to) = 0;
    virtual bool HasEdge(int from, int to) = 0;
    virtual int CountVertex() const = 0;
    virtual void dfs(int v) = 0;
    virtual std::vector<int> bfs(int start) = 0;
    virtual void PrintGraph() const = 0;
};

#endif /* _GRAPH_H_ */