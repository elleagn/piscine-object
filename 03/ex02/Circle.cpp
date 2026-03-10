#include "Circle.hpp"
#include <cmath>

Circle::Circle() {}

Circle::Circle(float radius): radius(radius) {};

Circle::Circle(const Circle& copy): radius(copy.radius) {};

Circle::~Circle() {};

Circle& Circle::operator=(const Circle& assign) {
    radius = assign.radius;
    return (*this);
}

float Circle::getPerimeter() const {
    return (2 * M_PI * radius);
}

float Circle::getArea() const {
    return (M_PI * radius * radius);
}