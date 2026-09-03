#include "mymath.h"
#include <assert.h>

int main(void) {
    assert(add(2, 3) == 6);
    assert(subtract(5, 3) == 2);
    assert(multiply(4, 3) == 12);

    return 0;
}
