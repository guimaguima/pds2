#include <iostream>

// 0) Crie uma função que receba três variveis inteiras como parâmetro, da seguinte forma:
//    - A primeira deve ser passada por valor
//    - A segunda deve ser passada por referência 
//    - A terceira deve ser passada "por referência" usando apontadores (passagem "por referência" disponível em C)
//    A função deverá somar 1 ao valor de cada uma das 3 variáveis e retornar.

using namespace std;


int somaValores(int valor, int &referencia, int *ponteiro){
    valor++;
    referencia++;
    *ponteiro += 1;
    return valor;
}



int main(){

    // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada
    int passoUm = 0;
    cin >> passoUm;
    
    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int *ponteiroInteiro = nullptr;
    

    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com dados lidos da entrada
    int tamanho = 0;
    cin >> tamanho;
    int vetor[tamanho];
    for (int i = 0; i < tamanho; i++){
        cin >> vetor[i];
    }
    

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &passoUm  << endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    cout << passoUm  << endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &ponteiroInteiro  << endl;
    
    // 7) Imprima o VALOR da variável declarada em (2)
    cout << ponteiroInteiro  << endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << &vetor  << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << &vetor[0]  << endl;

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    cout << vetor[0]  << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    ponteiroInteiro = &passoUm;

    // 12) Imprima o VALOR da variável declarada em (2)
    cout << ponteiroInteiro  << endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ponteiroInteiro  << endl;

    // 14) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *ponteiroInteiro = 5;

    // 15) Imprima o VALOR da variável declarada em (1)
    cout << passoUm  << endl;

    // 16) Atribua o VALOR da variável (3) à variável declarada em (2)
    ponteiroInteiro = vetor;

    // 17) Imprima o VALOR da variável declarada em (2)
    cout << ponteiroInteiro << endl;
    

    // 18) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ponteiroInteiro << endl;

    // 19) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    ponteiroInteiro = &vetor[0];

    // 20) Compare o valor variáveis (2) e (3), imprimindo 'S' se forem iguais e 'N' se forem diferentes
    if(ponteiroInteiro == vetor)
        cout << "S" << endl;

    else
        cout << "N"  << endl;

    // 21) Imprima o VALOR da variável declarada em (2)
    cout << ponteiroInteiro  << endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ponteiroInteiro << endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for (int i = 0; i < tamanho; i++){
        *(ponteiroInteiro + i) *= 10;
    }
    

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    for (int i = 0; i < tamanho; i++){
        cout << vetor[i] << " ";
    }

    cout << endl;
    

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    for (int i = 0; i < tamanho; i++){
        cout << *(vetor + i) << " ";
    }

    cout << endl;
    
    

    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (2)
        // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    for (int i = 0; i < tamanho; i++){
        cout << *(ponteiroInteiro + i) << " ";
    }
    cout << endl;
    

    // 27) Atribua o ENDEREÇO da última posição de (3) à variável declarada em (2)
    ponteiroInteiro = &vetor[tamanho-1];

    // 28) Imprima o VALOR da variável declarada em (2)
    cout << ponteiroInteiro << endl;

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ponteiroInteiro << endl;

    // 30) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int **ponteiroDuplo = &ponteiroInteiro;

    // 31) Imprima o VALOR da variável declarada em (30)
    cout << ponteiroDuplo << endl;

    // 32) Imprima o ENDEREÇO da variável declarada em (30)
    cout << &ponteiroDuplo << endl;

    // 33) Imprima o VALOR guardado no ENDEREÇO apontado por (30)
    cout << *ponteiroDuplo << endl;

    // 34) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (30)
    cout << **ponteiroDuplo << endl;

    // 35) Crie 3 variáveis interiras e leia o valor delas da entrada
    int primeira, segunda, terceira;
    cin >> primeira >> segunda >> terceira; 

    // 36) Chame a função criada em (0) passando as 3 variáveis criadas em (35) como parâmetro.
    int retorno = somaValores(primeira,segunda,&terceira); 
    
    // 37) Imprima o valor das 3 variáveis criadas em (35)
    cout << primeira << " " << segunda << " " << terceira << endl;
    
    return 0;
}