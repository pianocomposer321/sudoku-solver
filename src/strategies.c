#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

#include "board.h"

bool full_house_p(Board board, size_t *pos)
{
  // Squares
  for (size_t square = 0; square < BOARD_STRIDE; square++) {
    bool found_digits[BOARD_STRIDE] = {0};
    bool found_empty_cell = false;
    size_t empty_cell_ind = 0;

    bool quit = false;
    for (size_t cell = 0; cell < BOARD_STRIDE; cell++) {
      char c = board_at_in_square(board, square, cell);

      if (isdigit(c)) {
        found_digits[c - '0' - 1] = true;
      } else {
        if (found_empty_cell) {
          quit = true;
          break;
        }
        found_empty_cell = true;
        empty_cell_ind = cell;
      }
    }

    if (quit) continue;

    if (found_empty_cell) {
      for (size_t i = 0; i < BOARD_STRIDE; i++) {
        if (!found_digits[i]) {
          size_t pos_ = board_ind_in_square(square, empty_cell_ind);
          board[pos_] = i + '0' + 1;
          if (pos != NULL) {
            *pos = pos_;
          }
          return true;
        }
      }
    }
  }

  // Rows
  for (size_t row = 0; row < BOARD_STRIDE; row++) {
    bool found_digits[BOARD_STRIDE] = {0};
    bool found_empty_cell = false;
    size_t empty_cell_col = 0;

    bool quit = false;
    for (size_t cell = 0; cell < BOARD_STRIDE; cell++) {
      char c = board_at(board, row, cell);

      if (isdigit(c))
        found_digits[c - '0' - 1] = true;
      else {
        if (found_empty_cell) {
          quit = true;
          break;
        }
        found_empty_cell = true;
        empty_cell_col = cell;
      }
    }

    if (quit) continue;

    if (found_empty_cell) {
      for (size_t i = 0; i < BOARD_STRIDE; i++) {
        if (!found_digits[i]) {
          // size_t pos_ = board_at(board, row, empty_cell_col);
          size_t pos_ = IND(row, empty_cell_col);
          board[pos_] = i + '1';
          if (pos != NULL) {
            *pos = pos_;
          }
          return true;
        }
      }
    }
  }

  // Columns
  for (size_t col = 0; col < BOARD_STRIDE; col++) {
    bool found_digits[BOARD_STRIDE] = {0};
    bool found_empty_cell = false;
    size_t empty_cell_row = 0;

    bool quit = false;
    for (size_t cell = 0; cell < BOARD_STRIDE; cell++) {
      char c = board_at(board, cell, col);

      if (isdigit(c))
        found_digits[c - '0' - 1] = true;
      else {
        if (found_empty_cell) {
          quit = true;
          break;
        }
        found_empty_cell = true;
        empty_cell_row = cell;
      }
    }

    if (quit) continue;

    if (found_empty_cell) {
      for (size_t i = 0; i < BOARD_STRIDE; i++) {
        if (!found_digits[i]) {
          // size_t pos_ = board_at(board, col, empty_cell_row);
          size_t pos_ = IND(empty_cell_row, col);
          board[pos_] = i + '1';
          if (pos != NULL) {
            *pos = pos_;
          }
          return true;
        }
      }
    }
  }

  return false;
}

bool full_house(Board board)
{
  return full_house_p(board, NULL);
}
