#include <iostream>
#include "filaSuperMercado.h"
#include <time.h>

using namespace std;

/*
    /Simular o movimento de um supermercado durante 5 horas.
    /A unidade de tempo da simulação é o minuto.
    /Há quatro caixas de atendimento, sendo uma delas caixa-expressa que somente atende clientes com, no máximo, 6 volumes.

    /O funcionamento das caixas é o seguinte:
        -caixa 4 (caixa-expressa) : atende 1 cliente a cada 2 minutos
        -caixa 1 :                  atende 1 cliente a cada 4 minutos
        -caixa 2 :                  atende 1 cliente a cada 5 minutos
        -caixa 3 :                  atende 1 cliente a cada 7 minutos


    /O número de volumes de cada cliente é aleatório, entre 1 e 50.
    /A cada minuto chega um cliente que escolhe para ser atendido a caixa que tiver a menor fila.
    /Caso haja mais de uma fila com o mesmo tamanho, o cliente escolherá a que oferecer o menor tempo de atendimento.
    /No início da simulação há 4 clientes na caixa 1, 3 na caixa 2, 2 na caixa 3 e 4 na caixa 4.

    [Admita a estrutura de fila estática para representar as filas envolvidas na simulação.]

*/

int main(){

    FilaEstaticaCircular<int,50> FilaRapida; // so ate 6 volumes
    FilaEstaticaCircular<int,50> FilaA;
    FilaEstaticaCircular<int,50> FilaB;
    FilaEstaticaCircular<int,50> FilaC;

    criaFila(FilaRapida); //em 2 minutos
    criaFila(FilaA); // em 4 minutos
    criaFila(FilaB); // em 5 minutos
    criaFila(FilaC); // em 7 minutos

    srand(time(NULL));
    int novoCliente;
    //novoCliente = rand() % 51;


    //insere valores na lista para iniciar
   for (int i = 0; i<4; i++){
        insereFila(FilaA, novoCliente = rand() % 51);
        insereFila(FilaRapida, novoCliente = rand() %7);

        if( i != 2 ){insereFila(FilaB, novoCliente = rand() %51);}
        if (i <= 1 ){insereFila(FilaC, novoCliente = rand() %51);}
    }

    //mostraFila(FilaRapida);mostraFila(FilaA);mostraFila(FilaB);mostraFila(FilaC); //mostra as filas


    try{
        cout <<endl;
        cout << "Os caixas abriram:" <<endl;
        cout << "----------------------------------"<<endl;
        //inicia o programa
        for (int minutos = 0; minutos < 301; minutos++){

            if (minutos % 2 == 0){
                if (!estaVazia(FilaRapida))
                    retiraFila(FilaRapida);
            }
            if (minutos % 4 == 0){
                if (!estaVazia(FilaA))
                    retiraFila(FilaA);
            }
            if (minutos % 5 == 0){
                if (!estaVazia(FilaB))
                    retiraFila(FilaB);
            }
            if (minutos % 7 == 0){
                if (!estaVazia(FilaC))
                    retiraFila(FilaC);
            }


            //verifica quem tem a  menor fila, se for o rapido, verifica se o cliente tem 6 ou menos itens
            //se nao, pega o segundo menor caixa, se dois forem iguais, pega o que tem menor tempo


            //verifica se tem menos de 6 itens e se e menor que as outras
            if (novoCliente <= 6){
                if (numeroElementos(FilaRapida) <= numeroElementos(FilaA) &&
                    numeroElementos(FilaRapida) <= numeroElementos(FilaB) &&
                    numeroElementos(FilaRapida) <= numeroElementos(FilaC))
                    insereFila(FilaRapida, novoCliente = rand() % 51);
            }
            //Verifica se a fila A e menor


            if (numeroElementos(FilaC) < numeroElementos(FilaA) &&
                numeroElementos(FilaC) < numeroElementos(FilaB)){
                insereFila(FilaC, novoCliente = rand() % 51);
            }
            //verifica se a fila B e menor
            else if ( numeroElementos(FilaB) < numeroElementos(FilaA)){
                insereFila(FilaB, novoCliente = rand() % 51);
            }
            //Verifica se a fila C e menor
            else {
                insereFila(FilaA, novoCliente = rand() % 51);
            }

            if(minutos%60 == 0){
            cout <<"Se passou " <<minutos/60 << " uma hora"<<endl;
            cout << endl;
            cout <<"O caixa A tem " << numeroElementos(FilaA)<<" clientes"<<endl;
            mostraFila(FilaA);
            cout <<"O caixa B tem " << numeroElementos(FilaB)<<" clientes"<<endl;
            mostraFila(FilaB);
            cout <<"O caixa C tem " << numeroElementos(FilaC)<<" clientes"<<endl;
            mostraFila(FilaC);
            cout <<"O caixa Rapido tem " << numeroElementos(FilaRapida)<<" clientes"<<endl;
            mostraFila(FilaRapida);

            cout<<endl;
            cout << "----------------------------------"<<endl;
            }
        }
    }catch (const char *msg){
        cout << "Ouve um: "<< msg<< endl;
    }


    return 0;
}
