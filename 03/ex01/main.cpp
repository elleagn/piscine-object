#include "Command.hpp"
#include "ThursdayDiscount.hpp"
#include "PackageReductionDiscount.hpp"
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
    ThursdayDiscountCommand t1("2026-03-10", "ThursdaynotThursday");
    PackageReductionDiscountCommand p1("2026-10-03", "PackagenotPackage");
    
    enter_prices();
    cmd.add_article("apple", 3);
    cmd.add_article("mango", 1);
    cmd.add_article("orange", 5);
    cmd.add_article("raspberry", 3);

    t1.add_article("apple", 3);
    t1.add_article("mango", 1);
    t1.add_article("orange", 5);
    t1.add_article("raspberry", 3);

    p1.add_article("apple", 3);
    p1.add_article("mango", 1);
    p1.add_article("orange", 5);
    p1.add_article("raspberry", 3);
    std::cout << cmd << " : " << cmd.get_total_price() << std::endl;
    std::cout << t1 << " : " << t1.get_total_price() << std::endl;
    std::cout << p1 << " : " << p1.get_total_price() << std::endl << std::endl;

    Command cmd2("2023-03-02", "Leo");
    ThursdayDiscountCommand t2("2026-03-12", "Thursday");
    PackageReductionDiscountCommand p2("2026-10-03", "Package");
    
    enter_prices();
    cmd2.add_article("apple", 3);
    cmd2.add_article("mango", 1);
    cmd2.add_article("orange", 5);
    cmd2.add_article("raspberry", 100);

    t2.add_article("apple", 3);
    t2.add_article("mango", 1);
    t2.add_article("orange", 5);
    t2.add_article("raspberry", 100);

    p2.add_article("apple", 3);
    p2.add_article("mango", 1);
    p2.add_article("orange", 5);
    p2.add_article("raspberry", 100);
    std::cout << cmd << " : " << cmd2.get_total_price() << std::endl;
    std::cout << t2 << " : " << t2.get_total_price() << std::endl;
    std::cout << p2 << " : " << p2.get_total_price() << std::endl;

}