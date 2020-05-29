#include <iostream>
#include <vector>
#include <string>
#include "histogram.h"
using namespace std;

void find_minmax(const vector<double>& numbers, size_t count, double& min, double& max) {
    min = numbers[0];
    max = numbers[0];
    for (int i=0; i < count; i++)
    {
        if (numbers[i] < min)
        {
            min = numbers[i];
        }
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }
}
vector<double>
input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}
vector<size_t>
make_histogram(const vector<double> numbers, size_t number_count, size_t bin_count) {
    double min, max;
    find_minmax(numbers, number_count, min, max);
    vector<size_t> bins(bin_count);
    for (int i = 0; i < number_count; i++)
    {
        size_t bin = (size_t)((numbers[i] - min) / (max - min) * bin_count);
        if (bin == bin_count)
        {
            bin--;
        }
        bins[bin]++;
    }
    return bins;
}
void
show_histogram_text(vector<size_t> bins, const vector<double> numbers, size_t number_count, size_t bin_count) {
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;

    size_t max_count = 0;
    for (int i=0; i < bin_count; i++)
    {
        if (bins[i] > max_count)
        {
            max_count = bins[i];
        }
    }
    const bool scaling_needed = max_count > MAX_ASTERISK;

    for (int i=0; i < bin_count; i++)
    {
        if (bins[i] < 100)
        {
            cout << ' ';
        }
        if (bins[i] < 10)
        {
            cout << ' ';
        }
        cout << bins[i] << "|";

        size_t height = bins[i];
        if (scaling_needed)
        {
            const double scaling_factor = (double)MAX_ASTERISK / max_count;
            height = (size_t)(bins[i] * scaling_factor);
        }

        for (size_t i = 0; i < height; i++)
        {
            cout << '*';
        }
        cout << '\n';
    }
}
