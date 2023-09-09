#include <stdio.h>

#define ROWS 5
#define COLS 5

int matrix[ROWS][COLS];

// Function to check if the player can pass
int canPlayerPass(int x, int y, int exitX, int exitY) {
    // Check boundaries and conditions
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS || matrix[x][y] == 1) {
        return 0; // Cannot pass through obstacles or out of bounds
    }

    if (x == exitX && y == exitY) {
        return 1; // Player reached the exit
    }

    // Mark the current cell as visited
    matrix[x][y] = 1;

    // Recursively check adjacent cells
    if (canPlayerPass(x + 1, y, exitX, exitY) || // Right
        canPlayerPass(x - 1, y, exitX, exitY) || // Left
        canPlayerPass(x, y + 1, exitX, exitY) || // Down
        canPlayerPass(x, y - 1, exitX, exitY)) { // Up
        return 1; // Player can pass through
    }

    return 0; // Player cannot pass through
}

int main() {
    // Initialize the matrix (0 represents pen path, 1 represents obstacle)
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix[i][j] = 0; // Initialize all cells to open path
        }
    }

    // Place obstacles (1) in the matrix
    matrix[0][2] = 1;
    matrix[1][2] = 1;
    matrix[2][2] = 1;
    matrix[3][2] = 1;
    matrix[4][2] = 1;

    // Set player's starting position and exit point
    int startX = 0;
    int startY = 0;
    int exitX = 4;
    int exitY = 4;

    // Check if the player can pass
    if (canPlayerPass(startX, startY, exitX, exitY)) {
        printf("Player can pass from (%d, %d) to (%d, %d).\n", startX, startY, exitX, exitY);
    } else {
        printf("Player cannot pass from (%d, %d) to (%d, %d).\n", startX, startY, exitX, exitY);
    }

    return 0;
}

