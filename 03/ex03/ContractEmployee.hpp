#pragma once

#include "Interfaces.hpp"
#include "Employee.hpp"

class ContractEmployee: public Employee, public IAbsenceDeclarable {

    private: 

        int lastMonthAbsences;
        int currentMonthAbsences;
    
    public:
        void executeWorkday();
        void calculatePayroll() const;
        void declareAbsence(int hours);
};