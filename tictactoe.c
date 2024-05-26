#include <stdio.h>
// Define constants

#define ROWS 3
#define COLS 3

void printBoard(char board[ROWS][COLS]) {
    printf("\n--------------\n");
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            printf(" %c | ", board[r][c]);
        }
        printf("\n--------------\n");
    }
}

int hasWon(char board[ROWS][COLS], char player) {

    int player_won = 1;

    // Check rows
    for (int row=0; row<ROWS; row++) {
        player_won = 1;
        for (int col=0; col<COLS; col++) {
            if (board[row][col] != player) {
                player_won = 0;
                break;
            }
        }

        if (player_won) {
            return 1;
        }
    }

    // Check columns
    for (int col=0; col<COLS; col++) {
        player_won = 1;
        for (int row=0; row<ROWS; row++) {
            if (board[row][col] != player) {
                player_won = 0;
                break;
            }
        }

        if (player_won) {
            return 1;
        }
    }

    // Check leading diagonal
    for (int i=0; i<ROWS; i++) {
        player_won = 1;

        if (board[i][i] != player) {
            player_won = 0;
            break;
        }
    }

    if (player_won) {
        return 1;
    }

    // Check trailing diagonal
    player_won = 1;
    int row = 0, col = COLS - 1;

    while (row < ROWS && col >= 0) {
        if (board[row][col] != player) {
            player_won = 0;
            break;
        }
        row++;
        col--;
    }

    if (player_won) {
        return 1;
    }

    return 0;
}

int isDraw(char board[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == ' ') {
                return 0;
            }
        }
    }
    return 1;  // Only a draw if the entire grid is filled
}

int* coordConverter(int c) {
    static int conv_coords[2];  // Static to preserve scope beyond func. call

    // Convert single coordinate [1,9] into a pair of coordinates to represent row/col
    // eg: 8 becomes [2][1]

    conv_coords[0] = (c - 1) / 3;
    conv_coords[1] = (c - 1) % 3;

    return conv_coords;
}

int main() {

    // Create board
    char board[ROWS][COLS];

    // Create players
    int players[2] = {'X', 'O'};
    int *curr_player = &players[0];  // First player is 'X'

    // Initialise board

    for (int row=0; row < ROWS; row++) {
        for (int col=0; col < COLS; col++) {
            board[row][col] = ' ';
        }
    }

    int game_over = 0;

    while (!game_over) {

        // Print the board
        printBoard(board);

        printf("Player %c, enter grid position (1-9): ", *curr_player);

        // Accept user input

        int chosen_square;

        if (scanf("%d", &chosen_square) != 1 || chosen_square < 1 || chosen_square > 9) {
            printf("Invalid location, try again\n");
            while (getchar() != "\n");  // Clear stdin input buffer to prevent unexpected behaviour
            continue;
        }

        // Validate grid position, then assign player

        int* coords = coordConverter(chosen_square);

        if (board[coords[0]][coords[1]] == ' ') {
            board[coords[0]][coords[1]] = *curr_player;


            if (hasWon(board, *curr_player)) {
                printBoard(board);
                printf("Player %c has won!", *curr_player);
                game_over = 1;
            }

            else if (isDraw(board)) {
                printBoard(board);
                printf("It's a draw!");
                game_over = 1;
            }

            else {
                // Swap the current player using bitwise XOR operator on curr_player's index in array
                curr_player = &players[1 ^ (curr_player - &players[0])];
            }
        }

        else {
            printf("Square is occupied, try again\n");
        }

    }

    return 0;

}