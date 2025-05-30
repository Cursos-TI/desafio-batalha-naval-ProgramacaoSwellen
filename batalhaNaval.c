#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas dos navios (definidas no código)
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    int i;
    int sobreposicao = 0;

    // Verificação de limites
    if (coluna_horizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        linha_vertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: navio fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Verificação de sobreposição
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_horizontal][coluna_horizontal + i] == NAVIO ||
            tabuleiro[linha_vertical + i][coluna_vertical] == NAVIO) {
            sobreposicao = 1;
        }
    }

    if (sobreposicao) {
        printf("Erro: os navios estão se sobrepondo.\n");
        return 1;
    }

    // Posiciona navios
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = NAVIO;
        tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
    }

    // Título do tabuleiro
    printf("Tabuleiro Batalha Naval\n\n");

    // Cabeçalho com letras (colunas)
    printf("   ");
    for (char letra = 'A'; letra < 'A' + TAMANHO_TABULEIRO; letra++) {
        printf(" %c", letra);
    }
    printf("\n");

    // Exibe o tabuleiro com números (linhas)
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        printf("%2d ", linha + 1);
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf(" %d", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}