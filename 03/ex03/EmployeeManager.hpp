#pragma once
#include <vector>

class Employee;

class EmployeeManager {

    private:
        std::vector<Employee *> workers;

    public:

        EmployeeManager();
        EmployeeManager(const EmployeeManager& src);
        ~EmployeeManager();

        EmployeeManager& operator=(const EmployeeManager& src);

        void addEmployee(Employee *worker);
        void removeEmployee(Employee *worker);
        void executeWorkday();
        void calculatePayroll();

};