#include <iostream>
#include <algorithm>
#include <numeric>
#include "aluno.hpp"

Aluno::Aluno(string nome, int matricula) {

    this->nome = nome;
    this->matricula = matricula;

}

Aluno::~Aluno() {}

void Aluno::setNotas(int nota) {
    this->notas.push_back(nota);
}

vector<int> Aluno::getNotas() {
    return this->notas;
}

int Aluno::getNotaMaximo() {

    if (this->notas.empty()) 
        return 0;

    return *max_element(this->notas.begin(), this->notas.end());

}

int Aluno::getNotaMinimo() {
    if (this->notas.empty())
        return 0;

    return *min_element(this->notas.begin(), this->notas.end());
}

float Aluno::getMedia() {
    if (this->notas.empty())
        return 0;

    return accumulate(this->notas.begin(),this->notas.end(),0.0) / this->notas.size();
}

string Aluno::getNome() {
    return this->nome;
}

int Aluno::getMatricula() {
    return this->matricula;
}


bool Aluno::operator<(Aluno& obj) const{
    return this->nome < obj.nome;
}