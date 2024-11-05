#ifndef ONIBUS_H
#define ONIBUS_H

#include <iostream>

using namespace std;

struct Onibus
{
   string placa;
   int capacidade_maxima;
   int lotacao_atual;
   
    Onibus(string,int);
    bool subir_passageiros(int);
    bool descer_passageiros(int);
    bool transfere_passageiros(Onibus*,int);
    void imprime_estado();
};

#endif