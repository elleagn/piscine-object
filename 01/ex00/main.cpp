#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Workshop.hpp"
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
    std::cout << "PART 3: Inheritance" << std::endl;
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

    std::cout << std::endl;
    std::cout << "PART 4: Association\n\n";
    {
        Workshop shop1;
        Workshop shop2;
        Worker  kevin("Kevin");

        shop1.registerWorker(&kevin);
        shop1.executeWorkDay();
        shop2.registerWorker(&kevin);
        shop2.executeWorkDay();
        shop1.releaseWorker(&kevin);
        shop1.executeWorkDay();
    }
}
