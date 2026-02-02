#pragma once

class Brake {
    public:
        Brake();
        Brake(const Brake& copy);
        ~Brake();

        Brake& operator=(const Brake& assign);

        void decelerate(int speed);
};
