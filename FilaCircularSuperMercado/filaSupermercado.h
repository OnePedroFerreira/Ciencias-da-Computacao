#ifndef FILASUPERMERCADO_H_INCLUDED
#define FILASUPERMERCADO_H_INCLUDED

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
    l.inicio = 0; // porque o incio nao e zero, e 1
    l.fim = 0;
 }

//verificar se uma fila está vazia,
template <typename T, int MAX>
bool estaVazia (FilaEstaticaCircular<T, MAX> l){
    return l.cardinalidade == 0;
}

//verificar se há espaço na fila,
template <typename T, int MAX>
bool temEspaco (FilaEstaticaCircular<T, MAX>l){
    return l.cardinalidade < MAX; // não poder ter mais itens que o tamanho da fila
}

//recuperar o número de elementos da fila,
template <typename T, int MAX>
int numeroElementos (FilaEstaticaCircular<T, MAX> l){
    return l.cardinalidade;
}

//verificar se um determinado elemento está na fila,
template <typename T,int MAX>
bool existeElemento (FilaEstaticaCircular<T,MAX> l, T elemento){
    int i = 1;
    int posicao = l.inicio;
    while (i<= l.cardinlidade){

        posicao++;
        if (posicao > (MAX - 1))
            posicao = 0;
        if (l.elementos[posicao] == elemento)
            return true;
        i++;
    }
    return false; // se nao achar volta falso
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
    if ((l.inicio + posicao)<= MAX - 1)
        return l.elementos[l.inicio + posicao];
    else
        return l.elementos [posicao - MAX + l.inicio];
}

//recuperar a posição de um elemento da fila,
template <typename T, int MAX>
int recuperaPosicao (FilaEstaticaCircular<T,MAX> l, int elemento){
    if (!existeElemento(l, elemento)){ throw "Não esta na lista"; } // salva

    int i = 1;
    int posicao = l.inicio;

    while (i <= l.cardinalidade){
        posicao++;
        if (posicao > MAX - 1)
            posicao = 0;
        if (l.elementos[posicao] == elemento)
            return i;
        i++;
    }
}

//recuperar o primeiro elemento da fila,
template <typename T, int MAX>
T recuperaPrimeiroE (FilaEstaticaCircular<T,MAX> l){
    if (l.inicio < MAX - 1)
        return l.elementos[l.inicio +1];
    else
        return l.elementos[0];
}

//recuperar o último elemento da fila,
template <typename T, int MAX>
T recuperaUltimoE (FilaEstaticaCircular<T,MAX> l){
    return l.elementos[l.fim];
}

//inserir um elemento,
template <typename T, int MAX>
void insereFila (FilaEstaticaCircular<T,MAX> &l, T elemento){
//verrifica se lista não esta cheia
    if (l.cardinalidade == MAX){
        throw "OVERFLOW";
    }

    l.fim++;
    if(l.fim > MAX-1){l.fim = 0;}
    l.elementos[l.fim] = elemento;
    l.cardinalidade++;
}

//retirar um elemento e
template <typename T, int MAX>
void retiraFila (FilaEstaticaCircular<T,MAX> &l){
    if(l.cardinalidade == 0){
        throw "Underflow"; //nao da pra remover mais
    }
    l.inicio++;
    if(l.inicio > MAX -1)
        l.inicio = 0;
    l.cardinalidade--;
}

//exibir os elementos da fila
template <typename T, int MAX>
void mostraFila (FilaEstaticaCircular <T,MAX> l){ // corrigir

    int i = 1;
    int posicao = l.inicio;

    while (i <= l.cardinalidade){
        posicao++;
        if (posicao > MAX - 1)
            posicao = 0;
        cout << l.elementos[posicao] << " ";
        i++;
    }
    cout << endl;
}



#endif // FILASUPERMERCADO_H_INCLUDED
