#include <stdio.h>
#include "def.h"
#include "funcoes.c"
#include <ncurses.h>
#include <string.h>

int main(){
    char tabuleiro[linhas][colunas];
    char visivel[linhas][colunas];

    criarTab(tabuleiro);
    colocarBom(tabuleiro);
    colocarNum(tabuleiro);

    criarVisivel(visivel);
    imprimirVisivel(visivel);
        
    char comando,linha;
    int coluna;
    int semParar = 1;

    printf("\n r b2 -> revelar\n ");
    printf("b b2 -> bandeira\n");
    printf(" s 00 -> sair\n\n");
    while (semParar){
        scanf(" %c %c%d",&comando,&linha,&coluna);

        if(comando=='s'&&linha=='0'&&coluna==0){
            semParar=0;

        } else if(comando=='r'){
            int x = linha-'a';
            int y = coluna-1;
            revelar(x,y,tabuleiro,visivel);
            imprimirVisivel(visivel);

            if (tabuleiro[x][y]=='!'){
                imprimirTab(tabuleiro);
                printf("BOOM!\n");
                semParar = 0;  
            }   

        }else if (comando=='b'){
            int x = linha-'a';
            int y = coluna-1;
            porBandeira(x, y, tabuleiro, visivel);
            imprimirVisivel(visivel);

        }else if (verificarVitoria(visivel,tabuleiro) && semParar){
            imprimirTab(tabuleiro);
            printf("Parabéns! Ganhastes!\n");
            semParar=0;

        } else{
            printf("comando errado.\n");
        }

    }
    return 0;
}  
