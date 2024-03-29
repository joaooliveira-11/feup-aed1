///@file Turma.h

#ifndef AED_1_TURMA_H
#define AED_1_TURMA_H

#include <string>
#include <vector>
#include <set>
#include "Aula.h"
#include "map"
using namespace std;

///@brief Class for classes.
class Turma {
    private:
        ///@brief The class code and the UC code.
        string Classcode, Uccode;

        ///@brief The number of students in a class.
        int numeroAlunos;
    public:
        ///Empty class constructor.
        Turma();

        ///@brief Constructor of a new class given it's class code, the UC code and the number of students in the class/UC.
        ///@param Uccode
        ///@param Classcode
        ///@param numeroAlunos
        Turma(string Classcode,string Uccode,int numeroAlunos);

        ///@brief Getter for the ClassCode.
        ///@returns Our class's code.
        string get_classcode();

        ///@brief Getter for the class' UcCode.
        ///@returns Our UC's code.
        string get_uccode();

        ///@brief Getter for the number of students in a class/UC.
        ///@returns The amount of students in our class/UC.
        int get_numeroalunos() const;

        ///@brief Increments the number of students in this class/UC.
        void adder();

        ///@brief Checks is a new student can be added to a class.
        ///@param Max_students_by_UC
        ///@see menu.cpp
        ///@note Time complexity: O(1)
        bool can_add(map<string, int> Max_students_by_UC, Turma);

        ///@brief Sets the number of students of a class to 0.
        ///@note Time complexity: O(1)
        void set_numeroalunos_0();
};

#endif
