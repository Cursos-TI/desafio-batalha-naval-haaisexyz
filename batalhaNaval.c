#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Trabalho Batalha Naval - Murillo :)

    int tabuleiro[10][10];
    int i, j;

    // Preenche o tabuleiro
    for(i=0;i<10;i++){
    for(j=0;j<10;j++){
    tabuleiro[i][j] = 0;
    }}

    // Navios
    int nav1[3] = {3,3,3};
    int nav2[3] = {3,3,3};
    int navD1[3] = {3,3,3};
    int navD2[3] = {3,3,3};

    // Horizontal
    int lin = 2;
    int col = 8;
    int ok = 1;

    if(col+3>=10){
        ok=0;
    }

    for(i=0;i<3;i++){
        if(tabuleiro[lin][col+i]!=0){
            ok=0;
        }
    }

    if(ok==1){
        for(i=0;i<3;i++){
            tabuleiro[lin][col+i] = nav1[i];
        }
    } else {
        printf("Erro ao colocar navio 1\n");
    }

    // Vertical
    int l=6;
    int c=0;
    int v=1;

    if(l+3>10){
        v=0;
    }

    for(i=0;i<3;i++){
        if(tabuleiro[l+i][c]!=0){
            v=0;
        }
    }

    if(v==1){
        for(i=0;i<3;i++){
            tabuleiro[l+i][c] = nav2[i];
        }
    } else {
        printf("Erro ao colocar navio 2\n");
    }

    // Diagonal
    int li = 7;
    int cj = 7;
    int d1 = 1;

    if(li+3>=10 || cj+3>=10){
        d1=0;
    }

    for(i=0;i<3;i++){
        if(tabuleiro[li+i][cj+i]!=0){
            d1=0;
        }
    }

    if(d1==1){
        for(i=0;i<3;i++){
            tabuleiro[li+i][cj+i] = navD1[i];
        }
    } else {
        printf("Erro ao colocar navio 3\n");
    }

    // Diagonal
    int lz = 6;
    int cz = 2;
    int d2 = 1;

    if(lz+3>10 || cz-2<0){
        d2 = 0;
    }

    for(i=0;i<3;i++){
        if(tabuleiro[lz+i][cz-i]!=0){
            d2 = 0;
        }
    }

    if(d2==1){
        for(i=0;i<3;i++){
            tabuleiro[lz+i][cz-i] = navD2[i];
        }
    } else {
        printf("Erro ao colocar navio 4\n");
    }

    // Resultado
    printf("Tabuleiro Final: \n");

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%d ",tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
