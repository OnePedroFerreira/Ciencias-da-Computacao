#ifndef LISTAGENERICAESTOQUE_H_INCLUDED
#define LISTAGENERICAESTOQUE_H_INCLUDED
#include <iostream>
using namespace std;

template <typename N, typename M, int MAX>
struct ListaCompras {
    N produtos[MAX];
    M valores[MAX];
    int cardinalidade = 0;
};

template <typename N,  typename M, int MAX>
void cria(ListaCompras< N, M, MAX > &l) {
    l.cardinalidade = 0;
}

template <typename N, typename M, int MAX>
void insereNaLista (ListaCompras<N,M,MAX> &l, N produto, M valor, int posicao){
   //faz isso por a lista tem um tamanho definido
   if (l.cardinalidade == MAX){ throw "Overflow"; }// passou o limite
   if (posicao <1||posicao> l.cardinalidade +1){ throw "posicao invalida"; } // nao e valido

    for (int i = l.cardinalidade; i >= posicao; i--){ // loop, move todos para frente
        l.produtos[i] = l.produtos[i-1];
        l.valores[i] = l.valores[i-1];}
    l.produtos[posicao - 1] = produto; // ao fim do loop, adciona o valor no espaço adequado
    l.valores[posicao - 1] = valor;
    l.cardinalidade ++;
}




#endif // LISTAGENERICAESTOQUE_H_INCLUDED
