#include <stdio.h>
#include "listaDirection.h"

void menu(){
    printf("1-Adicionar um trecho\n");
    printf("2-Remover um trecho\n");
    printf("3-Sair\n");
}
int main(){
    int opt;
    float initialX, initialY;
    printf("Bem vindo ao gps manual, para comecar digite sua posicao atual (x y)\n");
    scanf("%f %f", &initialX, &initialY);
    while(1){
        menu();
        scanf("%d", &opt);
        switch (opt){
            
        }
    }
}