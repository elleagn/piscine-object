#pragma once

#include <string>
#include <vector>

class ATool;
class Workshop;

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
        std::vector<Workshop *> shops;
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

        const std::string& getName() const;
        void registerToWorkshops(std::vector<Workshop *> shops);
        void registerToWorkshops(Workshop* wshops);
        void leaveWorkshop(Workshop *shop);
        void work() const;
};
