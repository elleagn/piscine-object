#pragma once

#include <string>

struct Position
{
    int x;
    int y;

    Position();
    ~Position();
};

struct Statistic {
    int level;
    int exp;
    Statistic();
    ~Statistic();
};

class Worker {

    private:
        Position coordonnee;
        Statistic stat;
        std::string name;
        Worker();

    public:

        Worker(std::string name);
        ~Worker();
        Worker(const Worker& src);
        Worker& operator=(const Worker& src);

    void setCoordonnee(int x, int y);
    void setStat(int level, int exp);
    const Position& getCoordonnee() const;
    const Statistic& getStatistic();
};
