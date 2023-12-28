#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <map>

#include "list_graph.h"

ListGraph::ListGraph(int n) : vertexNumber(n), graph(new std::list<int>[n]) {}

ListGraph::~ListGraph() {
    delete graph;
}

void ListGraph::AddEdge(int from, int to) {
    if (from < 0 || from >= vertexNumber || to < 0 || to >= vertexNumber)
        return;
    
    graph[from].push_back(to);
}

bool ListGraph::HasEdge(int from, int to) {
    if (from < 0 || from >= vertexNumber || to < 0 || to >= vertexNumber)
        return false;
    
    std::list<int>::iterator it = graph[from].begin();
    it = std::find(graph[from].begin(), graph[from].end(), to);
    if (graph[from].end() == it)
        return false;
    
    return true;
}

int ListGraph::CountVertex() const {
    return vertexNumber;
}

void ListGraph::dfs(int v) {
    visited[v] = 1;
    std::cout << v << " ";

    std::list<int>::iterator it;
    for (it = graph[v].begin(); it != graph[v].end(); it++) {
        if (!visited[*it])
            dfs(*it);
    }
}

void ListGraph::PrintGraph() const {
    for (int i = 0; i < vertexNumber; i++) {
        std::cout << "Vertex " << i << ":";
        for (auto x : graph[i])
            std::cout << "->" << x;
        std::cout << "\n";
    }
}