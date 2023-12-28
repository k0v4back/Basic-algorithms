#include <iostream>

#include "list_graph.h"

int main(void) {
    ListGraph* lg = new ListGraph(5);

    lg->AddEdge(0, 1);
    lg->AddEdge(0, 2);
    lg->AddEdge(0, 3);
    lg->AddEdge(1, 2);
    lg->AddEdge(1, 3);
    lg->PrintGraph();

    lg->dfs(0);

    return 0;
}