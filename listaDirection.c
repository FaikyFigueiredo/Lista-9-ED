#include <stdio.h>
#include "listaDirection.h"

void criar(ListaDE* l){
    l = (ListaDE*)malloc(sizeof(ListaDE));
}
int vazia(ListaDE* l){
    l==NULL? return 1: return 0;
}
int tamanho(ListaDE* l){
    int i;
    No* temp = l->inicio;
    for(i = 0 ; temp != NULL ; temp = temp->prox);
    return i;
}
int inserir(ListaDE* l, char direction, float distance, int index){
    No* new = (No*)malloc(sizeof(No));
    if(new == NULL){
        return 0;
    }
    new->direction = direction;
    new->idTrecho = index;
    new->distance = distance;
    new->ant = l->fim;
    l->fim = new;
    new->prox = NULL;
    l->tamanho++;
    return 1;
}
float distanceX(float distance, char direction){
    if (direction == 'a')
        return -1*distance;
    else if (direction == 'd')
        return distance;
    return 0;
}
float distanceY(float distance, char direction){
    if (direction == 's')
        return -1*distance;
    else if (direction == 'w')
        return distance;
    return 0;
}
void exibir(ListaDE* l, float x, float y){
    No* temp = l->inicio;
    printf("Posicao inicial: X-%.2f Y-%.2f", x,y);
    for( ; temp!=NULL ; temp = temp->prox){
        x+=directionX(temp->distance,temp->direction)
        y+=directionY(temp->distance,temp->direction);
        printf("Posicao atual no trecho%d: X-%.2f Y-%.2f",temp->idTrecho,x,y);
    }
    printf("Voce andou para esquerda por %.2f metros",searchDirection(l,'a'));
    printf("Voce andou para direita por %.2f metros",searchDirection(l,'d'));
    printf("Voce andou para frente por %.2f metros",searchDirection(l,'w'));
    printf("Voce andou para tras por %.2f metros",searchDirection(l,'s'));
    printf("Sua posicao final foi X-%.2f Y-%.2f",x,y);
}
float searchDirection(ListaDE* l, char direction){
    No* temp = l->inicio;
    float len;
    for (len = 0; temp!=NULL ; temp = temp->prox){
        if (temp->direction == direction)
            len+= temp->distance;
    }
    return len;
}
int remove(ListaDE* l, char direction){
    No* temp = l->fim;
    for(;temp->direction!=direction && temp!=NULL;temp=temp->ant);
    if (temp == NULL)
        return 0;
    if (l->inicio == temp){
        l->inicio = temp->prox;
    }else
        temp->ant = temp->prox;
    free(temp);
    l->tamanho--;
    return 1;
}