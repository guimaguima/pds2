#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
#include <vector>


using namespace std;

class Aluno{
    private:
        string nome;
        int matricula;
        vector<int> notas;

    public:

        Aluno(string nome,int matricula);
        ~Aluno();

        void setNotas(int nota);

        vector<int> getNotas();
        int getNotaMaximo();
        int getNotaMinimo();
        float getMedia();
        string getNome();
        int getMatricula();

        bool operator<(Aluno& obj) const;

};

#endif
