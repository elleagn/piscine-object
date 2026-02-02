#pragma once

class Engine {

    public:
        Engine();
        Engine(const Engine& copy);
        ~Engine();

        Engine& operator=(const Engine& assign);

        void start();
        void stop();
        void accelerate(int speed);
};
