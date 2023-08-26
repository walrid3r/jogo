#include <stdio.h>

// Função para imprimir o tabuleiro
void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
            if (j < 2) {
                printf(" | ");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("---------\n");
        }
    }
}

// Função para verificar se há um vencedor
char checkWinner(char board[3][3]) {
    // Checar linhas e colunas
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    
    // Checar diagonais
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    
    return ' ';
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    int currentPlayer = 0; // 0 para jogador X, 1 para jogador O
    int totalMoves = 0;
    
    while (1) {
        // Mostrar o tabuleiro
        printf("Jogo da Velha\n");
        printBoard(board);
        
        // Determinar o símbolo do jogador atual
        char symbol = (currentPlayer == 0) ? 'X' : 'O';
        
        // Obter a jogada do jogador
        int row, col;
        printf("Jogador %c, digite a linha (0-2) e coluna (0-2) separadas por um espaço: ", symbol);
        scanf("%d %d", &row, &col);
        
        // Verificar se a jogada é válida
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Jogada inválida. Tente novamente.\n");
            continue;
        }
        
        // Atualizar o tabuleiro
        board[row][col] = symbol;
        totalMoves++;
        
        // Verificar se há um vencedor ou empate
        if (totalMoves >= 5) {
            char winner = checkWinner(board);
            if (winner != ' ') {
                printf("Jogador %c venceu!\n", winner);
                break;
            } else if (totalMoves == 9) {
                printf("Empate!\n");
                break;
            }
        }
        
        // Trocar de jogador
        currentPlayer = 1 - currentPlayer;
    }
    
    return 0;
}
