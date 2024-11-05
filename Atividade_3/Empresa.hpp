#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
#include "Onibus.hpp"

using namespace std;

struct Empresa{
    int total_onibus;
    Onibus* vetor_onibus[20]; 

    Empresa();
    Onibus* adicionar_onibus(string,int);
    Onibus* busca_onibus(string);
    void imprime_estado();
};


#endif