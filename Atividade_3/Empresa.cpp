#include <iostream>
#include "Empresa.hpp"
#include "Onibus.hpp"

Empresa::Empresa(){
    this->total_onibus = 0;
    for (auto& onibus : this->vetor_onibus){
        onibus = nullptr;
    }
}

Onibus* Empresa::busca_onibus(string placa_desejada){
    for (auto& onibus : this->vetor_onibus){
        if((onibus != nullptr) && (onibus->placa == placa_desejada))
            return onibus;
    }
    return nullptr;
}


Onibus* Empresa::adicionar_onibus(string placa_input, int passageiros){

    if (this->busca_onibus(placa_input) != nullptr || total_onibus >= 20) {
        return nullptr; 
    }
    

    for (auto& onibus : this->vetor_onibus){
        if (onibus == nullptr) {
            onibus = new Onibus(placa_input, passageiros);
            this->total_onibus++;
            return onibus;
        }
    }
    return nullptr;
}
   

void Empresa::imprime_estado(){
    for (int i = 0; i < this->total_onibus; i++) {
        this->vetor_onibus[i]->imprime_estado();
    }
}
