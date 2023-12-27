#include <iostream>
#include <list>
#include <algorithm>

#include "list_graph.h"

ListGraph::ListGraph(int n) : vertexNumber(n), graph(new std::list<int>[n]) {}

ListGraph::~ListGraph() {
    delete graph;
}

void ListGraph::AddEdge(int from, int to) {
    if (from < 0 || from >= vertexNumber || to < 0 || to >= vertexNumber)
        return;
    
    std::list<int>::iterator it = graph->begin();
    std::advance(it, from);
    graph->insert(it, to);
}

bool ListGraph::HasEdge(int from, int to) {
    if (from < 0 || from >= vertexNumber || to < 0 || to >= vertexNumber)
        return false;
    
    std::list<int>::iterator it = graph->begin();
    
    it = std::find_if(graph->begin(), graph->end(), from);
    if (graph->end() == it)
        return false;
    
    it = std::find_if(graph->begin(), graph->end(), to);
    if (graph->end() == it)
        return false;
    
    return true;
}

int ListGraph::CountVertex() const {
    return vertexNumber;
}