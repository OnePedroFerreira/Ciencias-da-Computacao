#include <iostream>
#include "arvoreBusca.h"

using namespace std;

/*
    Elabore um programa para fazer a leitura de um número qualquer de elementos inteiros no
    intervalo de [10, 80] e inserir os elementos pares em uma árvore binária de busca A1 e os
    elementos ímpares em uma árvore binária de busca A2. Na sequência, exibir os elementos
    armazenados nas árvores A1 e A2.
*/

int main()
{
    ArvoreBinariaBusca<double> A1;
    ArvoreBinariaBusca<double> A2;
    cria(A1);
    cria(A2);

        int n;
        cout << "Quantos elementos você deseja inserir? ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            int elemento;
            cout << "Digite um elemento (entre 10 e 80): ";
            cin >> elemento;

            if (elemento < 10 || elemento > 80) {
                cout << "Elemento fora do intervalo permitido. Tente novamente." << endl;
                --i; // decrementa para repetir a entrada do mesmo índice
                continue;
            }

            if (elemento % 2 == 0) {
                insereEmArvore(A1, elemento);
            } else {
                insereEmArvore(A2, elemento);
            }
        }

        cout << "Elementos na árvore A1 (pares): ";
        exibe(A1);

        cout << "Elementos na árvore A2 (ímpares): ";
        exibe(A2);

        destroi(A1);
        destroi(A2);


    return 0;
}
