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
    {
        Worker john("John");
        Worker emily("Emily");
        ATool *ham = new Hammer();
        ATool *shov = new Shovel();
        shov->use();
        ham->use();
        john.takeTool(shov);
        john.takeTool(ham);
        john.hasTool(ham);
        emily.takeTool(ham);
        delete ham;
        delete shov;
    }
}
