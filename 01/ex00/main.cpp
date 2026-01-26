#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"

#include <iostream>

int main() {
    std::cout << "PART 1: Composition\n\n";
    {
        Worker worker("Bob");
    }

    std::cout << std::endl;
    std::cout << "PART 2: Aggregation\n\n";
    {
        Shovel* shov = new Shovel();
        Worker* alice = new Worker("Alice");
        alice->takeTool(shov);
        delete alice;
        shov->use();
        delete shov;
    }
    std::cout << std::endl;
    std::cout << "Inheritance" << std::endl;
}
