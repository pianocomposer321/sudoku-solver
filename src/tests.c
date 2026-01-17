#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>

#include "board.h"
#include "strategies.h"

void test_full_house_square(void)
{
  Board board = "8..739..637.465....4.182..9...6...4..543..61..6.5.....4..853.7....271.641..94...2";
  size_t pos;
  bool res = full_house_p(board, &pos);
  assert(res && pos == 77);
}

void test_full_house_row(void)
{
  Board board = "2.7.......8..9.....3.6..8....8.649..6927853.4..132.5....9..1.2.....4..9.......4.8";
  size_t pos;
  bool res = full_house_p(board, &pos);
  assert(res);
}

int main(void)
{
  test_full_house_square();
  test_full_house_row();
  return 0;
}
