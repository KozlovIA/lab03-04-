#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void find_minmax(const vector<double>& numbers, size_t count, double& min, double& max);
vector<double> input_numbers(size_t count);
vector<size_t> make_histogram(const vector<double> numbers, size_t number_count, size_t bin_count);
void show_histogram_text(vector<size_t> bins, const vector<double> numbers, size_t number_count, size_t bin_count);
void svg_begin(double width, double height);
void svg_end();
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black");
void svg_text(double left, double baseline, string text);
void show_histogram_svg(const vector<size_t>& bins, size_t bin_count);

#endif // HISTOGRAM_H_INCLUDED
