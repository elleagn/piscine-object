#include "Command.hpp"
#include "iostream"


void enter_prices() {
    Command::prices["pear"] = 2;
    Command::prices["orange"] = 3;
    Command::prices["mango"] = 4;
    Command::prices["raspberry"] = 2;
    Command::prices["apple"] = 1;
}

int main(void) {
    Command cmd("2023-03-02", "Leo");
    
    enter_prices();
    cmd.add_article("apple", 3);
    cmd.add_article("mango", 1);
    cmd.add_article("orange", 5);
    cmd.add_article("raspberry", 3);
    std::cout << "Total price: " << cmd.get_total_price() << std::endl;

}