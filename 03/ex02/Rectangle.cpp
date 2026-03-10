#include "Rectangle.hpp"

Rectangle::Rectangle() {}

Rectangle::Rectangle(float height, float width): height(height), width(width) {};

Rectangle::Rectangle(const Rectangle& copy): height(copy.height), width(copy.width) {};

Rectangle::~Rectangle() {};

Rectangle& Rectangle::operator=(const Rectangle& assign) {
    height = assign.height;
    width = assign.width;
    return (*this);
}

float Rectangle::getPerimeter() const {
    return (2 * (width + height));
}

float Rectangle::getArea() const {
    return (width * height);
}