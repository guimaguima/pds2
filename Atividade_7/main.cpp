#include <iostream>
#include <list>

class Carteirinha {
private:
    int id;
    static int contador_id;
    static int objetos_count;

public:
    Carteirinha() : id(++contador_id) {
        objetos_count++;
    }

    Carteirinha(int id) {
        if (id < 0) {
            this->id = id;
            objetos_count++;
        } 
    }

    Carteirinha(const Carteirinha& outro) : id(outro.id) {
        objetos_count++;
    }

    int getID() const {
        return this->id;
    }

    static int getObjetos() {
        return objetos_count;
    }

    const Carteirinha* getEndereco() const {
        return this;
    }

    ~Carteirinha() {
        objetos_count--;
    }
};

int Carteirinha::contador_id = 0;
int Carteirinha::objetos_count = 0;

int main() {
    std::list<Carteirinha> alunos;

    char letra;

    std::cin >> letra;
    while (letra != 'E') {
        std::cout << Carteirinha::getObjetos() << std::endl;

        switch (letra) {
                
            case 'A': {

                Carteirinha novo_aluno;
                std::cout << novo_aluno.getID() << " " << novo_aluno.getEndereco() << std::endl;

                alunos.push_back(novo_aluno);


                break;
            }

            case 'C': {
                int id;
                std::cin >> id;


                if (id < 0){
                    Carteirinha novo_aluno(id);

                    alunos.push_front(novo_aluno);

                    std::cout << novo_aluno.getID() << " " << novo_aluno.getEndereco() << std::endl;
                }

                else
                    std::cout << "ERRO" << std::endl;

                break;

            }

            case 'R': {

                if (alunos.empty()) {
                    std::cout << "ERRO" << std::endl;
                }
                
                else {
                    auto& aluno = alunos.front();
                    std::cout << aluno.getID() << " " << aluno.getEndereco() << std::endl;
                    alunos.pop_front();
                }

                break;

            }

            case 'N': {

                std::cout << Carteirinha::getObjetos() << std::endl;
                break;

            }

            case 'P': {

                int index = 0, i = 0;
                std::cin >> index;

                if ((index < 1) || (index > Carteirinha::getObjetos())) {
                    std::cout << "ERRO" << std::endl;
                    break;
                }

                for (auto& aluno : alunos) {
                    if (i+1 == index) {
                        std::cout << aluno.getID() << " " << aluno.getEndereco() << std::endl;
                        break;
                    }
                    i++;
                }

                break;
            }

            case 'L': {

                for (auto& aluno : alunos) {
                    std::cout << aluno.getID() << " " << aluno.getEndereco() << std::endl;
                }

                break;
            }

            default:
                break;

        }

        std::cin >> letra;
    }

    return 0;
}
