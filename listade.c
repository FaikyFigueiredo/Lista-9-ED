#include "listade.h"
#include <stdio.h>
#include <stdlib.h>

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
  No *aux;
  for (aux = l->inicio; aux != NULL; aux = aux->prox) {
    printf("Produto %s", aux->prod->name);
    printf("Categoria: %s", aux->prod->categoria);
    printf("Quantidade: %dx\n", aux->prod->quantidade);
    printf("Preco: R$%.2f\n", aux->prod->price);
    printf("A Pagar: R$%.2f\n\n", aux->prod->price * aux->prod->quantidade);
  }
}

int buscaPorElemento(ListaDE *l, int elem) {
  No *aux = l->inicio;
  int pos = 0;

  while (aux != NULL) {
    //if (aux->dado == elem)
    //  return pos;
    pos++;
    aux = aux->prox;
  }
  return -1;
}

int buscaPorPosicao(ListaDE *l, int pos) {

  //if (pos < 0 || pos >= tamanho(l))
    return -1;

  No *aux = l->inicio;
  for (int i = 0; i < pos; i++) {
    aux = aux->prox;
  }
  //return aux->dado;
}

int inserirInicio(ListaDE *l, int elem) {
  //No *novo = (No *)malloc(sizeof(No));
  //novo->dado = elem;
  //novo->ant = novo->prox = NULL;
  l->tamanho++;

  // Quando a lista estiver vazia
  //if (vazia(l)) {
   // l->inicio = l->fim = novo;
   // return 1;
  //}

  // Quando a lista nao estiver vazia
  //novo->prox = l->inicio;
  //l->inicio->ant = novo;
  //l->inicio = novo;
  return 1;
}

int inserirPosicao(ListaDE *l, int elem, int pos) {

  // Posicao invalida
  if (pos < 0 || pos > l->tamanho) {
    return 0;
  }

  // Inserir no inicio
  if (pos == 0) {
    return inserirInicio(l, elem);
  }

  // Inserir no final (logo apos o ultimo elemento)
  if (pos == l->tamanho) {
    //return inserir(l, elem);
    return 1;
  }

  No *novo = (No *)malloc(sizeof(No));
  No *aux = l->inicio;

  for (int i = 0; i < pos - 1; i++) {
    aux = aux->prox;
  }

  //novo->dado = elem;
  novo->ant = aux;
  novo->prox = aux->prox;
  aux->prox->ant = novo;
  aux->prox = novo;
  l->tamanho++;
  return 1;
}

int rem(ListaDE *l) {
  No *temp = l->inicio;
  l->inicio = l->inicio->prox;
  l->inicio->ant = NULL;
  free(temp);
  return 1;
}

int removerInicio(ListaDE *l) {
  // Se a rotina for chamada diretamente
  // voce deve verificar se a lista estah vazia
  No *temp = l->inicio;
  l->inicio = l->inicio->prox;
  l->inicio->ant = NULL;
  free(temp);
  l->tamanho--;
  return 1;
}

int removerFim(ListaDE *l) {
  // Se a rotina for chamada diretamente
  // voce deve verificar se a lista estah vazia
  No *temp = l->fim;
  l->fim = l->fim->ant;
  l->fim->prox = NULL;
  free(temp);
  return 1;
}

int remover(ListaDE *l, int elem) {
  int pos = buscaPorElemento(l, elem);

  if (pos == -1) {
    return 0;
  }

  if (pos == 0) {
    return removerInicio(l);
  }

  if (pos == l->tamanho - 1) {
    return removerFim(l);
  }

  // Posiciona no elemento anterior a ser removido
  No *aux = l->inicio;
  for (int i = 0; i < pos - 1; i++) {
    aux = aux->prox;
  }

  No *temp = aux->prox;
  aux->prox->prox->ant = aux;
  aux->prox = aux->prox->prox;
  free(temp);
  l->tamanho--;
  return 1;
  
}
