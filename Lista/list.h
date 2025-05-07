#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

using namespace std;

//cria lista
struct Lista {
    int elemento[100];
    int cardinalidade;
};

Lista cria (){
    Lista l;

    //l.elemento [100];
    l.cardinalidade = 0;

    return l;
}

//verificar se esta vazia
bool listaVazia (Lista l){
    return l.cardinalidade == 0; // true se a cardinalidade e zero
}

//verificar se a espaço na lista
bool temEspaco (Lista l){
    return l.cardinalidade < 99; // true se nao for mais que 100
}

//recuperar o numero de elementos
int numeroElementos (Lista l){
    return l.cardinalidade; //tamanho da cardinalidade
}

//verificar se determinado elemento esta na lista
bool Existe (Lista l, int elemento){
    bool tem = false; // começa sem saber se a o elemento
    int i = 0; // inicio loop

    while ((i< l.cardinalidade) && (tem == false)){ //enquanto nao passar por toda a cardinalidade, e não achar o elemento
        if (l.elemento[i] == elemento){ tem = true; } else { i++; }
    }return tem; // retorn o que achou

}

//verificar se determinada posição esta livre
bool temPosicao (Lista l, int posicao){
    return ((posicao>=1) && (posicao<= l.cardinalidade)); // verifica se e = ou maior que 1, e se o valor e menor ou = a cardinalidade
    // faz assim pra verificar se a posicao e valida para a cardinalidade
}

//recuperar um elemento da lista
int elementoRecupera (Lista l, int posicao){
    return l.elemento [posicao - 1]; //parametro da posica, da lista, logica
}

//recuperar a posição de um elemento da lista
int posicaoRecupera (Lista l, int posicao){ // onde aquele elemento esta na lista
    int i = 0;
    while (l.elemento[i] !=posicao){ //espera que elemento exista na lsita
        i++;
    } return i+1;
}

//insira um elemento
void insere (Lista &l, int elemento, int posicao){
    for (int i = l.cardinalidade; i >= posicao; i--) // configura posicao
        l.elemento[i] = l.elemento[i-1];
    l.elemento[posicao - 1] = elemento; // novo elemento na posicao
    l.cardinalidade ++; //novo elemento, mais cardinalidade

}

//retire um elemento
void retira (Lista &l, int posicao){
    for (int i = posicao; i < l.cardinalidade; i++)

        l.elemento[i - 1] = l.elemento[i];
    l.cardinalidade--;
}

//exiba os elementos da lista
void mostra (Lista l){ // corrigir
    for (int i =0; i < l.cardinalidade; i++){
        cout << l.elemento[i] << " " ;
    }
}



#endif // LIST_H_INCLUDED
