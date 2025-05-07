#include <iostream>
#include "listagenericaestoque.h"
#include <string>
using namespace std;
//falha
int main()
{
//Crie uma lista que gerencie uma estoque de produtos. Deve permitir:
//1)inserir produtos, lendo o nome, o preço e a posição no estoque;
//2) remover um produto a partir de sua posição no estoque;
//3) exibir todos os produtos cadastrados no estoque.
//O programa deve lançar exceções apropriadas para tentativas de inserção em uma lista cheia,
//remoção de um produto de uma lista vazia ou acesso a posições inválidas.
/*
    const int tam = 10;


    ListaCompras<string, double, tam> ListaValor;
    cria(ListaValor);

    insereNaLista(ListaValor,"novo", 1.1,1);
*/

//Versao do professor

struct Produto {
    string nome;
    double preco;
};

 template<typename T>
 void mostraProduto(T p) {
     cout << "Produto: " << p.nome << " | Preco: R$ " << p.preco << endl;
 }

 int main() {
     const int MAX = 100;
     ListaEstaticaGenerica<Produto, MAX> estoque;

     cria(estoque);

     int opcao;
     do {
         cout << "\nMenu de Gerenciamento de Estoque:\n";
         cout << "1 - Inserir Produto\n";
         cout << "2 - Remover Produto\n";
         cout << "3 - Exibir Produtos\n";
         cout << "0 - Sair\n";
         cout << "Escolha uma opcao: ";
         cin >> opcao;

         try {
         if (opcao == 1) {
         Produto p;
             int posicao;
             cout << "Nome do produto: ";
             cin.ignore();
             getline(cin, p.nome);
             cout << "Preco do produto: ";
             cin >> p.preco;
             cout << "Posicao para inserir: ";
             cin >> posicao;
             insere(estoque, p, posicao);
             cout << "Produto inserido com sucesso.\n";
         } else if (opcao == 2) {
             int posicao;
             cout << "Posicao do produto a remover: ";
             cin >> posicao;
             retira(estoque, posicao);
             cout << "Produto removido com sucesso.\n";
         } else if (opcao == 3) {
             if (ehVazia(estoque)) {
                cout << "Estoque vazio.\n";
            } else {
                cout << "Produtos no estoque:\n";
                 for (int i = 1; i <= numeroDeElementos(estoque); i++) {
                 mostraProduto(umElemento(estoque, i));
                }
            }
         } else if (opcao == 0) {
            cout << "Saindo...\n";
         } else {
            cout << "Opcao invalida.\n";
         }
         } catch (const char* msg) {
            cout << "Erro: " << msg << endl;
         }
     } while (opcao != 0);

 return 0;

}
