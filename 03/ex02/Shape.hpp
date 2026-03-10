#pragma once

class Shape {
    public:
        virtual ~Shape() {};
        virtual float getPerimeter() const = 0;
        virtual float getArea() const = 0;
};