#include "histogram.h"
#include <cassert>

void
test_odinakovie_chisla() {
    cout << "Enter 3 numbers ";
    auto numbers = input_numbers(3);
    for (int i = 0; i < 3-1; i++) {
     assert(numbers[i] == numbers[i+1]);

    }
}

int
main() {
    test_odinakovie_chisla();
    return 0;
}
