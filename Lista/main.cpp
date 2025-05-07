#include <iostream>
#include "list.h"

using namespace std;

int main(){ //revisar essa parte

    Lista lA, lB;
    int i, n, elemento;

    lA = cria();
    lB = cria();

    cout << "numero de elementos da primeira lista = ";
    cin >> n;

    for (i = 1; i <= n; i++){ // primeira lista
        cout << "entre com o " << i << " elemento = ";
        cin >> elemento;
        insere (lA, elemento, i);
    }
    mostra (lA);
    cout << endl;

    cout << "numero de elementos da segunda lista = ";
    cin >> n;

    for (i = 1; i <= n; i++){ // segunda lista
        cout << "entre com o " << i << " elemento = ";
        cin >> elemento;
        insere (lB, elemento, i);
    }

    mostra (lB);
    cout << endl;

    for (i = 1; i <= numeroElementos (lA); i++) // mostra os valores iguais
        if (Existe (lB, elementoRecupera (lA, i)))
            cout << posicaoRecupera(lA, i) << " e elemento comum entre as listas" << endl;

    return 0;

}
