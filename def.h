#define linhas 9
#define colunas 9

void criarTab(char tabuleiro[linhas][colunas]);
void colocarBom(char tabuleiro[linhas][colunas]);
void colocarNum(char tabuleiro[linhas][colunas]);
char contarBom(char tabuleiro[linhas][colunas], int i, int j);
void imprimirTab(char tabuleiro[linhas][colunas]);
void imprimirVisivel(char visivel[linhas][colunas]);
void revelar(int x, int y, char tabuleiro[linhas][colunas], char visivel[linhas][colunas]);


