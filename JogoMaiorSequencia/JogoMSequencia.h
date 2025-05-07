#ifndef JOGOMSEQUENCIA_H_INCLUDED
#define JOGOMSEQUENCIA_H_INCLUDED
#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;


template <typename T>
struct Nodo {//constroi o nodo que vai guardar as informações
    T elemento; //valor guardado
    Nodo<T>* proximo; // valor do proximo endereço
    Nodo<T>* anterior; // valor anterior
};

template <typename T>
struct MaoCartas{ //constroi o inicio da lista. Tamnho da lista e o nodo inicial
    int cardinalidade; // marca o tamanho fisico da lista
    Nodo<T>* inicio;
};

template <typename T>
void cria (MaoCartas<T> &l){
    l.cardinalidade = 0;
    l.inicio = NULL;
}


//destroi lista
template <typename T>
void destroi (MaoCartas<T> &l){
    Nodo<T> *p; // instanica o nodo
    while (l.inicio != NULL){ //loop percorre toda a lista, enquanto ela nao for vazia
        p = l.inicio; // salva o nodo inicial em p
        l.inicio = l.inicio->proximo; // muda o nodo do inicio para o nodo seguinte
        delete p; // deleta o nodo salvo em pedro :D
    }
    l.cardinalidade = 0;
}

//recuperar o número de elementos da lista,
template <typename T>
int NumeroDeCartas (MaoCartas <T> &l){
    return l.cardinalidade;
}

template <typename T>
int ValorCarta (MaoCartas<T> l, int posicao){
    if(posicao <1|| posicao> l.cardinalidade) {
        throw "posicao invalida";
    }
    Nodo<T>* atual = l.inicio; //começa a lista
    for (int i = 1; i < posicao; ++i) { //anda ate a posicao do elemento
        atual = atual->proximo;
    }

    return atual->elemento; //recupera o valor dentro dele
}

template <typename T>
int verificaCopias(MaoCartas<T> l){ // impede que aja  copias na lista

    int valor; //valor que retorna
    bool existe; // controle

       do {
        valor = rand() % 100 + 1; //gera valor de 1 a 100
        Nodo<T>* atual = l.inicio; //inicia o nodo no começo da lista
        existe = false; //ja inicia sendo false, faria so um loop

        // Percorre a lista para verificar se o número já existe
        while (atual != NULL) { // viaja ate a lista acabar
            if (atual->elemento == valor)
                existe = true;  // Copia encontrada, reinicia
                break;
            atual = atual->proximo;
        }
    } while (existe);// nao a copias, pode sair
    return valor;
}


