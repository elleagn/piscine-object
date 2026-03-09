#pragma once

#include <string>
#include <vector>
#include <map>


class Command {

    protected:
        int id;
        std::string date;
        std::string client;
        std::map<std::string, int> basket;
        static int last_id;
        Command();

    public:
        
        Command(const Command& copy);
        Command(std::string date, std::string client);
        virtual ~Command();

        static std::map<std::string, int> prices;

        Command& operator=(const Command& assign);

        void        add_article(std::string article, int quantity);
        virtual int get_total_price() const;

};
