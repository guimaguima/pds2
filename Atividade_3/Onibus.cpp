#include <iostream>
#include "Onibus.hpp"

Onibus::Onibus(string placa_input, int capacidade_input){
    this->placa = placa_input;
    this->capacidade_maxima = capacidade_input;
    this->lotacao_atual = 0;
}


bool Onibus::subir_passageiros(int passageiros){
    if(this->lotacao_atual + passageiros <= this->capacidade_maxima){
        this->lotacao_atual+=passageiros;
        return true;
    }

    return false;
}


bool Onibus::descer_passageiros(int passageiros){
    if(this->lotacao_atual  -  passageiros >= 0){
        this->lotacao_atual-=passageiros;
        return true;
    }

    return false;
}

bool Onibus::transfere_passageiros(Onibus* outro, int passageiros){
    if(
        (this->lotacao_atual - passageiros >= 0) && 
        (outro->lotacao_atual + passageiros <= outro->capacidade_maxima)
    ){
        this->lotacao_atual-=passageiros;
        outro->lotacao_atual+=passageiros;
        return true;
    }

return false;
}

void Onibus::imprime_estado(){
    cout << this->placa << " (" << this->lotacao_atual << "/" << this->capacidade_maxima << ")" << endl; 
}