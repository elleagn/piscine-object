#pragma once

class Employee {

    protected:

        int dayOfMonth;
        int hourlyValue;

    public:

        Employee();
        Employee(int hourlyValue);
        Employee(const Employee& src);
        ~Employee();

        Employee& operator=(const Employee& src);

        virtual void executeWorkday() = 0;
        virtual void calculatePayroll() const = 0;    

};