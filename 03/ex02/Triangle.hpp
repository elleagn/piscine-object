#pragma once
#include "Shape.hpp"

class Triangle: public Shape {

    private:
        float s1;
        float s2;
        float s3;
        Triangle();

    public:

        Triangle(float s1, float s2, float s3);
        Triangle(const Triangle& copy);
        ~Triangle();

        Triangle& operator=(const Triangle& assign);

        float getPerimeter() const;
        float getArea() const;

};