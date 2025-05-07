#include <iostream>
#include "lista.h"

using namespace std;

//1 fazre uma cotaçã aleatoria entre o nuemro 5 e 7 // feito
// intervalo aleatorio de -3 / +3 // feito
// 9 as 15 (6h) // feito
// 20m mostre os valores (3x) // feito
// em lista // como eu coloco isso?

//inacabado, não ficou muiot bom


int main(){
    srand(time(nullptr)); // adciona ao man pra poder ter varios numeros
    listaAcoes l1;
    l1 = cria();

    loop(l1);
    return 0;
}
