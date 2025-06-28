#include <stdio.h>
#include <stdlib.h>

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
        }
    }

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
        printf("Erro ao colocar navio 1 \n");
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
        printf("Erro ao colocar navio 2 \n");
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
        printf("Erro ao colocar navio 3 \n");
    }

    // Diagonal ↙
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
        printf("Erro ao colocar navio 4 \n");
    }

    // Cone
    int cone[5][5];
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(i>=j && i>=4-j){
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // Cruz
    int cruz[5][5];
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(i==2 || j==2){
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // Octaedro
    int octaedro[5][5];
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(abs(i-2)+abs(j-2)<=2){
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // Aplica cone no tabuleiro
    int x0 = 4;
    int y0 = 4;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            int x = x0 - 2 + i;
            int y = y0 - 2 + j;
            if(x >= 0 && x < 10 && y >= 0 && y < 10){
                if(cone[i][j]==1 && tabuleiro[x][y]==0){
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // Aplica Cruz
    int lx = 2;
    int cx = 6;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            int x = lx - 2 + i;
            int y = cx - 2 + j;
            if(x >= 0 && x < 10 && y >= 0 && y < 10){
                if(cruz[i][j]==1 && tabuleiro[x][y]==0){
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // Aplica octaedro
    int lo = 6;
    int co = 6;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            int x = lo - 2 + i;
            int y = co - 2 + j;
            if(x >= 0 && x < 10 && y >= 0 && y < 10){
                if(octaedro[i][j]==1 && tabuleiro[x][y]==0){
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // Mostrar resultados
    printf("Tabuleiro Final Com Habilidades: \n");

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n ");
    }

    return 0;
}
