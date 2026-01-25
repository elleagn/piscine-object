#pragma once

class Worker;

class ATool {

    protected:
        int numberOfUses;
        Worker *user;

    public:
        ATool();
        ATool(const ATool& src);
        ATool& operator=(const ATool& src);
        virtual ~ATool();

        void getAway();
        virtual void use() = 0;
};
