#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "strategies.h"

int main(void) {
  Board board = "9..5.8..7.8.3.29.5.54....8..7.68..321....4..85..219.6....9.6..1726..1.4...147..56";
  print_board(board);
  printf("%d\n", full_house(board));
  print_board(board);
}
