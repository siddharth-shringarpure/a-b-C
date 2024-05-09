// Define constants

#define ROWS 3
#define COLS 3

int main() {

    // Create board
    char board[ROWS][COLS];

    // Initialise board

    for (int row=0; row < ROWS; row++) {
        for (int col=0; col < COLS; col++) {
            board[row][col] = ' ';
        }
    }

    return 0;

}