#pragma once

#include <vector>

class Worker;


class Workshop {
    private:
        std::vector<Worker *> worker;

    public:
        Workshop();
        Workshop(const Workshop& copy);
        Workshop& operator=(const Workshop& assign);
        ~Workshop();


        void registerWorker(Worker *worker);
        void releaseWorker(Worker *worker);
        void executeWorkDay() const;

};
