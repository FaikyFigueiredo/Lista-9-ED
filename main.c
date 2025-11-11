#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listade.h"

void menu(){
  printf("1 - Adicionar Produto\n");
  printf("2 - Remover Produto\n");
  printf("3 - Atualizar Produto\n");
  printf("4 - Visualizar Carrinho\n");
  printf("5 - Filtrar Produtos por Categoria\n");
  printf("6 - Sair\n");
}
int main(){
  printf(">>> Bem-vindo ao Carrinho de Compras!\n\n");
  ListaDE* l = (ListaDE*)malloc(sizeof(ListaDE));
  criar(l);
  while (1){
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
        printf("Digite a quantidade do produto\n");
        scanf("%d",&quantidade);
        printf("Digite o preco do produto\n");
        scanf("%f",&price);
        p->quantidade = quantidade;
        p->price = price;
        inserir(l,p);
      };
      break;
      case 2:{

      };
      break;
      case 3:{

      };
      break;
      case 4:{
        exibir(l);
      };
      break;
      case 5:{

      };
      break;
      case 6:{return 0;};
      break;
      default:{printf("Opcao invalida\n");};
    }
  }
}