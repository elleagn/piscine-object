

#include "Workshop.hpp"
#include "Worker.hpp"
#include "Hammer.hpp"
#include "Shovel.hpp"
#include <iostream>

Workshop::Workshop() {
    std::cout   << "Workshop : Created." << std::endl;
}

Workshop::Workshop(std::string type): type(type) {
    std::cout   << "Workshop : Created with type " << type << std::endl;
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

    if ((type == "Hammer" && person->getTool<Hammer *>() != NULL)
            || (type == "Shovel" && person->getTool<Shovel *>() !=  NULL)) {
        worker.push_back(person);
        person->registerToWorkshops(this);
        std::cout << "Workshop: Worker " << person->getName() << " registered." << std::endl;
        return ;
    }
    std::cout << "Workshop: Worker " << person->getName() << " couldn't register (tool type)." << std::endl;

}

void Workshop::releaseWorker(Worker* person) {
    std::vector<Worker *>::iterator it = worker.begin();
    person->leaveWorkshop(this);
    while (it != worker.end()) {
        if (*it == person) {
            worker.erase(it);
            std::cout << "Workshop: Worker " << person->getName() << " was released." << std::endl;
            return ;
        }
        it++;
    }
}

void Workshop::executeWorkDay() const {
    std::vector<Worker *>::const_iterator it = worker.begin();

    std::cout << "Workshop: Execute work day." << std::endl;
    while (it != worker.end()) {
        (*it)->work();
        it++;
    }
}
