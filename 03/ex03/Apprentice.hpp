#pragma once

#include "Interfaces.hpp"
#include "Employee.hpp"

class Apprentice: public Employee, public IAbsenceDeclarable, public ISchoolAssignable {

    private: 

        int lastMonthAbsences;
        int currentMonthAbsences;
        int currentMonthSchool;
        int lastMonthSchool;
    
    public:
        void executeWorkday();
        void calculatePayroll() const;
        void declareAbsence(int hours);
        void assignSchool(int hours);
};