#pragma once
#include <vector>

class Graph {
    private:
        class Vector2 {
            private:
                float X;
                float Y;
                Vector2();

            public:
                Vector2(float x, float y);
                Vector2(const Vector2& vect);
                ~Vector2();

                Vector2& operator=(const Vector2& vect);
                bool operator<(const Vector2& point) const;

                float getX() const;
                float getY() const;

        };
        Vector2 size;
        std::vector<Vector2 *> points;

    public:
        Graph();
        Graph(const Graph& graph);
        ~Graph();

        Graph& operator=(const Graph* graph);
        void add(float x, float y);
        void plot();
};

