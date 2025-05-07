#ifndef LISTDUPLAMENCADEDA_H_INCLUDED
#define LISTDUPLAMENCADEDA_H_INCLUDED

//lista dinâmica duplamente encadeada e construa operações e relações para:

//criar uma lista,
template <typename T> //ajustar
struct Nodo {//constroi o nodo que vai guardar as informações
    T elemento; //valor guardado
    Nodo<T>* proximo; // valor do proximo endereço
    Nodo<T>* anterior; // valor anterior
};

template <typename T>
struct ListaDuplaEncadeada{ //constroi o inicio da lista. Tamnho da lista e o nodo inicial
    int cardinalidade; // marca o tamanho fisico da lista
    Nodo<T>* inicio; // marca o inicio da lista de nodos
    Nodo<T>* fim; // mas o fim da fila
};

template <typename T>
void cria (ListaDuplaEncadeada<T> &l){
    l.cardinalidade = 0;
    l.inicio = NULL;
    l.fim = NULL;
}

//destroi lista
template <typename T>
void destroi (ListaDuplaEncadeada<T> &l){
    Nodo<T> *p; // instanica o nodo
    while (l.inicio != NULL){ //loop percorre toda a lista, enquanto ela nao for vazia
        p = l.inicio; // salva o nodo inicial em p
        l.inicio = l.inicio->proximo; // muda o nodo do inicio para o nodo seguinte
        delete p; // deleta o nodo salvo em p
    }
    l.cardinalidade = 0;
}

//lista e vazia
template <typename T>
bool ListaVazia (ListaDuplaEncadeada <T> l){
    return l.cardinalidade == 0;
}

//recuperar o número de elementos da lista,
template <typename T>
int ListaNumeroElementos (ListaDuplaEncadeada <T> &l){
    return l.cardinalidade;
}

//verificar se um elemento existe na lista,
template <typename T> //terminar
bool ListaVerificaElemento (ListaDuplaEncadeada<T> &l, T elemento){
   if (l.cardinalidade == 0 ){ throw "A lista esta vazia";}

   Nodo<T> *p = l.inicio; //instancia o primeiro nodo
    for (int i = 0; i < l.cardinalidade; i++){ //viaja toda a lista
        if(p->elemento == elemento){
            return true;
        }
        p = p->proximo; // instancia o nodo seguinte(proximo)
    }return false;
}

//inserir um elemento na lista,
template <typename T>
insere (ListaDuplaEncadeada <T> &l, T elemento, int posicao){

    Nodo<T>* q = new Nodo<T>; //cria um struct(nodo), novo (alocacao de memoria), nao esta me nenhum lugar ainda
    q->elemento = elemento; //adciona o dado
    q-> proximo = NULL; // deixa vago para o endereço seguinte
    q->anterior = NULL;

    if(l.inicio == NULL)
        l.inicio = q; // se o inicio e vazio, esse nodo vai ser o primeiro
        l.anterior = q;
    else{ //  nao esta  vazia
        if(posicao == 1){ // se quer adcionar no primeira posicao
            q->proximo = l.inicio; // o novo, aponta para o segundo(proximo)
            l.inicio = q; // o inicio aponta para o novo. exemplo |inicio| -> |novo| -> |proximo|
            l.anterior = q;
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

//mostrar uma lista.
template <typename T>
void mostra (ListaDuplaEncadeada<T> l){
    for (Nodo<T>* p = l.inicio; p != NULL; p = p->proximo){
        cout << p->elemento << "  ";
    }cout << endl;
}


#endif // LISTDUPLAMENCADEDA_H_INCLUDED
