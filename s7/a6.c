#include <stdio.h>
#include <stdlib.h>

#define PLAYER_X 1
#define PLAYER_CIRCLE 2
#define X PLAYER_X
#define O PLAYER_CIRCLE
#define EMPTY 0
#define BOARD_SIZE 3

char chooseCharacter(int val);

int countValueInRow(int** matrix, int n, int val, int row) {
    int i, cnt = 0;
    for(i = 0; i < n; i++)
        cnt += matrix[row][i] == val ? 1 : 0;
    return cnt;
}   

// col is up down
int countValueInCol(int** matrix, int m, int val, int col) {
    int i, cnt = 0;
    for(i = 0; i < m; i++)
        cnt += matrix[i][col] == val ? 1 : 0;
    return cnt; 
}

int** createBoard() {
    int** board = malloc(sizeof(int**) * BOARD_SIZE);
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        board[i] = malloc(sizeof(int*) * BOARD_SIZE);
        for(j = 0; j < BOARD_SIZE; j++)
            board[i][j] = EMPTY;
    }
    return board;
}

int checkWinner(int** board) {
    int i;
    for(i = 0; i < BOARD_SIZE; i++)
        if(countValueInRow(board, BOARD_SIZE, X, i) == 3 
            || countValueInCol(board, BOARD_SIZE, X, i) == 3)
            return PLAYER_X;
        else if(countValueInRow(board, BOARD_SIZE, O, i) == 3 
            || countValueInCol(board, BOARD_SIZE, O, i) == 3)
            return PLAYER_CIRCLE;
    int dia = board[0][0]  & board[1][1] & board[2][2] ;
    int dia2 = board[0][2] & board[1][1] & board[2][0];
    if( dia == X || dia2 == X)
        return PLAYER_X;
    else if(dia == O || dia2 == O)
        return PLAYER_CIRCLE;
    return 0;
}

int turn(int** board, int player) {
    // returns 0 when the game is over otherwise 1
    int x = 0, y = 0;
    do{
        printf("\n(%c) ist am Zug\n", chooseCharacter(player));
        printf("X=");
        scanf("%d", &x);
        printf("Y=");
        scanf("%d", &y);
        if(x < 0 || x > BOARD_SIZE - 1 || y < 0 || y > BOARD_SIZE - 1)
            printf("Eingabe ungültig x, y muss zwischen 0 und 2 liegen");
        else
            if(board[y][x] != EMPTY)
                printf("Die Stelle ist belegt");
            else 
                break;
    }while(1);
    board[y][x] = player;
    return checkWinner(board);
}


char chooseCharacter(int val) {
    if(val == X)
        return 'X';
    else if (val == O)
        return '0';
    else 
        return ' ';
}

void clearBoard() {
    printf("\n\n\n");
    //printf("\e[1;1H\e[2J");  // clear screen on ANSI    
}

void renderBoard(int** board) {
    clearBoard();
    int i, j;
    char cur;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            //printf("arr[%d, %d] = %d", i, j, board[i][j]);
            cur = chooseCharacter(board[i][j]);
            if(j == BOARD_SIZE - 1)
                printf(" %c ", cur);
            else
                printf(" %c  |", cur);
        }
        printf("\n --- ---- ---\n");
    }

}

int main() {
    int x = 0;
    int currentPlayer = PLAYER_X, winner = 0;
    int** board = createBoard();
    renderBoard(board);
    while((winner = turn(board, currentPlayer)) == 0 ) {
        renderBoard(board);
        currentPlayer = currentPlayer == PLAYER_X ? PLAYER_CIRCLE : PLAYER_X;
        x++;
        if(x == 9){
            printf("No winner");
            free(board);
            return 1;
        }
    }
    renderBoard(board);
    free(board);
    return 1;
}