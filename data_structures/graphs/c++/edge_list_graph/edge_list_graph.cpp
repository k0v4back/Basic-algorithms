#include <iostream>
#include <algorithm>
#include <list>

#include "edge_list_graph.h"

EdgeListGraph::EdgeListGraph(int n) : vertexNumber(n) {}

void EdgeListGraph::AddEdge(int from, int to) {
    if (from < 0 || from > vertexNumber || to < 0 || to > vertexNumber)
        return;
    
    graph.insert({from, to});
}

bool EdgeListGraph::HasEdge(int from, int to) {
    if (from < 0 || from > vertexNumber || to < 0 || to > vertexNumber)
        return false;

    if (auto it = graph.find(from); it == graph.end())
        return false;
    
    return true;
}

int EdgeListGraph::CountVertex() const {
    return vertexNumber;
}

void EdgeListGraph::PrintGraph() const {
    for (const auto& [from, to] : graph) {
        std::cout << from << ": " << to << "\n";
    }
}
