#include <stdio.h>
#include "listaDirection.h"

void menu(){
    printf("1-Adicionar um trecho\n");
    printf("2-Remover um trecho\n");
    printf("3-Exibir trechos percorridos\n");
    printf("4-Sair\n");
}
int main(){
    int ID = 0;
    ListaDE* l;
    criar(&l);
    int opt;
    float initialX, initialY;
    printf("Bem vindo ao gps manual, para comecar digite sua posicao atual (x y)\n");
    scanf("%f %f", &initialX, &initialY);
    getchar();
    while(1){
        menu();
        scanf("%d", &opt);
        getchar();
        switch (opt){
            case 1:{
                float distance;
                char direction;
                printf("Insira a direcao (w - frente, a - esquerda, s - tras, d - direita)\n");
                scanf("%c", &direction);
                getchar();
                if (direction != 'w' && direction != 'a' && direction != 's' && direction != 'd'){
                    printf("Direcao invalida inserida\n");
                    break;
                }
                printf("Insira a distancia(metros)\n");
                scanf("%f",&distance);
                getchar();
                inserir(l,direction,distance,++ID)? printf("Trecho inserido com sucesso!\n"):printf("Erro ao inserir trecho\n");
            }break;
            case 2:{
                char direction;
                printf("Insira a direcao para remover o ultimo trecho dessa direcao\n");
                scanf("%c",&direction);
                getchar();
                remover(l,direction)?printf("Remocao concluida com sucesso\n"):printf("Erro, direcao nao encontrada\n");                
            }break;
            case 3:{exibir(l,initialX,initialY);}
            break;
            case 4:{return 0;}
            break;
            default: {printf("Opcao invalida\n");}
        }
    }
}