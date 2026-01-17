#ifndef STRATEGIES_
#define STRATEGIES_

#include <stdbool.h>

// Checks if there is any square with only one empty cell.
// If so, fills in that last cell and returns true.
// If not, returns false.
// The *_p version sets *pos to the position that was changed, if any.
bool full_house(Board board);
bool full_house_p(Board board, size_t *pos);

#endif // STRATEGIES_
