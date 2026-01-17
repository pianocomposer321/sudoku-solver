#ifndef BOARD_
#define BOARD_

#define BOARD_STRIDE 9
#define BOARD_LENGTH (BOARD_STRIDE*BOARD_STRIDE)

typedef char Board[BOARD_LENGTH];

#define IND(row, col) (BOARD_STRIDE*row + col)

char board_at(Board board, size_t row, size_t col);
size_t board_ind_in_square(size_t square, size_t n);
char board_at_in_square(Board board, size_t square, size_t n);

void print_board(Board board);

#endif // BOARD_
