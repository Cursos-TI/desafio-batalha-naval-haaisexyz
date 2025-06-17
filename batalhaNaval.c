#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Trabalho Batalha Naval - Murillo :) 
    
    int tabuleiro[10][10]; // Matriz do tabuleiro
    int i = 0, j = 0; // Variáveis de controle

    int navio1[3] = {3, 3, 3}; // Navio Horizontal
    int navio2[3] = {3, 3, 3}; // Navio Vertical

    // "Preenchendo" o tabuleiro
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas do Navio Horizontal
    int linha1 = 3;
    int coluna1 = 5;
    int verificacao1 = 1;

    if (coluna1 + 3 > 10) {
        verificacao1 = 0;
    }

    // Verificação de lugar para evitar erro
    for(i = 0; i < 3; i++) {
        if (tabuleiro[linha1][coluna1 + i] != 0) {
            verificacao1 = 0;
        }
    }

    if (verificacao1 == 1) {
        for(i = 0; i < 3; i++) {
            tabuleiro[linha1][coluna1 + i] = navio1[i];
        }
    } else {
        printf("erro colocando navio 1 :(\n");
    }

    // Navio vertical
    int linha2 = 6;
    int coluna2 = 2;
    int verificacao2 = 1;

    if (linha2 + 3 > 10) {
        verificacao2 = 0;
    }

    for(i = 0; i < 3; i++) {
        if (tabuleiro[linha2 + i][coluna2] != 0) {
            verificacao2 = 0;
        }
    }

    if (verificacao2 == 1) {
        for(i = 0; i < 3; i++) {
            tabuleiro[linha2 + i][coluna2] = navio2[i];
        }
    } else {
        printf("erro colocando navio 2 :(\n");
    }

    // Resultado
    printf("Tabuleiro Final:\n");

    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
