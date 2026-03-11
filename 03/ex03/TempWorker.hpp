#pragma once

#include "Interfaces.hpp"
#include "Employee.hpp"

class TempWorker: public Employee, public IMobilizable {

    private: 

        int lastMonthHours;
        int currentMonthHours;
    
    public:
        void executeWorkday();
        void calculatePayroll() const;
        void mobilize(int hours);
};