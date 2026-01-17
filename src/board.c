#include <stdio.h>

#include "board.h"

char board_at(Board board, size_t row, size_t col)
{
  return board[IND(row, col)];
}

// TODO: this assumes that BOARD_STRIDE and BOARD_LENGTH are as definied above
inline size_t board_ind_in_square(size_t square, size_t n)
{
  size_t row_of_square = square / 3;
  size_t first_cell_in_square = row_of_square * 27 + (square % 3) * 3;
  return first_cell_in_square + n % 3 + (n / 3) * 9;
}

inline char board_at_in_square(Board board, size_t square, size_t n)
{
  return board[board_ind_in_square(square, n)];
}

void print_board(Board board)
{
  for (size_t row = 0; row < BOARD_STRIDE; row++) {
    if (row % 3 == 0) printf("-------------------------\n");
    for (size_t col = 0; col < BOARD_STRIDE; col++) {
      if (col % 3 == 0) printf("| ");
      printf("%c ", board_at(board, row, col));
    }
    printf("|\n");
  }
  printf("-------------------------\n");
}
