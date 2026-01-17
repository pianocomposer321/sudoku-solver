#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
  uint16_t mask = 0b111111111;
  const char *board = "923.56781";

  for (size_t i = 0; i < 9; i++) {
    char c = board[i];
    if (isdigit(c)) {
      mask &= ~(1 << (c - '0'));
    }
  }

  printf("%d\n", mask);
  printf("%d\n", (int)log2(mask));
}
