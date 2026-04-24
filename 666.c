#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 7
#define EMPTY ' '
#define PLAYER1 'X'
#define PLAYER2 'O'

char board[ROWS][COLS];

void initialize_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void display_board() {
    printf("\n");
    printf(" 1   2   3   4   5   6   7\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    for (int j = 0; j < COLS; j++) {
        printf("----");
    }
    printf("\n");
}

int drop_piece(int col, char player) {
    if (col < 0 || col >= COLS) {
        return 0;
    }
    
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == EMPTY) {
            board[i][col] = player;
            return 1;
        }
    }
    return 0;
}

int check_win(char player) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i][j+1] == player && 
                board[i][j+2] == player && board[i][j+3] == player) {
                return 1;
            }
        }
    }
    
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == player && board[i+1][j] == player && 
                board[i+2][j] == player && board[i+3][j] == player) {
                return 1;
            }
        }
    }
    
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i+1][j+1] == player && 
                board[i+2][j+2] == player && board[i+3][j+3] == player) {
                return 1;
            }
        }
    }
    
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i-1][j+1] == player && 
                board[i-2][j+2] == player && board[i-3][j+3] == player) {
                return 1;
            }
        }
    }
    
    return 0;
}

int is_board_full() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

int get_valid_column() {
    int col;
    while (1) {
        printf("Выберите столбец (1-7): ");
        scanf("%d", &col);
        col--;
        
        if (col >= 0 && col < COLS) {
            if (board[0][col] == EMPTY) {
                return col;
            } else {
                printf("Столбец заполнен! Выберите другой.\n");
            }
        } else {
            printf("Неверный номер столбца! Введите число от 1 до 7.\n");
        }
    }
}

int main() {
    int game_over = 0;
    int current_player = 1;
    int col;
    int moves = 0;
    
    printf("=================================\n");
    printf("    ИГРА ЧЕТЫРЕ В РЯД\n");
    printf("=================================\n");
    
    initialize_board();
    
    while (!game_over) {
        display_board();
        
        if (current_player == 1) {
            printf("\nХод ИГРОКА 1 (%c):\n", PLAYER1);
        } else {
            printf("\nХод ИГРОКА 2 (%c):\n", PLAYER2);
        }
        
        col = get_valid_column();
        
        if (current_player == 1) {
            drop_piece(col, PLAYER1);
            if (check_win(PLAYER1)) {
                display_board();
                printf("\nПОЗДРАВЛЯЕМ! ИГРОК 1 ПОБЕДИЛ!\n");
                game_over = 1;
            }
            current_player = 2;
        } else {
            drop_piece(col, PLAYER2);
            if (check_win(PLAYER2)) {
                display_board();
                printf("\nПОЗДРАВЛЯЕМ! ИГРОК 2 ПОБЕДИЛ!\n");
                game_over = 1;
            }
            current_player = 1;
        }
        
        moves++;
        
        if (!game_over && is_board_full()) {
            display_board();
            printf("\nНИЧЬЯ! Доска заполнена.\n");
            game_over = 1;
        }
    }
    
    printf("\nИГРА ЗАВЕРШЕНА!\n");
    return 0;
}
