#include <stdio.h>
#include "def.h"
#include "funcoes.c"

int main(){
    char tabuleiro[linhas][colunas];
    char visivel[linhas][colunas];

    criarTab(tabuleiro);
    colocarBom(tabuleiro);
    colocarNum(tabuleiro);

    criarVisivel(visivel);
    imprimirVisivel(visivel);
    
    
    char c1,c2;
    int x,y;
    while(1){
        printf("\nRevelar coordenada: ");
        scanf(" %c %c",&c1,&c2);

        x = c1-'a';
        y = c2-'a';
        revelar(x,y,tabuleiro,visivel);
        imprimirVisivel(visivel);

        if(tabuleiro[x][y]=='!'){
            imprimirTab(tabuleiro);
            printf("BOOM!\n");
            break;
        }
    }

    return 0;
} 