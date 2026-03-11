#pragma once

class IMobilizable {
    virtual void mobilize(int hours) = 0;
};

class IAbsenceDeclarable {
    virtual void declareAbsence(int hours) = 0;
};

class ISchoolAssignable {
    virtual void assignSchool(int hours) = 0;
};