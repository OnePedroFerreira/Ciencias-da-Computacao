#include <iostream>
#include "JogoMSequencia.h"
#include <time.h>
#include <cstdlib>
using namespace std;


int main(){
    MaoCartas<int> Jogador1, Jogador2;
    cria(Jogador1); cria(Jogador2);
    int rodadas, inicio, acao;
    srand(time(NULL));

    try {

    cout << " Inicio do Jogo: Quantas rodadas seram? ";
    while (true) { // tesde de valor valido
        cin >> rodadas; //valor de rodadas

        if (cin.fail()) { // detectou valor invalido
            cin.clear(); //limpa o valor digitado
            cout << "Numeros de rodadas invalido. Digite um novo valor: ";
            cin.ignore(10, '\n'); //limpa linhas digitadas e pula pro proximo
        } else {
            system("cls");
            break;
        }
    }


    primeiraRodada(Jogador1, Jogador2);

    cout<<"\n---------------------------------------------------------\n";
    cout << " Jogador 1: Cartas "<< endl;
    mostra(Jogador1);
    cout<<"\n---------------------------------------------------------\n";
    cout << " Jogador 2: Cartas "<< endl;
    mostra(Jogador2);
    cout<<"\n---------------------------------------------------------\n";

    system("pause"); //pausa pra nao pular o display das listas
    system("cls");

    for (inicio = 0; inicio < rodadas; inicio++){ //loop de rodadas
        acao = 0;
        cout<<"\n";

        cout << "Jogador 1: O que quer fazer? "<<endl;
        mostra(Jogador1); cout<<"\n\n";
        cout << "Comprar(1) - Trocar(2) - Descartar (3): ";
        cin >> acao;
        jogadorAcoes(Jogador1, acao);

        cout<<"\n";system("pause");system("cls");cout<<"\n\n"; //pula linha, espera o comando, limpa a tela e continua, bagunçado, mas eficaz

        cout << "Jogador 2: O que quer fazer? "<<endl;
        mostra(Jogador2); cout<<"\n\n";
        cout << "Comprar(1) - Trocar(2) - Descartar (3)" << endl;
        cin >> acao;

        jogadorAcoes(Jogador2, acao);

        cout<<"\n";system("pause");system("cls");cout<<"\n\n";

    }

    system("cls");

    cout << "Final! Vejamos o vencedor "<<endl;

    if (MaiorSequencia(Jogador1) == MaiorSequencia(Jogador2)){
        cout << "Um empate! Ambos venceram!";
    }else if ( MaiorSequencia(Jogador1) > MaiorSequencia(Jogador2)){
        cout<< "Jogador um venceu com uma sequencia de " << MaiorSequencia(Jogador1) << " cartas." <<endl;
    }else {
        cout<< "Jogador dois venceu com uma sequencia de " << MaiorSequencia(Jogador2) << " cartas." <<endl;
    }

    cout<<"Joagador1: "<<endl;
    mostra(Jogador1);
    cout<<"Joagador1: "<<endl;
    mostra(Jogador2);


    }catch (const char* msg){ cout << "Ouve um erro de: "<< msg << endl; }

    return 0;
}
