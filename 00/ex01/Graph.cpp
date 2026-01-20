#include "Graph.hpp"
#include <cmath>
#include <iostream>

Graph::Graph(): size(Vector2(0,0)) {}

Graph::Graph(const Graph& graph): size(graph.size), points(graph.points) {}

Graph::~Graph() {};

Graph& Graph::operator=(const Graph& graph) {
    size = graph.size;
    points = graph.points;
    return (*this);
}

void Graph::add(float x, float y) {
    Vector2 point(roundf(x), roundf(y));
    if (x < 0 || y < 0) {
        return ;
    }
    std::vector<Vector2>::iterator it = points.begin();
    while (it != points.end() && *it < point) {
        it++;
    }

    if (it == points.end() || *it != point) {
        points.insert(it, point);

        if (point.X > size.X) {
            size.X = point.X;
        }
        if (point.Y > size.Y) {
            size.Y = point.Y;
        }
    }
}

void Graph::plot() {
    std::vector<Vector2>::iterator nextPoint = points.begin();
    for (int y = size.Y; y >= 0; y--) {
        std::cout << y;
        for (int x = 0; x <= size.X; x++) {
            std::cout << " ";
            if (nextPoint != points.end()
                && (*nextPoint).Y == y && (*nextPoint).X == x) {
                    std::cout << "*";
                    nextPoint++;
            } else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }

    std::cout << " ";
    for (int x = 0; x <= size.X; x++) {
            std::cout << " " << x;
    }
    std::cout << std::endl;
}

void Graph::print() {

    for (std::vector<Vector2>::iterator it = points.begin(); it != points.end();
        it++) {
            std::cout << (*it).X << " " << (*it).Y;
            std::cout << std::endl;
    }
}
