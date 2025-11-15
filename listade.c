#include "listade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criar(ListaDE *l) {
  l->inicio = l->fim = NULL;
  l->tamanho = 0;
}
int vazia(ListaDE *l) {
  if (l->inicio == NULL)
    return 1;
  return 0;
}
int tamanho(ListaDE *l) { return l->tamanho; }

// Inserir no Final
int inserir(ListaDE *l, Product* elem) {
  No *novo = (No *)malloc(sizeof(No));
  novo->prod = elem;
  novo->ant = novo->prox = NULL;
  l->tamanho++;

  // Quando a lista estiver vazia
  if (vazia(l)) {
    l->inicio = l->fim = novo;
    return 1;
  }

  // Quando a lista nao estiver vazia
  l->fim->prox = novo;
  novo->ant = l->fim;
  l->fim = novo;
  return 1;
}

void exibir(ListaDE *l) {
  float total=0;
  No *aux;
  for (aux = l->inicio; aux != NULL; aux = aux->prox) {
    printf("Produto - %s", aux->prod->name);
    printf("  Categoria: %s", aux->prod->categoria);
    printf("  Quantidade: %dx\n", aux->prod->quantidade);
    printf("  Preco: R$%.2f\n", aux->prod->price);
    printf("  A Pagar: R$%.2f\n\n", aux->prod->price * aux->prod->quantidade);
    total += aux->prod->price * aux->prod->quantidade;
  }
  printf("Total: %.2f\n", total);
}
void exibirCategoria(ListaDE* l,char name[]){
  No* aux = l->inicio;
  float total = 0;
  printf("Exibindo itens da categoria %s\n", name);
  for(;aux!=NULL;aux=aux->prox){
    if (strcmp(aux->prod->categoria, name) == 0){
      printf("Produto - %s", aux->prod->name);
      printf("  Categoria: %s", aux->prod->categoria);
      printf("  Quantidade: %dx\n", aux->prod->quantidade);
      printf("  Preco: R$%.2f\n", aux->prod->price);
      printf("  A Pagar: R$%.2f\n\n", aux->prod->price * aux->prod->quantidade);
      total += aux->prod->price * aux->prod->quantidade;
    }
  }
  printf("Total nessa categoria: %.2f\n", total);
}

No* searchName(ListaDE *l, char name[]) {
  No *aux = l->inicio;
  for(;aux!=NULL && strcmp(name,aux->prod->name)!=0;aux = aux->prox);
  return aux;
}
int removeName(ListaDE *l, char name[]) {
  No* toRemove = searchName(l,name);
  printf("Search valid\n");
  if (toRemove == NULL)
    return 0;
  if(toRemove == l->inicio)
    l->inicio = toRemove->prox;
  else
    toRemove->ant->prox = toRemove->prox;
  l->tamanho--;
  free(toRemove->prod);
  free(toRemove);
  return 1;
}
int update(ListaDE *l, char name[], Product* p){
  No* toUpdate = searchName(l,name);
  if (toUpdate == NULL)
    return 0;
  Product* temp = toUpdate->prod;
  toUpdate->prod = p;
  free(temp);
  return 1;
}