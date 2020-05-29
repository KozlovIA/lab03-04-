#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct input {
vector<double> numbers;
size_t bin_count;
size_t number_count;
};
input read_input(istream& in, bool prompt);
void find_minmax(const vector<double>& numbers, size_t count, double& min, double& max);
vector<double> input_numbers(istream& in, size_t count);
vector<size_t> make_histogram(struct input);
void show_histogram_text(vector<size_t> bins, const vector<double> numbers, size_t number_count, size_t bin_count);
input download(const string& address);


#endif // HISTOGRAM_H_INCLUDED
