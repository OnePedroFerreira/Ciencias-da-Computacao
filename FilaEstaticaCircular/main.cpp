#include <iostream>
#include "filaEstaticaCircular.h"
#include <cstdlib>  // Para rand() e srand()
#include <ctime>    // Para time()

using namespace std; //termiando

/*
na lista circular, os ultimos espaços, sao usados, e o itens que forma
removidos não são tirados e sim substituidos por novoa quando necessario
*/


/*
Desenvolva um programa para simular uma bilheteria de um cinema durante os 45 minutos que antecedem a sessão.
A cada minuto chegam de 2 a 4 pessoas, que são dispostas em uma fila.
Antes do início da abertura da bilheteria já se encontram 12 pessoas na fila.
Existe apenas um atendente, que demora 30 segundos para vender um bilhete.
Indique o número de pessoas que vieram assistir determinado filme e quantas pessoas estavam na fila da bilheteria quando a sessão teve início.

Resumo, uma fila,
-inicie com 12 valores,
-A cada loop, 2 a 4 valores são adcionados, e pelo menos 2 saem,
-O loop dura 45 ciclos
Mostre o total de pessoas que apareceram, e quantas ainda estao na fila

*/


int main(){
    /*
    FilaEstaticaCircular<int, 50> FilaCinema;
    criaFila(FilaCinema);
    srand(time(NULL));
    int PessoasNoCinema;


    cout << "-----O cinema abre ------" << endl;
    for(int i = 1; i < 13; i++ ){
        insereFila(FilaCinema, 1);
        PessoasNoCinema++;
    }
    cout << "12 lugares estao reservados"<<endl;
    //mostraFila(FilaCinema);

    try{
        for (int loop =0; loop < 45; loop++){
            int novo = rand()%3+1;
            for ( novo ; novo > 0; novo--){
                insereFila(FilaCinema,1);
            }
            retiraFila(FilaCinema); PessoasNoCinema++;
            retiraFila(FilaCinema); PessoasNoCinema++;
        }
    }catch (const char* msg){
        cout<<endl;
        cout << "Teve um problema de: " << msg <<endl;

    }

    cout << "Vieram ao cinema: " << PessoasNoCinema;
    cout << " e ainda estao na fila: " << numeroElementos(FilaCinema) <<endl;


    */
        //taxi
     FilaEstaticaCircular <int, 100> filaDePassageiros, filaDeTaxis;
     int i, j, tempoChegada, tempoEspera, taxisUsados, passageirosAtendidos;

     srand(time(NULL));

     criaFila(filaDePassageiros);
     criaFila(filaDeTaxis);

     tempoEspera = 0;
     taxisUsados = 0;
     passageirosAtendidos = 0;

     for (i = 1; i <= 10 * 60; i++)
     {
        if (i % 3 == 0)
            for (j = 1; j <= rand()%3; j++)
                insereFila(filaDePassageiros, i);

         if (i % 5 == 0)
            for (j = 1; j <= rand()%4; j++)
                insereFila (filaDeTaxis, 1);

         if ( (estaVazia (filaDePassageiros) == false) && (estaVazia (filaDeTaxis) == false) ){
             retiraFila (filaDeTaxis);
             taxisUsados++;
             tempoChegada = recuperaPrimeiroE (filaDePassageiros);//?
             retiraFila (filaDePassageiros);
             passageirosAtendidos++;
             tempoEspera += i - tempoChegada;
         }
     }

     cout << "tempo medio de espera = " << ((float) tempoEspera / (float) passageirosAtendidos) << endl; //float porque vai sre um numero quebrado
     cout << "taxis usados = " << taxisUsados;



    return 0;
}
