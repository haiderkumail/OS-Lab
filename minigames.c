#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Define colors for better visualization
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"

// Define symbols for cells
#define SYMBOL_UNREVEALED  "."
#define SYMBOL_MINE        "*"
#define SYMBOL_FLAG        "F"
#define SYMBOL_EMPTY       " "
#define SYMBOL_REVEALED    " "

// Define cell states
#define STATE_UNREVEALED  0
#define STATE_REVEALED    1
#define STATE_FLAGGED     2

// Define cell colors
#define COLOR_REVEALED    ANSI_COLOR_WHITE
#define COLOR_MINE        ANSI_COLOR_RED
#define COLOR_FLAG        ANSI_COLOR_YELLOW
#define COLOR_EMPTY       ANSI_COLOR_GREEN
#define COLOR_DEFAULT     ANSI_COLOR_RESET

int rows, cols;
int num_mines;
int grid[100][100];
int state[100][100];

void initialize() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = 0;
            state[i][j] = STATE_UNREVEALED;
        }
    }
}

void printGrid() {
    printf("    ");
    for (int i = 0; i < cols; i++)
        printf("%d ", i);
    printf("\n");
    printf("   ");
    for (int i = 0; i < cols * 2 + 1; i++)
        printf("-");
    printf("\n");

    for (int i = 0; i < rows; i++) {
        printf("%2d| ", i);
        for (int j = 0; j < cols; j++) {
            if (state[i][j] == STATE_UNREVEALED) {
                printf(ANSI_COLOR_CYAN SYMBOL_UNREVEALED ANSI_COLOR_RESET " ");
            } else if (state[i][j] == STATE_FLAGGED) {
                printf(ANSI_COLOR_YELLOW SYMBOL_FLAG ANSI_COLOR_RESET " ");
            } else {
                if (grid[i][j] == -1) {
                    printf(ANSI_COLOR_RED SYMBOL_MINE ANSI_COLOR_RESET " ");
                } else if (grid[i][j] == 0) {
                    printf(ANSI_COLOR_GREEN SYMBOL_EMPTY ANSI_COLOR_RESET " ");
                } else {
                    printf(COLOR_REVEALED "%d " ANSI_COLOR_RESET, grid[i][j]);
                }
            }
        }
        printf("\n");
    }
}

void placeMines(int x, int y) {
    srand(time(NULL));
    int count = 0;
    while (count < num_mines) {
        int r = rand() % rows;
        int c = rand() % cols;
        if (grid[r][c] == 0 && !(r == x && c == y)) {
            grid[r][c] = -1;
            count++;
        }
    }
}

int countAdjacentMines(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int newX = x + i;
            int newY = y + j;
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                if (grid[newX][newY] == -1)
                    count++;
            }
        }
    }
    return count;
}

void reveal(int x, int y) {
    if (x < 0 || x >= rows || y < 0 || y >= cols || state[x][y] == STATE_REVEALED)
        return;

    state[x][y] = STATE_REVEALED;

    if (grid[x][y] == 0) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int newX = x + i;
                int newY = y + j;
                reveal(newX, newY);
            }
        }
    }
}

void flagCell(int x, int y) {
    if (state[x][y] == STATE_UNREVEALED) {
        state[x][y] = STATE_FLAGGED;
    } else if (state[x][y] == STATE_FLAGGED) {
        state[x][y] = STATE_UNREVEALED;
    }
}

bool checkWin() {
    int unrevealed_count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (state[i][j] == STATE_UNREVEALED)
                unrevealed_count++;
        }
    }
    return unrevealed_count == num_mines;
}

int main() {
    printf("Welcome to Minesweeper!\n");

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    printf("Enter number of mines: ");
    scanf("%d", &num_mines);

    initialize();
    
    int x, y;
    printf("Enter row and column to start (separated by space): ");
    scanf("%d %d", &x, &y);

    placeMines(x, y);

    while (1) {
        printGrid();

        int action, row, col;
        printf("Enter action (0 - reveal, 1 - flag): ");
        scanf("%d", &action);

        printf("Enter row and column (separated by space): ");
        scanf("%d %d", &row, &col);

        if (action == 0) {
            if (grid[row][col] == -1) {
                printf("Game Over! You hit a mine!\n");
                state[row][col] = STATE_REVEALED;
                printGrid();
                break;
            } else {
                reveal(row, col);
                if (checkWin()) {
                    printf("Congratulations! You won!\n");
                    printGrid();
                    break;
                }
            }
        } else if (action == 1) {
            flagCell(row, col);
        } else {
            printf("Invalid action! Please try again.\n");
        }
    }

    return 0;
}
