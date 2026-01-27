#pragma once

#include <string>
#include <vector>

class ATool;

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
        std::vector<ATool*> tools;
        class Key {
            public:
                Key(){};
                ~Key(){};
        };
        Worker();

    public:

        Worker(std::string name);
        ~Worker();
        Worker(const Worker& src);
        Worker& operator=(const Worker& src);
        void takeTool(ATool* tool);
        void dropTool(ATool* tool);
        bool hasTool(ATool* tool) const;

        void setCoordonnee(int x, int y);
        void setStat(int level, int exp);
        const Position& getCoordonnee() const;
        const Statistic& getStatistic();
        const std::string& getName() const;
};
