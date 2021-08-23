#include "../include/client.h"

int main() {
    client_square_eq();

#ifdef UNIT_TEST
    test_square_eq();
#endif

    return 0;
}
