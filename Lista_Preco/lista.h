#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <iostream>
#include <ctime> //para o valor random
using namespace std;

//cria a lista
struct listaAcoes {
    int elemento[10];
    int cardinalidade;
};

listaAcoes cria(){
    listaAcoes LA;
    LA.cardinalidade = 0;
    return LA;
}

//adcionar valor
void novaAcao (listaAcoes &LA, int elemento, int posicao){
    for (int i = LA.cardinalidade; i >= posicao; i--)
        LA.elemento[i] = LA.elemento[i-1];
    LA.elemento[posicao-1] = elemento;
    LA.cardinalidade ++;
}

int elementoRecupera (listaAcoes LA, int posicao){
    return LA.elemento [posicao - 1]; //parametro da posica, da lista, logica
}

void mostra (listaAcoes LA){ // corrigir
    for (int i =0; i < LA.cardinalidade; i++){
        cout << LA.elemento[i] << " " ;
    }
}

int loop (listaAcoes &LA){
    int minuto= 2;

    novaAcao(LA, 0+rand()%2+5,0);

    while (minuto <= 37){
        int novo = rand()%7-3;
        novaAcao(LA, novo, minuto / 2 );
        mostra(LA); //otimo
        //cout << minuto << "0 " <<"minutos, e valor: "<< elementoRecupera(LA, minuto/2) <<endl;

        cout<<endl;
        minuto +=2;
    }
}


//correção. Exercicio 2
int numeroDeOcorrencias (listaAcoes LA, int elementos){ //verifica qauntos elementos sao iguais ao referido, devolve o resultado
    int cont = 0;
    for (int i=0; i < LA.cardinalidade; i++)
        if(LA.elemento[i] == elementos)
            cont++;
    return cont;
}

#endif // LISTA_H_INCLUDED
