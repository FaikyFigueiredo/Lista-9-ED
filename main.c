#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listade.h"
void menu(){
  printf("\n1 - Adicionar Produto\n");
  printf("2 - Remover Produto\n");
  printf("3 - Atualizar Produto\n");
  printf("4 - Visualizar Carrinho\n");
  printf("5 - Filtrar Produtos por Categoria\n");
  printf("6 - Sair\n\n");
}
int main(){
  printf(">>> Bem-vindo ao Carrinho de Compras!\n");
  ListaDE* l = (ListaDE*)malloc(sizeof(ListaDE));
  criar(l);
  while (1){
    menu();
    int opt;
    printf("Selecione a opção:\n");
    scanf("%d", &opt);
    getchar();
    switch(opt){
      case 1:{
        int quantidade;
        float price;
        Product* p = (Product*)malloc(sizeof(Product));
        printf("Digite o nome do produto\n");
        fgets(p->name,40,stdin);
        printf("Digite a categoria do produto(Limpeza, Bebida, Alimento etc)\n");
        fgets(p->categoria,40,stdin);
        printf("Digite a quantidade do produto a ser adicionado\n");
        scanf("%d",&quantidade);
        printf("Digite o preco do produto\n");
        scanf("%f",&price);
        p->quantidade = quantidade;
        p->price = price;
        inserir(l,p);
      };
      break;
      case 2:{
        char pName[40];
        printf("Digite o nome do produto\n");
        fgets(pName,40,stdin);
        removeName(l,pName)? printf("Produto removido com sucesso\n") : printf("Produto não encontrado no carrinho\n");
      };
      break;
      case 3:{
        char name[40];
        int quantidade;
        float price;
        Product* p = (Product*)malloc(sizeof(Product));
        printf("Digite o nome do produto a ser atualizado\n");
        fgets(name,40,stdin);
        printf("Digite o novo nome do produto\n");
        fgets(p->name,40,stdin);
        printf("Digite a nova categoria do produto(Limpeza, Bebida, Alimento etc)\n");
        fgets(p->categoria,40,stdin);
        printf("Digite a nova quantidade do produto\n");
        scanf("%d",&quantidade);
        printf("Digite o novo preco do produto\n");
        scanf("%f",&price);
        p->quantidade = quantidade;
        p->price = price;
        update(l,name,p)? printf("Produto atualizado com sucesso\n") : printf("Falha ao encontrar produto, utilize opcao 4 para verificar se o nome esta correto!\n");
      };
      break;
      case 4:{
        exibir(l);
      };
      break;
      case 5:{
        char name[40];
        printf("Insira o nome da categoria a ser filtrada\n");
        fgets(name,40,stdin);
        exibirCategoria(l,name);
      };
      break;
      case 6:{return 0;};
      break;
      default:{printf("Opcao invalida\n");};
    }
  }
}