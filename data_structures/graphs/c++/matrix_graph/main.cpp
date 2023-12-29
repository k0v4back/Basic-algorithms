#include <iostream>

#include "matrix_graph.h"

int main(void) {
    MatrixGraph* mg = new MatrixGraph(5); 

    mg->AddEdge(1, 2);
    mg->AddEdge(1, 3);
    mg->AddEdge(1, 4);
    mg->AddEdge(2, 3);
    mg->AddEdge(2, 4);
    mg->PrintGraph();

    return 0;
}
