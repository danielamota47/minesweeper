#include <stdio.h>
#include "def.h"
#include "funcoes.c"

int main(){
    char tabuleiro[linhas][colunas];
    criarTab(tabuleiro);
    colocarBom(tabuleiro);
    colocarNum(tabuleiro);
    imprimirTab(tabuleiro);

    return 0;
} 