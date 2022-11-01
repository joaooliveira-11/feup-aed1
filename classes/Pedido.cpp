#include "string"
#include "Pedido.h"
using namespace std;

Pedido::Pedido(){
    this->type = "";
    this->up = 0;
    this->uc = "";
    this->class_antiga = "";
    this->class_nova = "";
}

Pedido::Pedido(string tipo, int up, string uc, string class_antiga, string class_nova){
    this->type = tipo;
    this->up = up;
    this->uc = uc;
    this->class_antiga = class_antiga;
    this->class_nova = class_nova;
}