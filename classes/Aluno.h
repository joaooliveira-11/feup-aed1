///@file Aluno.h

#ifndef AED_1_ALUNO_H
#define AED_1_ALUNO_H

#include <string>
#include <vector>
#include <set>
#include "Horario.h"
using namespace std;

///@brief Class for students.
class Aluno {

    private:
        ///@brief The student's code and the number of UC's he has.
        int StudentCode, NUCS;

        ///@brief The student's name.
        string StudentName;

        ///@brief The student's schedule.
        Horario horarioAluno;
    public:
        ///@brief Empty student constructor.
        Aluno();

        ///@brief Constructor of new student given it's student code, name, schedule and number of UC's.
        Aluno(int StudentCode, string StudentName, Horario horario, int NUCS);

        ///@returns A student's code.
        int getStudentCode() const;

        ///@returns A student's name.
        string getStudentName();

        ///@returns A student's schedule.
        Horario& getHorario();

        ///@returns The number of UC's a student's enrolled in.
        int getNUCS() const;

        ///@returns Our student's code as the parameter it receives.
        void setStudentCode(int studentcode);

        ///@returns Our student's code as the parameter it receives.
        void setStudentName(string studentname);

        ///@returns Our student's schedule as the parameter it receives.
        void setHorario(Horario& horario);

        ///@returns Our student's number of UC's as the parameter it receives.
        void setNUCS(int NUCS);

        ///@brief Operator< overload.
        ///@returns True if our student's code is lower than the one from the student received as parameter.
        bool operator<(const Aluno&) const;

        ///@brief Operator> overload.
        ///@returns True if our student's code is higher than the one from the student received as parameter.
        bool operator>(const Aluno&) const;

        ///@brief Decrease the number of UC's a student is enrolled in if that student leaves an UC.
        void removeUcs();

        void addUcs();
};

#endif