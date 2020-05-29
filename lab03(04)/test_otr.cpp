#include "histogram.h"
#include <cassert>

void
test_otr() {
    cout << "Enter 3 numbers ";
    auto numbers = input_numbers(3);
    assert(numbers[0] < 0);
    assert(numbers[1] < 0);
    assert (numbers[2] < 0);
}

int
main() {
    test_otr();
    return 0;
}
