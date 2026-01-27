#pragma once

#include <vector>
#include <string>

class Worker;


class Workshop {
    private:
        std::vector<Worker *> worker;
        std::string type;
        Workshop();

    public:
        Workshop(std::string type);
        Workshop(const Workshop& copy);
        Workshop& operator=(const Workshop& assign);
        ~Workshop();


        void registerWorker(Worker *worker);
        void releaseWorker(Worker *worker);
        void executeWorkDay() const;

};
