#include <iostream>
#include <vector>
#include <string>
#include "histogram.h"
#include "svg.h"


using namespace std;

int main()
{
    // Print example
    const char* name = "Commander Shepard";
    int year = 2154;
    printf("%s was born in %d.\n", name, year);
    printf("n = %08x\n", 0x1234567);
    return 0;

    // Ввод данных
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    const auto numbers = input_numbers(number_count);
    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;

    // Вывод данных
    const auto bins = make_histogram(numbers, number_count, bin_count);
   // show_histogram_text(bins, numbers, number_count, bin_count);
   show_histogram_svg(bins, bin_count);

    return 0;
}
