#pragma once

#include "Shape.hpp"

class Circle: public Shape {

    private:
        float radius;
        Circle();

    public:

        Circle(float radius);
        Circle(const Circle& copy);
        ~Circle();

        Circle& operator=(const Circle& assign);
    
        float getPerimeter() const;
        float getArea() const;

};