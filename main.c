#include <stdio.h>
#include "def.h"
#include "funcoes.c"
#include <ncurses.h>

int main(){
    char tabuleiro[linhas][colunas];
    char visivel[linhas][colunas];

    criarTab(tabuleiro);
    colocarBom(tabuleiro);
    colocarNum(tabuleiro);

    criarVisivel(visivel);
    imprimirVisivel(visivel);
    
    char c1,c2,cB1,cB2;
    while(1){
        printf("\nRevelar coordenada ('00' para BANDEIRA): ");
        scanf(" %c %c",&c1,&c2);

        if(c1=='0' && c2=='0'){
            printf("Coordenadas da bandeira: ");
            scanf(" %c %c", &cB1,&cB2);
            int nB1 = cB1-'a';
            int nB2 = cB2-'a';
            porBandeira(nB1,nB2,tabuleiro,visivel);
            imprimirVisivel(visivel);
        } else{
            int x = c1-'a';
            int y = c2-'a';
            revelar(x,y,tabuleiro,visivel);
            imprimirVisivel(visivel);

            if(tabuleiro[x][y]=='!'){
                imprimirTab(tabuleiro);
                printf("BOOM!\n");
                break;
            }
        }
    }

    return 0;
}  