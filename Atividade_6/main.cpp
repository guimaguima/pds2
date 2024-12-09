#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "aluno.hpp"

int main() {
    string nome;
    vector<Aluno> Alunos;

    cin >> nome;
    while (nome != "END") {
        int matricula, nota;
        cin >> matricula;

        Aluno novo_aluno(nome, matricula);

        cin >> nota;
        while (nota != -1) {
            novo_aluno.setNotas(nota);
            cin >> nota;
        }

        Alunos.push_back(novo_aluno);
        cin >> nome;
    }


    sort(Alunos.begin(),Alunos.end());

    for (auto &aluno : Alunos) {
        cout << aluno.getMatricula() << " " << aluno.getNome();

        for (auto &nota : aluno.getNotas()) {
            cout << " " << nota;
        }

        cout << endl;

        cout << fixed << setprecision(2);

        cout << aluno.getMedia() << " " << aluno.getNotaMaximo() << " " << aluno.getNotaMinimo() << endl;
    }

    return 0;
}
