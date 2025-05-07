#include <iostream>
#include "listaGenerica.h"
#include <cstdlib>
#include <ctime>

using namespace std;

//comparacao
//ordenacao
//remover duplos


int main(){
    int A;
    const int tamanho = 10;
    srand(time(0));

    ListaGenerica<int, tamanho> Lista1; //indica valores
    cria(Lista1); // constroi a lista


//adcione 5 valores aleatorio
//ordene esses valores
//mostre

for (int i = 0; i < 10; i++) {
        insereNaLista(Lista1,0+rand() % 10,i+1); // adciona um valor aleatorio de 1 a 10
}

//ordene uma lista (ineficiente)
//bubbleSort(Lista1);
//mostra(Lista1); // depois


//comparar: menor e maior elemnto
//comparandoElementos (Lista1);


//remova todos os elmentos duplicados, deixe so 1 copia
removedorDeCopias(Lista1);

//try and catch - estudar isso e implementar
    return 0;
}
