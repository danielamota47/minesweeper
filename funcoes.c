#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "def.h"


//modo beginner
#define linhas 9
#define colunas 9
#define bombas 10

void criarTab(char tabuleiro[linhas][colunas]){
    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            tabuleiro[i][j] = '_';
        }
    }
}

void criarVisivel(char tabuleiro[linhas][colunas]){
    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            tabuleiro[i][j] = '#';
        }
    }
}

void colocarBom(char tabuleiro[linhas][colunas]){
    int colocadas = 0;
    srand(time(NULL));

    while(colocadas<bombas){
        int l = rand() % linhas;
        int c = rand() % colunas;
        if(tabuleiro[l][c] == '_'){
           tabuleiro[l][c] = '!'; 
           colocadas++;
        } 
    }
}

void colocarNum(char tabuleiro[linhas][colunas]){
    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            if(tabuleiro[i][j] == '_'){
                tabuleiro[i][j] = contarBom(tabuleiro,i,j);
            } 
        }
    }
}

char contarBom(char tabuleiro[linhas][colunas], int i, int j){
    int bombasRedor = 0;

    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,1,-1,-1,0,1};
    for(int k=0;k<8;k++){
        int ni = i+dx[k];
        int nj = j+dy[k];
        if(ni>=0 && ni<linhas && nj>=0 && nj<colunas){
            if(tabuleiro[ni][nj] == '!') bombasRedor++;
        }
    }
    return bombasRedor+'0';
}

void imprimirVisivel(char visivel[linhas][colunas]){
    printf("   ");
    for(char j='a';j<'a'+colunas;j++){
        printf("%c ",j);
    }
    printf("\n");
    
    for(int i=0;i<linhas;i++){
        printf("%c| ",'a'+i);
        for(int j=0;j<colunas;j++){
            printf("%c ",visivel[i][j]);
        }
        printf("\n");
    }
}

void imprimirTab(char tabuleiro[linhas][colunas]){
    printf("   ");
    for(char j='a';j<'a'+colunas;j++){
        printf("%c ",j);
    }
    printf("\n");
    
    for(int i=0;i<linhas;i++){
        printf("%c| ",'a'+i);
        for(int j=0;j<colunas;j++){
            printf("%c ",tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void revelar(int x, int y, char tabuleiro[linhas][colunas], char visivel[linhas][colunas]){
    if(x<0 || x>linhas || y<0 || y>colunas) return;
    visivel[x][y] = tabuleiro[x][y];
}



