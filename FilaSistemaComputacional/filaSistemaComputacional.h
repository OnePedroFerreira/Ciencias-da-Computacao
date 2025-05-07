#ifndef FILASISTEMACOMPUTACIONAL_H_INCLUDED
#define FILASISTEMACOMPUTACIONAL_H_INCLUDED

#include <iostream>

using namespace std;

//fila estática e operações e relações para:
//criar uma fila,
 template <typename T, int MAX> // tipo de dado e tamanho da lista
 struct FilaEstaticaCircular{
    int cardinalidade; //e necessario
    int inicio;
    int fim;
    T elementos[MAX];

 };

 template <typename T, int MAX>
 void criaFila(FilaEstaticaCircular <T, MAX> &l){
    l.cardinalidade = 0;
    l.inicio =0;
    l.fim = 0;
 }

//verificar se uma fila está vazia,
template <typename T, int MAX>
bool estaVazia (FilaEstaticaCircular<T, MAX> l){
    l.cardinalidade =0;
}

//verificar se há espaço na fila,
template <typename T, int MAX>
bool temEspaco (FilaEstaticaCircular<T, MAX>l){
    l.cardinalidade != MAX;
}

//recuperar o número de elementos da fila,
template <typename T, int MAX>
int numeroElementos (FilaEstaticaCircular<T, MAX> l){
    return l.cardinalidade;
}

//verificar se um determinado elemento está na fila,
template <typename T,int MAX>
bool existeElemento (FilaEstaticaCircular<T,MAX> l, T elemento){
    int i;
    for (i = l.inicio; i = l.fim; i++)
    if (i = MAX){i =0;}
        if(l.elemento[i] == elemento){return true;}
    return false;
}

//verificar se uma posição qualquer é válida,
template <typename T, int MAX>
int posicaoValida (FilaEstaticaCircular<T,MAX> l, int posicao){
    return (posicao >= 1) && (posicao <= l.cardinalidade);

}

//recuperar um elemento da fila,
template <typename T, int MAX>
T recuperaElemento (FilaEstaticaCircular<T,MAX> l, int posicao){
    if(posicao <1|| posicao> l.cardinalidade) {
        throw "posicao invalida";
    }
    return l.elementos[posicao-1];
}

//recuperar a posição de um elemento da fila,
template <typename T, int MAX>
int recuperaPosicao (FilaEstaticaCircular<T,MAX> l, int elemento){
    if (!existeElemento(l, elemento)){
    throw "Não esta na lista"; // salva
    }
    for (int i = 0; i <= l.cardinalidade; i++)
        if(l.elemento[i] = elemento){ return i+1; }
}

//recuperar o primeiro elemento da fila,
template <typename T, int MAX>
T recuperaPrimeiroE (FilaEstaticaCircular<T,MAX> l){
    return l.elementos[l.inicio];
}

//recuperar o último elemento da fila,
template <typename T, int MAX>
T recuperaUltimoE (FilaEstaticaCircular<T,MAX> l){
    return l.elemento[l.fim];
}

//inserir um elemento,
template <typename T, int MAX>
void insereFila (FilaEstaticaCircular<T,MAX> &l, T elemento){
//verrifica se lista não esta cheia
    if (l.cardinalidade == MAX){
        throw "OVERFLOW";
    }

     l.elementos[l.fim+1] = elemento; //adciona a posicao
     l.fim = (l.fim + 1);
     l.cardinalidade ++; //aumenta cardinalidade

}

//retirar um elemento e
template <typename T, int MAX>
void retiraFila (FilaEstaticaCircular<T,MAX> &l){
    if(l.cardinalidade == 0){
        throw "Underflow"; //nao da pra remover mais
    }
    l.inicio = (l.inicio - 1);    // Move 'inicio' circularmente
    l.cardinalidade--;

}

//exibir os elementos da fila
template <typename T, int MAX>
void mostraFila (FilaEstaticaCircular <T,MAX> l){ // corrigir
    for (int i = 0; i < l.cardinalidade;  i++){ //cardinalidade = valor de elemntos, adciona +1 ao i ate chegar no valor maximo/cardianlidade
        cout << l.elementos[i] << " " ;
    } cout << endl;
}

#endif // FILASISTEMACOMPUTACIONAL_H_INCLUDED
