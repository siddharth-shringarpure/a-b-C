#include <stdio.h>
// Define constants

#define ROWS 3
#define COLS 3

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

    // Initialise board

    for (int row=0; row < ROWS; row++) {
        for (int col=0; col < COLS; col++) {
            board[row][col] = ' ';
        }
    }

    char player = 'X';
    int game_over = 0;


    while (!game_over) {
        // Print the board

        printf("Player %c, enter grid position (1-9): ", player);

        // Accept user input

        int chosen_square;

        scanf("%d", &chosen_square);

        // Validate grid position, then assign player

        if (chosen_square >=1 && chosen_square <= 9) {
            int* coords = coordConverter(chosen_square);

            if (board[coords[0]][coords[1]] == ' ') {
                board[coords[0]][coords[1]] = player;
            }

            else {
                printf("Square is occupied, try again\n");
            }
        }

        else {
            printf("Invalid location, try again\n");
        }

        // Temporary, to terminate loop

        player = '1';

//        game_over = 1;

    }

    return 0;

}