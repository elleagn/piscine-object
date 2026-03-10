#pragma once
#include "Shape.hpp"

class Rectangle: public Shape {

    private:
        float height;
        float width;
        Rectangle();

    public:

        Rectangle(float width, float height);
        Rectangle(const Rectangle& copy);
        ~Rectangle();

        Rectangle& operator=(const Rectangle& assign);

        float getPerimeter() const;
        float getArea() const;

};