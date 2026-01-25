#pragma once

class Worker;

class ATool {

    protected:
        int numberOfUses;

    public:
        ATool();
        ATool(const ATool& src);
        ATool& operator=(const ATool& src);
        virtual ~ATool();

        virtual void use() = 0;
};
