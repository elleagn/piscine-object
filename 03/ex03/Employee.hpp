#pragma once

class Employee {

    protected:

        int dayOfMonth;
        int hourlyValue;
    
    public:
        virtual void executeWorkday() = 0;
        virtual void calculatePayroll() const = 0;    

};