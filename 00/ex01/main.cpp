#include "Graph.hpp"

int main(void) {
    Graph graph;

    graph.add(0,0);
    graph.add(2,2);
    graph.add(4,2);
    graph.add(2,4);
    graph.plot();
}
