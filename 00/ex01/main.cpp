#include "Graph.hpp"
#include <iostream>

void wings() {
    Graph graph;
    graph.add(0, 3);
    graph.add(0, 2);
    graph.add(0, 1);

    graph.add(1, 3);
    graph.add(1, 0);

    graph.add(3, 2);

    graph.add(4, 1);
    graph.add(4, 0);

    graph.add(10, 3);
    graph.add(10, 2);
    graph.add(10, 1);

    graph.add(9, 3);
    graph.add(9, 0);

    graph.add(7, 2);

    graph.add(6, 1);
    graph.add(6, 0);

    graph.plot();
}

int main(void) {
    Graph graph;

    std::cout << std::endl << "Subject: " << std::endl;
    graph.add(0,0);
    graph.add(0,0);
    graph.add(2,2);
    graph.add(4,2);
    graph.add(2,4);
    graph.plot();

    std::cout << std::endl << "Wings: " << std::endl;
    wings();
}
