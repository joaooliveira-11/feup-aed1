#include "Bst.h"
#include "Aluno.h"
#include <iostream>
#include "Aula.h"
#include "Turma.h"
#include <list>
using namespace std;

Bst::Bst() {
    atual = Aluno();
    Left = Right = NULL;
}

Bst::Bst(Aluno imp){
    atual = imp;
    Left = Right = NULL;
}

Bst* Bst::insert_by_upcode(Bst* base, Aluno imp){
    if (!base) return new Bst(imp);
    if (imp > base->atual) base->Right = insert_by_upcode(base->Right, imp);
    else if (imp < base->atual) base->Left = insert_by_upcode(base->Left, imp);
    return base;
}

void Bst::view(Bst* base){
    if(!base) return;
    view(base->Left);
    cout << base->atual.getStudentCode() << " | ";
    cout << base->atual.getStudentName()  << endl;
    view(base->Right);
}

void Bst::view_by_NUCS(Bst* base, int x){
    if(!base) return;
    view_by_NUCS(base->Left, x);
    if ( base->atual.getNUCS() > x ){
        cout << base->atual.getStudentCode() << " | ";
        cout << base->atual.getStudentName()  << endl;
    }
    view_by_NUCS(base->Right, x);
}
Aluno Bst::find_by_upcode(Bst *base, int upcode){
    if (!base) return Aluno();
    else if (upcode == base->atual.getStudentCode()) return base->atual;
    else if(upcode > base->atual.getStudentCode()) return find_by_upcode(base->Right, upcode);
    return find_by_upcode(base->Left, upcode);
}

void Bst::view_by_turma(Bst* base, string uccode, string classcode ){
    if(!base) return;
    view_by_turma(base->Left, uccode, classcode);
    vector<Aula> aulas = base->atual.getHorario().getAulas();
    for (Aula aula : aulas){
        if (aula.get_UcCode()==uccode and  aula.get_ClassCode() == classcode){
            cout << base->atual.getStudentCode() << " | ";
            cout << base->atual.getStudentName()  << endl;
            break;
        }
    }
    view_by_turma(base->Right, uccode, classcode);
}

void Bst::view_by_uc(Bst* base, string uccode){
    if(!base) return;
    view_by_uc(base->Left, uccode);
    vector<Aula> aulas = base->atual.getHorario().getAulas();
    for (Aula aula : aulas){
        if (aula.get_UcCode() == uccode ){
            cout << base->atual.getStudentCode() << " | ";
            cout << base->atual.getStudentName()  << endl;
            break;
        }
    }
    view_by_uc(base->Right, uccode);
}

void Bst::counter_turmas(Bst* base, list<Turma> &turmas){
    if(!base) return;
    counter_turmas(base->Left, turmas);
    vector<Aula> aulas = base->atual.getHorario().getAulas();
    for (Aula aula : aulas){
        if (aula.get_Type() == "TP" or aula.get_Type() == "PL") {
            for (Turma &turma : turmas) {
                if (turma.get_classcode() == aula.get_ClassCode() and turma.get_uccode() == aula.get_UcCode()) {
                    turma.adder();
                }
            }
        }
    }
    counter_turmas(base->Right, turmas);
}
