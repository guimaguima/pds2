#include <iostream>
#include <fstream>
#include <set>

#include "Onibus.hpp"
#include "Empresa.hpp"


using namespace std;

int main()
{
    char entrada;
    
    string placa;
    string placa_tranferencia;
    int numerador;

    Empresa empresa;
    Onibus* onibus_temp;
    Onibus* onibus_temp2;

    cin >> entrada;
    while(entrada!='F'){
        cin >> entrada;
        switch (entrada)
        {
        case 'C':
            cin >> placa >> numerador;
            if(empresa.adicionar_onibus(placa,numerador) != nullptr)
                cout << "novo onibus cadastrado" << endl;
            else
                cout << "ERRO : onibus repetido" << endl;
            break;
        
        case 'S':
            cin >> placa >> numerador;
            onibus_temp = empresa.busca_onibus(placa);
            if(onibus_temp==nullptr)
                cout  << "ERRO : onibus inexistente" << endl;
            else if(onibus_temp->subir_passageiros(numerador))
                cout << "passageiros subiram com sucesso" << endl;
            else 
                cout << "ERRO : onibus lotado" << endl;

            break;
        
        case 'D':
            cin >> placa >> numerador;
            onibus_temp = empresa.busca_onibus(placa);
            if(onibus_temp==nullptr)
                cout  << "ERRO : onibus inexistente" << endl;
            else if(onibus_temp->descer_passageiros(numerador))
                cout << "passageiros desceram com sucesso" << endl;
            else 
                cout << "ERRO : faltam passageiros" << endl;
            break;
        
        case 'T':
            cin >> placa >> placa_tranferencia >> numerador;
            onibus_temp = empresa.busca_onibus(placa);
            onibus_temp2 = empresa.busca_onibus(placa_tranferencia);
            if((onibus_temp==nullptr)||(onibus_temp2==nullptr))
                cout  << "ERRO : onibus inexistente" << endl;
            else if(onibus_temp->transfere_passageiros(onibus_temp2,numerador))
                cout << "transferencia de passageiros efetuada" << endl;
            else
                cout << "ERRO : transferencia cancelada" << endl;

            break;
        
        case 'I':
            empresa.imprime_estado();
            break;
        
        default:
            break;
        }
    }
    return 0;
}