#include <iostream>
#include <string>
#include "listaEncadeada.h"

using namespace std;

/*
construa um jogo de pedra, papel e tesoura.
registre quem ganha, se a empate e o numero de rodadas.

*/


int main()
{
    /*
    int rodadas, lanca;
    float resposta;

    ListaEncadeada <int> ListaA;
    ListaEncadeada <int> ListaB;
    ListaEncadeada <string> ListaVitoria;

    criaEncadeada(ListaA);
    criaEncadeada(ListaB);
    criaEncadeada(ListaVitoria);

    do {
        cout << "Jogo: Pedra, Papel e Tesoura:"<<endl;
        cout << "Quantas rodadas seram?"<<endl;
        cin  >> rodadas;
        system("cls");

        for (int i = 1; i <= rodadas; i++){
            cout << "Rodada " << i << endl;
            cout << "Jogador A, lanca? [Pedra(1)| Papel(2) | Tesoura(3)]  ";
            cin >> lanca;
            cout<<endl;
            insere(ListaA, lanca, i);
            system("cls");
            lanca =0;

            cout << "Jogador B, lanca? [Pedra(1)| Papel(2) | Tesoura(3)]  ";
            cin >> lanca;
            insere(ListaB, lanca, i);
            cout<<endl;
            system("cls");
            lanca =0;

            Jogo(ListaA, ListaB,ListaVitoria, i);
            system("pause");
            system("cls");
            //salva resultado
        }

        cout << "Quer jogar de novo? sim(s)/nao(n): ";
        cin >> resposta;
        system("cls");
    }while (resposta == 'n' || resposta == 'N');


*/

    ListaEncadeada <int> ListaRemoveu;
    cria(ListaRemoveu);

    insere(1, 1);
    insere(2, 1);
    insere(3, 1);
    insere(1, 1);
    insere(4, 1);

    mostra(ListaRemoveu);

    int novo = encadeadaNumeroElementos;
    int i = 0;

    while ( i < novo ){
        if (encadeadaVerificaElemento(ListaRemoveu, 1)){
            retira
        }

        i++;
    }




    return 0;
}
