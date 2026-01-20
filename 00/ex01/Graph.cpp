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
    for (std::vector<Vector2>::iterator it; it != points.end(); it++) {
        if (point < *it) {
            points.insert(it, point);
            break;
        }
    }

    if (point.X > size.X) {
        size.X = point.X;
    }
    if (point.Y > size.Y) {
        size.Y = point.Y;
    }
}

void Graph::plot() {
    std::vector<Vector2>::iterator nextPoint = points.begin();
    for (int y = size.Y; y >= 0; y--) {
        std::cout << y;
        for (int x = 0; x <= size.X; x++) {
            std::cout << " ";
            if ((*nextPoint).Y == y && (*nextPoint).X == x) {
                std::cout << "+";
            } else {
                std::cout << "-";
            }
        }
        std::cout << std::endl;
    }

    for (int x = 0; x <= size.X; x++) {
            std::cout << " " << x;
        }
}
