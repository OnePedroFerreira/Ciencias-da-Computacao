#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

//criar uma lista,
template <typename T>
struct Nodo {//constroi o nodo que vai guardar as informações
    T elemento; //valor guardado
    Nodo<T>* proximo; // valor do proximo endereço

};

template <typename T>
struct ListaEncadeada{ //constroi o inicio da lista. Tamnho da lista e o nodo inicial
    int cardinalidade; // marca o tamanho fisico da lista
    Nodo<T>* inicio; // marca o inicio da lista de nodos

};

template <typename T>
void criaEncadeada (ListaEncadeada<T> &l){ //cria a lista
    l.cardinalidade = 0; // inicia em zero, ja que não tem nada
    l.inicio = NULL; // inicia o primeiro nodo em Null ja que ele não leva a nada
}

//destruir uma lista,
template <typename T>
void destroiEncadeada (ListaEncadeada<T> &l){ // destroi tudo na lista e zera a cardinalidade

    Nodo<T> *p; // instanica o nodo
    while (l.inicio != NULL){ //loop percorre toda a lista, enquanto ela nao for vazia
        p = l.inicio; // salva o nodo inicial em p
        l.inicio = l.inicio->proximo; // muda o nodo do inicio para o nodo seguinte
        delete p; // deleta o nodo salvo em p
    }
    l.cardinalidade = 0; // zera a lista, agora que todos os valores foram removidos
}

//verificar se uma lista está vazia,
template <typename T>
bool encadeadaVazia (ListaEncadeada <T> l){
    l.cardinalidade == 0;
}

//recuperar o número de elementos da lista,
template <typename T>
int encadeadaNumeroElementos (ListaEncadeada <T> &l){
    return l.cardinalidade;

}

//verificar se um determinado elemento existe na lista,
template <typename T> //terminar
bool encadeadaVerificaElemento (ListaEncadeada<T> &l, T elemento){
   //if (l.cardinalidade == NULL){ throw "A lista esta vazia";}

   Nodo<T> *p = l.inicio; //instancia o primeiro nodo
    for (int i = 0; i < l.cardinalidade; i++){ //viaja toda a lista
        if(p->elemento == elemento){
            return true;
        }
        p = p->proximo; // instancia o nodo seguinte(proximo)
    }return false;
}

//verificar se uma posição qualquer é válida,
template <typename T>
bool encadeadaExistePosicao (ListaEncadeada<T> l, int posicao){
    return ((posicao >=1) && (posicao <= l.cardinalidade));

}

//recuperar um elemento da lista,
template <typename T>
T encadeadaUmELemento (ListaEncadeada<T> l, int posicao){
    if (posicao <1 || posicao> l.cardinalidade){
        throw "POSICAO INVALIDA";
    }

    int contador = 1; //inicia a posicao
    Nodo<T>* p = l.inicio; // . e estatico, estrutura

    while (contador < posicao){
        contador++;
        p = p->proximo;
    }
    return p->elemento; // -> referencia ao endereco, apontando

}

//recuperar a posição de um elemento da lista,
template <typename T>
int encadeadaPosicao (ListaEncadeada<T> l, T elemento){ //arrrumar
    if (!encadeadaUmELemento(l,elemento)){
        throw "Elemento nao esta na lista";
    }

    int contador = 1; //comeca no inicio
    Nodo<T>* p =l.cardinalidade;
    while (p->elemento != elemento){
        contador++;
        p = p->elemento;
    }
    return contador;

}

//inserir um elemento na lista,

template<typename T>
void insere (ListaEncadeada <T> &l, T elemento, int posicao){

    Nodo<T>* q = new Nodo<T>; //cria um struct(nodo), novo (alocacao de memoria), nao esta me nenhum lugar ainda
    q->elemento = elemento; //adciona o dado
    q-> proximo = NULL; // deixa vago para o endereço seguinte

    if(l.inicio == NULL)
        l.inicio = q; // se o inicio e vazio, esse nodo vai ser o primeiro
    else{ //  nao esta  vazia
        if(posicao == 1){ // se quer adcionar no primeira posicao
            q->proximo = l.inicio; // o novo, aponta para o segundo(proximo)
            l.inicio = q; // o inicio aponta para o novo. exemplo |inicio| -> |novo| -> |proximo|
        }else{ // outras posicoes, fora a primeira
            Nodo<T>* p = l.inicio;
            int contador = 1;
            while (contador != posicao -1){ // enquando nao chegar a posicao anterior a da posicao. o anterior tem o endereço do proximo, e o novo vai receber esse endereço
                p = p->proximo;
                contador++;
            }
            q-> proximo = p->proximo; // o novo aponta para o seguinte
            p->proximo = q; // o anterior aponta para o novo
        }
    }
    l.cardinalidade++;
}

//retirar um elemento da lista e exibir os elementos da lista.
template <typename T>
void retira (ListaEncadeada<T> &l, int posicao){
    if (l.cardinalidade == 0){
        throw "UNDERFLOW";
    }
    if (posicao <1||posicao> l.cardinalidade){
        throw "POSICAO INVALIDA";
    }
    Nodo<T>* q = l.inicio; // salva o inicio da lista
    if (posicao == 1)
        l.inicio = l.inicio->proximo; // salva a proxima posicao
    else {

        Nodo<T>* p = l.inicio;
        int contador = 1;
        while (contador != posicao - 1){
            p = p-> proximo;
            contador++;
        }
        q = p->proximo;
        p->proximo = q->proximo;
    }
    delete q; //so remove apos reordenar a lista
    l.cardinalidade--; //diminui a lista
}

//mostra
template <typename T>
void mostra (ListaEncadeada<T> l){
    for (Nodo<T>* p = l.inicio; p != NULL; p = p->proximo){
        cout << p->elemento << "  ";
    }cout << endl;
}


template <typename T>
Jogo (ListaEncadeada<T> &A, ListaEncadeada<T> &B, /*ListaEncadeada<T> &C,*/ int posicao){

    T resultado;
    Nodo<T>* a = A.inicio; // ja no inicio, instancia a primeira posicao
    Nodo<T>* b = B.inicio;
    //Nodo<T>* c = C.inicio;

    if (posicao > 1){ //se nao for a primeira, verifica em qual posicao esta e salva
        for (int i = 0; posicao < i; i++){
            a = a->proximo;
            b = b->proximo;
            //c = c->proximo;
        }
    }

    if (a->elemento == b->elemento) {
        cout << "Empate" << endl;
        //resultado = "empate";

    } else if ((a->elemento == 1 && b->elemento == 3) || (a->elemento == 2 && b->elemento == 1) || (a->elemento == 3 && b->elemento == 2)) {
        cout << "Jogador A vence" << endl;
        //resultado = "VenceuA";

    } else {
        cout << "Jogador B vence" << endl;}
        //resultado = "VenceuB";

    //insere(C, resultado, posicao);
}



#endif // LISTAENCADEADA_H_INCLUDED
