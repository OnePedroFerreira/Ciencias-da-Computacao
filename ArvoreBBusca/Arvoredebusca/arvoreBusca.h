#ifndef ARVOREBUSCA_H_INCLUDED
#define ARVOREBUSCA_H_INCLUDED

#include <iostream>

 using namespace std;

 //tipo generica
 //criar*, destruir*, estaVazia, numeroDeElementos
 //ElementoExiste, inserir*, remover*, exibir


 template<typename T>
 struct Nodo{
     T elemento;
     Nodo* subArvoreEsquerda;
     Nodo* subArvoreDireita;
 };

 template<typename T>
 struct ArvoreBinariaBusca{
     int cardinalidade;
     Nodo<T>* raiz;
 };

 template<typename T>
 void cria(ArvoreBinariaBusca<T> &arvore){
     arvore.cardinalidade = 0;
     arvore.raiz = NULL;
 }

 template<typename T>
 void destroiArvore(Nodo<T>* &raiz){
     if(raiz != NULL){
         destroiArvore(raiz->subArvoreEsquerda);
         destroiArvore(raiz->subArvoreDireita);
         delete(raiz);
     }
 }

 template<typename T>
 void destroi(ArvoreBinariaBusca<T> &arvore){
     destroiArvore(arvore.raiz);
     arvore.cardinalidade = 0;
 }

 //____________________________________________________

template<typename T>
void insereEmArvore (ArvoreBinariaBusca<T> &arvore, T elemento){

    if (arvore == NULL){
    cria(arvore);
    arvore.elemento = elemento;
    arvore.subArvoreEsquerda = NULL;
    arvore.subArvoreDireita = NULL;
    }
    else{
        if (elemento < arvore.elemento){
        isereEmArvore(elemento, arvore.subArvoreEsquerda);
        }else{
        isereEmArvore(elemento, arvore.subArvoreDireita);
        }
    }

}



template<typename T>
void retiraEmArvore (ArvoreBinariaBusca<T> &arvore){
T q = arvore;

    if(!arvore.subArvoreDireita == NULL){
       reitiaEmArvore(arvore.subArvoreDireita);
    }else{
       q .chave <- arvore.elemento;
       q <- arvore;
       arvore <- q.subArvoreEsquerda;
    }
}

template<typename T>
void RemoveEmArvore (ArvoreBinariaBusca<T> &arvore, T elemento){
   T q = arvore;

    if (elemento < arvore.elemento){delete (elemento, arvore.subArvoreEsquerda);}
    else{
        if(elemento > arvore.elemento){delete (elemento, arvore.subArvoreDireita);}
        else{
            //T q <- arvore;
            if(arvore.subArvoreDireita == NULL){arvore <- q.subArvoreEsquerda;}
            else{
                if(q.subArvoreEsquerda ==NULL){ arvore <- q.subArvoredireita;}
                else{
                   retiraEmArvore(arvore.subArvoreEsquerda);
                }
            }
            T q = NULL;
        }
    }
}



//_________________________________________________

template <typename T>
bool estaVazia (ArvoreBinariaBusca<T> arvore){
    if (arvore == NULL){return true;}
    return false;
}

template <typename T>
bool elementoExiste(ArvoreBinariaBusca<T> arvore, T elemento){
    return elementoExisteEmArvore(arvore.raiz, elemento);
}

template <typename T>
void ExibeArvore(ArvoreBinariaBusca<T> arvore, T elemento){
    if(arvore != NULL){
        exibeArvore(arvore->subArvoreEsquerda);
        cout << arvore->elemento << " ";
        exibeArvore(arvore->subArvoreDireita);
    }
}

template <typename T>
void exibe(ArvoreBinariaBusca<T> arvore){
    ExibeArvore(arvore.raiz);
    cout << endl;
}



#endif // ARVOREBUSCA_H_INCLUDED
