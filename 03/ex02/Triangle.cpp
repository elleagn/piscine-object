#include "Triangle.hpp"
#include <cmath>

Triangle::Triangle() {}

Triangle::Triangle(float s1, float s2, float s3): s1(s1), s2(s2), s3(s3) {};

Triangle::Triangle(const Triangle& copy): s1(copy.s1), s2(copy.s2), s3(copy.s3) {};

Triangle::~Triangle() {};

Triangle& Triangle::operator=(const Triangle& assign) {
    s1 = assign.s1;
    s2 = assign.s2;
    s3 = assign.s3;
    return (*this);
}

float Triangle::getPerimeter() const {
    return (s1 + s2 + s3);
}

float Triangle::getArea() const {
    float semiPerimeter = getPerimeter() / 2.0;

    // Heron's formula
    float area =  sqrtf(semiPerimeter * (semiPerimeter - s1) * (semiPerimeter - s2) * (semiPerimeter - s3));

    return (area);
}