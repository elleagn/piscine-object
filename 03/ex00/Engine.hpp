#pragma once

class Engine {

    private:
        bool on;

    public:
        Engine();
        Engine(const Engine& copy);
        ~Engine();

        Engine& operator=(const Engine& assign);

        void start();
        void stop();
        void accelerate(int speed);
};
