#ifndef LISTAGENERICA_H_INCLUDED
#define LISTAGENERICA_H_INCLUDED
#include <iostream>

using namespace std;

//construa a lista generica
 template <typename T, int MAX> // tipo de dado e tamanho da lista
 struct ListaGenerica{
    int cardinalidade; //e necessario
    T elementos[MAX];
 };

 template <typename T, int MAX>
 void cria(ListaGenerica <T, MAX> &l){
    l.cardinalidade = 0;
 }

//verifica se esta vazia
template<typename T, int MAX>
bool estaVazia(ListaGenerica<T, MAX> &l){
    l.cardinalidade = 0;
}

//numero de elementps da lista
template<typename T, int MAX>
int numeroElementos(ListaGenerica<T,MAX> l){
    return l.cardinalidade;
}

//verifica se determinado elemento esta na lista
template <typename T, int MAX>
bool existeElemento (ListaGenerica<T,MAX> l, T elemento){
    for (int i = 0; i < l.cardinalidade; i++)
        if(l.elemento[i] == elemento){return true;}
    return false;
}

//verifica se a posicapo esta valida
template <typename T, int MAX>
int existePosicao (ListaGenerica<T,MAX> l, int posicao){
    return (posicao >= 1) && (posicao <= l.cardinalidade);

}

//recupera um elemento da lista
template <typename T, int MAX>
int recuperaElemento (ListaGenerica<T,MAX> l, int posicao){
    if(posicao <1|| posicao> l.cardinalidade) {
        throw "posicao invalida";
    }
    return l.elementos[posicao-1];
}

//recupera a posicao de um elemento da lista
template <typename T, int MAX>
int recuperaPosicao (ListaGenerica<T,MAX> l, int elemento){
    if (!existeElemento(l, elemento)){
    throw "Não esta na lista"; // salva
    }
    for (int i = 0; i <= l.cardinalidade; i++)
        if(l.elemento[i] = elemento){ return i+1; }
}

//insere um elemento
template <typename T, int MAX>
void insereNaLista (ListaGenerica<T,MAX> &l, T elemento, int posicao){
   //faz isso por a lista tem um tamanho definido
   if (l.cardinalidade == MAX){
        throw "Overflow"; // passou o limite
   }
   if (posicao <1||posicao> l.cardinalidade +1){
        throw "posicao invalida";
   }

    for (int i = l.cardinalidade; i >= posicao; i--) // loop, move todos para frente
        l.elementos[i] = l.elementos[i-1];
    l.elementos[posicao - 1] = elemento; // ao fim do loop, adciona o valor no espaço adequado
    l.cardinalidade ++;
}

//retira um elemento
template <typename T, int MAX>
void retiraDaLista (ListaGenerica<T,MAX> &l, int posicao){

    if(l.cardinalidade == 0){
        throw "Underflow"; //nao da pra remover mais
    }
    if(posicao <1||posicao> l.cardinalidade){
        throw "Posicao invalida"; //fora da lista
    }
    for (int i = posicao; i < l.cardinalidade; i++)
        l.elementos[i - 1] = l.elementos[i]; // manda os elemntos para a esquerda, apagando o que foi chamado
    l.cardinalidade--;


}

//exiba os elementos da lista
template <typename T, int MAX>
void mostra (ListaGenerica<T,MAX> l){ // corrigir
    for (int i =0; i < l.cardinalidade; i++){ //cardinalidade = valor de elemntos, adciona +1 ao i ate chegar no valor maximo/cardianlidade
        cout << l.elementos[i] << " " ;
    } cout << endl;
}

// Preenche a lista com entrada do usuário
template <typename T, int MAX>
void Usuario(ListaGenerica<T, MAX>& l) {
    T valor;
    while (l.cardinalidade < MAX) {
        cout << "Digite o " << l.cardinalidade + 1 << "° valor: ";
        cin >> valor;
        insereNaLista(l, valor, l.cardinalidade + 1);
        system("CLS");
    }
}


// Ordenação usando Bubble Sort
template <typename T, int MAX>
bubbleSort(ListaGenerica<T, MAX>& l) { //ordenacao da lista,

    for (int i = 0; i < l.cardinalidade - 1; i++) { // percorre a lista
        for (int j = 0; j < l.cardinalidade - i - 1; j++) {// começa a rodar a troca
            if (l.elementos[j] > l.elementos[j + 1]) { //compara os valores
                T temp = l.elementos[j]; // guarda o valor B em C
                l.elementos[j] = l.elementos[j + 1]; //valor A vai para B
                l.elementos[j + 1] = temp; // Valor C vai para A
            }
        }
    }
}

template <typename T, int MAX>
void comparandoElementos (ListaGenerica<T, MAX> l, T &menor, T &maior){ //devolve o maior e o menor elemento da lista
    if (l.cardinalidade == 0) { // verifica se tem itens na lista
        throw "A lista está vazia!";}

    maior = l.elementos[0]; // guarda o maior valor
    menor = l.elementos[0]; // guarda o menor valor
    int i;

    //longo demais, o que eu fiz aqui?
    /*

    for (i= 0; i < l.cardinalidade - 1; i+=2){ //começa o loop, baseado no tamainho da cardinalidae
        if (l.elementos[i] > l.elementos[i+1]) //compara os dois primeiros valores. o primeiro se for maior
            if (l.elementos[i] > maior){maior = l.elementos[i+1];} // compara com o valor ja guardado
            if (l.elementos[i+1] < menor){menor = l.elementos[i+1];}
        else
            if (l.elementos[i]< menor){menor = l.elementos[i];}
            if (l.elementos[i+1] > maior){maior = l.elementos[i+1];}
    }

    if (l.cardinalidade % 2 != 0)  // depois do loop, verifica se a lista e impar. Compara o ultimo valor
        if (l.elementos[i] > maior) maior = l.elementos[i];
        if (l.elementos[i] < menor) menor = l.elementos[i];

    cout << "O MAIOR valor e: "<< maior <<" O MENOR valor e: " << menor <<endl; // mostra o resultado
    */
    for (int i=1; i< l.cardinalidade; i++){
        if(l.cardinalidade[i] < menor)
            menor = l.elementos[i];
        else if (l.elementos > maior)
            maior = l.elemento[i];
    }

}

template <typename T, int MAX>
void removedorDeCopias (ListaGenerica<T, MAX> &l){
    if (l.cardinalidade == 0)  // verifica se tem itens na lista
        throw "A lista está vazia!";
    //mostra(l);

    for (int i = 0; i < l.cardinalidade; i++) { //loop da cardinalidade cardinalidade, 1 a 1
        int j = i + 1;
        while (j < l.cardinalidade) { // loop de remoção
            if (l.elementos[i] == l.elementos[j]) { // compara o elmento 1 ao seguinte ate remover ou chegar no fim da lista
                retiraDaLista(l, j+1);
                mostra(l);
                 // retira e na posicao fisica, +1 para compensar
                //mostra(l);
            } else {
                j++; // Só avança se não houve remoção
            }
        }
    }
}


#endif // LISTAGENERICA_H_INCLUDED
