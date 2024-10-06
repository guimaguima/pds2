#include <iostream>
#include <fstream>
#include <set>

using namespace std;


int* igualdade(string palavraCorreta, string chute) {
    int len = chute.length();
    int* posicoesCorretas = new int[len];

    for (int i = 0; i < len; i++)
        posicoesCorretas[i] = -1;

    for (int i = 0; i < len; i++) {
        size_t posicao = palavraCorreta.find(chute[i]);

        if (posicao != string::npos) 
            posicoesCorretas[i] = posicao;
    }

    return posicoesCorretas;
}

string mascaraAtual(string chute,int *posicoesCorretas){
    int len = chute.length();
    string mascara;
    for (int i = 0; i < len; i++){

        if(i==posicoesCorretas[i])
            mascara += chute[i];
        else if(posicoesCorretas[i]<0)
            mascara += '*';
        else
            mascara += tolower(chute[i]);
    }
    
    return mascara;
}

string caracteresErrados(string mascara,string chute){
    int len = chute.length();
    string errados;
    for (int i = 0; i < len; i++){
        if(mascara[i]=='*'){
            size_t posicao = errados.find(chute[i]);

            if(posicao == string::npos)
                errados += chute[i];
        }
    }
    

    return errados;
}



int main()
{

    int palavra;

    ifstream in ("palavras.txt",fstream::in);

    cin >> palavra;


    if(!in.is_open()){
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    string linha;
    int i=0;

    while (getline(in, linha)) {
        if(i==palavra)
            break;
        i++;
    }

    string chute;
    string errado = "(";
    for (int i = 0; i < 5; i++){
        cin >> chute;

        string mascara = mascaraAtual(chute,igualdade(linha,chute));

        if(linha == mascara){
            cout << mascara << " " << errado << ")" << endl; 
            cout << "GANHOU!" << endl;
            return 2;
        }

        else{
            string errado_temp = caracteresErrados(mascara,chute);

            int len = errado_temp.length();

            for (int i = 0; i < len; i++){
                size_t posicao = errado.find(errado_temp[i]);

                if(posicao == string::npos)
                    errado += errado_temp[i];
            }


            cout << mascara << " " << errado << ")" << endl; 
        }
  
    }
    


    cout << "PERDEU! " << linha << "!" << endl;

    return 0;
}