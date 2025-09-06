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
        
    char entrada[3], cB1,cB2;
    int semParar = 1;

    while (semParar) {
        printf("\nRevelar coordenada ('00' para BANDEIRA, '11' para SAIR): ");
        scanf("%2s", entrada);

        if (strcmp(entrada,"00")==0) {
            printf("Coordenadas da bandeira: ");
            scanf(" %c %c", &cB1, &cB2);
            int nB1 = cB1 - 'a';
            int nB2 = cB2 - 'a';
            porBandeira(nB1, nB2, tabuleiro, visivel);
            imprimirVisivel(visivel);

        } else if (strcmp(entrada,"11")==0) {
            semParar = 0;  
        } else {
            int x = entrada[0] - 'a';
            int y = entrada[1] - 'a';
            revelar(x, y, tabuleiro, visivel);
            imprimirVisivel(visivel);

            if (tabuleiro[x][y] == '!') {
                imprimirTab(tabuleiro);
                printf("BOOM!\n");
                semParar = 0;  
            }
        }
    }

    return 0;
}  
