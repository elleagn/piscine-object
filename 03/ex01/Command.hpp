#pragma once

#include <string>
#include <vector>
#include <map>


class Command {

    protected:
        int id;
        std::string date;
        std::string client;
        std::vector<std::pair<std::string, int>> articles;
        static std::map<std::string, int> prices;

    public:
        

};