//inserir um elemento na lista,
template <typename T>
compra(MaoCartas <T> &l, T elemento, int posicao){

    //adcionar sistema para nao permitir colocar um valor repetido

    Nodo<T>* q = new Nodo<T>; //cria um struct(nodo), novo (alocacao de memoria), nao esta me nenhum lugar ainda
    q->elemento = elemento; //adciona o dado
    q-> proximo = NULL; // deixa vago para o endereço seguinte
    q-> anterior = NULL;

    if(l.inicio == NULL){
        l.inicio = q; // se o inicio e vazio, esse nodo vai ser o primei
    }else{ //  nao esta  vazia
        if(posicao == 1){ // se quer adcionar no primeira posicao
            q->proximo = l.inicio; // o novo, aponta para o segundo(proximo)
            l.inicio = q; // o inicio aponta para o novo. exemplo |inicio| -> |novo| -> |proximo|
            //l.anterior = q;
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

//retirar um elemento da lista e
template <typename T>
void descarta (MaoCartas<T> &l, int posicao){
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

//mostrar uma lista.
template <typename T>
void mostra (MaoCartas<T> l){
    cout << "[ Posicao " ;
    for (int i = 1; i<= l.cardinalidade; i++){ // atravessa a lista
        cout <<" | " <<" "<< i<< " | ";
    }cout <<"] \n";

    cout << "[ Carta   ";
    for (Nodo<T>* p = l.inicio; p != NULL; p = p->proximo){
        cout <<" | " << p->elemento << " | ";
    }cout <<"]";
}


//Acoes do jogador -  Troca
template <typename T>
void trocaCartas(MaoCartas<T> &l, T carta1, T carta2){
    if (carta1 == NULL || carta2 == NULL){
        throw "Esta vazio, nao pode trocar.";}

    if(carta1 == carta2 ){return;}

    T tempo = ValorCarta(l, carta1);
    T tempo2 = ValorCarta(l, carta2);

    //adciona a posicao 1 o valor de 2, removendo o anterior
    compra (l, tempo2, carta1);
    descarta (l, carta1+1);

    //adciona a posicao 2 o valor de 1, removendo o anterior
    compra (l, tempo, carta2);
    descarta (l, carta2+1);
}

template <typename T>
int testeDeValor(MaoCartas<T> l, int acao){ // verifica se o valor que o usuario escolheu e valido
int novovalor;

    while (true){
        cin >> novovalor;
        if (cin.fail()) { // detectou valor invalido
            cin.clear(); //limpa o valor digitado

            switch(acao){
            case 1:
                cout << "Valor de posicao invalido: ";
            break;
                case 2:
                cout << "Valor de troca invalido: ";
            break;
                case 3:
                cout << "Valor de remocao, invalido: ";
            break;
            }

            cin.ignore(10, '\n');
        } else {
            if (novovalor <= l.cardinalidade+1){
              return novovalor;
              break;

            }else{
                cin.ignore(10, '\n');
                cout << "Valor ultrapassou a mao: Jogue outro.";
                false;
            }
        }
    }
}

template <typename T>
void primeiraRodada(MaoCartas<T>& l, MaoCartas<T>&M) {  //lembre de usar referencia pra modificar a lista
    srand(time(NULL));
    int valor, valor2;

    for(int i = 1; i <= 5; i++) {
        valor = verificaCopias(l);
        compra(l, valor, i);

        valor2 = verificaCopias(M);
        compra(M, valor2, i);
    }
}

template<typename T>
jogadorAcoes (MaoCartas<T> &l, int acao){
int valor, valor2;

system("cls");
cout<<endl;

    switch(acao){ //teste de escolha do usuario
        case 1:
            cout << "Voce comprou:"<<endl;
            mostra(l);
            valor = verificaCopias(l); // //valor random entre as cartas
            cout << "\n Consegiu a carta onde quer colocar? ";
            valor2 = testeDeValor(l,acao); //teste para o valor do uusario

            cout<<endl;
            compra (l, valor, valor2); //adciona a lista
            mostra(l);
            break;

        case 2:
            cout << "Voce Trocou:"<<endl;
            mostra(l);
            cout << "\n Quais cartas quer trocar? ";
            cout << "\n Primeira carta: ";
            valor = testeDeValor(l, acao);

            cout << "\n Segunda carta: ";
            valor2 = testeDeValor(l, acao);

            cout<<endl;
            trocaCartas(l, valor, valor2);
            mostra(l);
            break;

        case 3:
            cout << "Voce Descartou: "<<endl;
            mostra(l);
            cout << "\n Qual carta quer descarta? (Escolha a posicao da carta): ";
            valor = testeDeValor(l, acao);

            cout<<endl;
            descarta(l, valor);
            mostra(l);
            break;

        default: //digitou errado, recursivo para corrigir
        system("cls");
        cout <<"Valor invalido"<<endl;
        cout << "Jogador o que quer fazer? ";
        cout << "Comprar(1) - Trocar(2) - Descartar (3): ";
        cin >> acao;
        jogadorAcoes (l, acao);


    }
}
#include <algorithm> // Para a função max

template<typename T>
int MaiorSequencia(MaoCartas<T> l) {
    // Verifica se a lista está vazia
    if (l.cardinalidade == 0) {
        throw "A lista esta vazia";
    }

    Nodo<T>* Primera = l.inicio;  // Primeiro nó da comparação
    Nodo<T>* proxCarta = Primera->proximo; // Segundo nó que será comparado

    int Sequencia = 1; // Guarda o comprimento da sequência corrente
    int MSequencia = 1; // Guarda o maior comprimento de sequência encontrado

    while (proxCarta != NULL) {  // Enquanto o node não chegar no fim da lista
        if (proxCarta->elemento > Primera->elemento) {  // Verifica se o valor seguinte é maior
            Sequencia++;  // Aumenta o contador da sequência
        } else {
            MSequencia = max(MSequencia, Sequencia); // Atualiza a maior sequência
            Sequencia = 1; // Reseta a sequência
        }

        Primera = proxCarta;  // Avança para o próximo nó
        proxCarta = proxCarta->proximo; // Avança o nó seguinte
    }

    // Verifica a maior sequência no final da lista
    MSequencia = max(MSequencia, Sequencia);

    return MSequencia;  // Retorna o comprimento da maior sequência crescente
}


#endif // JOGOMSEQUENCIA_H_INCLUDED
