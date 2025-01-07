#ifndef VETOR_H
#define VETOR_H

#include <iostream>

using namespace std;

template <typename T>
class Vetor
{
private:
    int _ultima_posicao;
    int _tamanho;
    T *vetor;

public:
    Vetor(int n)
    {
        this->vetor = new T[n];
        this->_tamanho = n;
        this->_ultima_posicao = 0;
    }

    Vetor(const Vetor &vetor_original)
    {
        this->_tamanho = vetor_original._tamanho;

        this->_ultima_posicao = vetor_original._ultima_posicao;

        this->vetor = new T[this->_tamanho];

        for (int i = 0; i < this->_ultima_posicao; i++)
        {
            this->vetor[i] = vetor_original.vetor[i];
        }
    }

    ~Vetor()
    {
        delete[] this->vetor;
    }

    void SetElemento(int posicao, T elemento)
    {
        if (posicao >= 0 && posicao < this->_tamanho)
            this->vetor[posicao] = elemento;
    }

    T GetElemento(int posicao)
    {
        if (posicao >= 0 && posicao < _ultima_posicao)
            return this->vetor[posicao];

        return 0;
    }

    void AdicionaElemento(T elemento)
    {
        if (_ultima_posicao < _tamanho)
            this->vetor[_ultima_posicao++] = elemento;
    }

    void Imprime()
    {

        for (int i = 0; i <= _ultima_posicao; i++)
            cout << this->vetor[i] << " ";

        cout << endl;
    }
};

#endif
