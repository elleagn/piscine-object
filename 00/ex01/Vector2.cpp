#include "Graph.hpp"

Graph::Vector2::Vector2() {}

Graph::Vector2::Vector2(float x, float y): X(x), Y(y) {}

Graph::Vector2::Vector2(const Vector2& vect): X(vect.X), Y(vect.Y) {}

Graph::Vector2::~Vector2() {};

Graph::Vector2& Graph::Vector2::operator=(const Vector2& vect) {
    X = vect.X;
    Y = vect.Y;
    return (*this);
}

// < means plotted before, so y descending and x ascending
bool Graph::Vector2::operator<(const Vector2& point) const {

    // Different lines
    if (Y > point.Y)
        return (true);
    if (Y < point.Y)
        return (false);

    // Same line
    if (X < point.X)
        return (true);
    return (false);

}

float Graph::Vector2::getX() const {
    return (X);
}

float Graph::Vector2::getY() const {
    return (Y);
}


