#include <iostream>
#include "Empresa.hpp"
#include "Onibus.hpp"

Empresa::Empresa(){
    this->total_onibus = 0;
    for (auto onibus : this->vetor_onibus){
        onibus = nullptr;
    }
}

Onibus* Empresa::busca_onibus(string placa_desejada){
    for (auto onibus : this->vetor_onibus){
        if((onibus != nullptr) & (onibus->placa == placa_desejada))
            return onibus;
    }
    return nullptr;
}


Onibus* Empresa::adicionar_onibus(string placa_input, int passageiros){
    for (auto onibus : this->vetor_onibus){
        if((this->busca_onibus(placa_input) == nullptr) & (total_onibus<20)){
            this->vetor_onibus[total_onibus] = new Onibus(placa_input,passageiros);
            total_onibus++;
            return vetor_onibus[total_onibus];
        }
    }
    return nullptr;
}
   

void Empresa::imprime_estado(){
    for (auto onibus : this->vetor_onibus){
        onibus->imprime_estado();
    }
}
