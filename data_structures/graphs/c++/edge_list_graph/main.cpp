#include <iostream>

#include "edge_list_graph.h"

int main(void) {
    EdgeListGraph* elg = new EdgeListGraph(5); 

    elg->AddEdge(1, 2);
    elg->AddEdge(1, 3);
    elg->AddEdge(1, 4);
    elg->AddEdge(2, 3);
    elg->AddEdge(2, 4);
    elg->PrintGraph();

    return 0;
}
