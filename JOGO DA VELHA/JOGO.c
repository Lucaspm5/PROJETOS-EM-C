#include <stdio.h>
#include <stdlib.h>

#define linha 3
#define coluna 3
//////////////////////////////////////////////////////
void inicializa(char jogo[linha][coluna]);
void tabuleiro(char jogo[linha][coluna]);
int check_win(char jogo[linha][coluna], char jogada);
int check_lose(char jogo[linha][coluna]);
//////////////////////////////////////////////////////
int main()
{
    char jogo[linha][coluna];
    char jogada = 'X';
    int lin, col;
    int winner = 0;

    inicializa(jogo);
    tabuleiro(jogo);
    do {
        printf("Jogador %c, eh sua vez.\n", jogada);

        printf("Digite a linha (0-2) e a coluna (0-2) separadas por um espaço: ");
        scanf("%d %d", &lin, &col);

        if (jogo[lin][col] == ' ') 
        {
            jogo[lin][col] = jogada;
            winner = check_win(jogo, jogada);
            jogada = (jogada == 'X') ? 'O' : 'X';
        }else{
            printf("Posição inválida. Tente novamente.\n");
        }

        tabuleiro(jogo);

    }while(winner == 0 && check_lose(jogo) == 0);

    if (winner)
        printf("Parabéns, jogador %c! Você venceu!\n", jogada);
    else 
        printf("Empate!\n");

    return 0;
}
//////////////////////////////////////////////////////
void inicializa(char jogo[linha][coluna])
{
    int i, j;

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++){
            jogo[i][j] = ' ';
        }
    }
}
//////////////////////////////////////////////////////
void tabuleiro(char jogo[linha][coluna])
{
    int i, j;

    printf("0   1   2\n");
    for (i = 0; i < linha; i++){
        for (j = 0; j < coluna; j++){
            printf("%c", jogo[i][j]);
            if (j < coluna - 1) {
                printf(" | ");
            }
            if(j == coluna - 1)
                printf(" %d",i);
        }
        printf("\n");
        if (i < linha - 1) {
            printf("---------\n");
        }
    }
}
//////////////////////////////////////////////////////
int check_win(char jogo[linha][coluna], char jogada)
{
    int i;

    for (i = 0; i < linha; i++){
        if (jogo[i][0] == jogada && jogo[i][1] == jogada && jogo[i][2] == jogada)
            return 1;
    }

    for (i = 0; i < coluna; i++){
        if (jogo[0][i] == jogada && jogo[1][i] == jogada && jogo[2][i] == jogada)
            return 1;
    }

    if (jogo[0][0] == jogada && jogo[1][1] == jogada && jogo[2][2] == jogada)
        return 1;

    if (jogo[0][2] == jogada && jogo[1][1] == jogada && jogo[2][0] == jogada)
        return 1;

    return 0;

}
//////////////////////////////////////////////////////
int check_lose(char jogo[linha][coluna])
{
    int i, j;
    int lose = 1;

    for (i = 0; i < linha; i++){
        for (j = 0; j < coluna; j++){
            if (jogo[i][j] == ' '){
                lose = 0;
                break;
            }
        }
        if (!lose){
            break;
        }
    }

    return lose;
}
