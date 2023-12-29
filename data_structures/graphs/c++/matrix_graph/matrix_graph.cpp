#include <iostream>

#include "matrix_graph.h"

MatrixGraph::MatrixGraph(int n) : vertexNumber(n) {
    graph.resize(n, std::vector<int>(n, 0));
}

void MatrixGraph::AddEdge(int from, int to) {
    if (from < 0 || from > vertexNumber || to < 0 || to > vertexNumber)
        return;
    
    from--;
    to--;

    graph[from][to] = 1;
    graph[to][from] = 1;
}

bool MatrixGraph::HasEdge(int from, int to) {
    if (from < 0 || from > vertexNumber || to < 0 || to > vertexNumber)
        return false;

    if (graph[from][to] == 0 && graph[from][to] == 0)
        return false;

    return true;
}

int MatrixGraph::CountVertex() const {
    return vertexNumber;
}

void MatrixGraph::PrintGraph() const {
    for (int i = 0; i < vertexNumber; i++) {
        std::cout << "Vertex " << i + 1 <<": ";
        for (int j = 0; j < vertexNumber; j++)
            std::cout << graph[i][j] << " ";
        std::cout << std::endl;
    }
}
