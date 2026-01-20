#pragma once
#include <vector>

class Graph {
    private:
        class Vector2 {
            private:
                Vector2();

            public:
                float X;
                float Y;

                Vector2(float x, float y);
                Vector2(const Vector2& vect);
                ~Vector2();

                Vector2& operator=(const Vector2& vect);
                bool operator==(const Vector2& vect) const;
                bool operator!=(const Vector2& vect) const;
                bool operator<(const Vector2& point) const;

        };
        Vector2 size;
        std::vector<Vector2> points;

    public:
        Graph();
        Graph(const Graph& graph);
        ~Graph();

        Graph& operator=(const Graph& graph);
        void add(float x, float y);
        void plot();
        void print();
};

