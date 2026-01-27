

#include "Workshop.hpp"
#include "Worker.hpp"
#include <iostream>

Workshop::Workshop() {
    std::cout   << "Workshop : Created." << std::endl;
}

Workshop::Workshop(const Workshop& src): worker(src.worker) {};
Workshop& Workshop::operator=(const Workshop& src) {
    worker = src.worker;
    return (*this);
}

Workshop::~Workshop() {

    std::vector<Worker *>::iterator it = worker.begin();
    while (it != worker.end()) {
        (*it)->leaveWorkshop(this);
        it++;
    }
    std::cout   << "Workshop : Destroyed." << std::endl;
}

void Workshop::registerWorker(Worker* person) {
    worker.push_back(person);
    std::cout << "Workshop: Worker " << person->getName() << " registered.";
}

void Workshop::releaseWorker(Worker* person) {
    std::vector<Worker *>::iterator it = worker.begin();
    person->leaveWorkshop(this);
    while (it != worker.end()) {
        if (*it == person)
            worker.erase(it);
        it++;
    }
    std::cout << "Workshop: Worker " << person->getName() << " was released." << std::endl;
}

void Workshop::executeWorkDay() const {
    std::vector<Worker *>::const_iterator it = worker.begin();

    std::cout << "Workshop: Execute work day." << std::endl;
    while (it != worker.end()) {
        (*it)->work();
        it++;
    }
}
