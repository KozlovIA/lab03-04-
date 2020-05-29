#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
void svg_begin(double width, double height);
void svg_end();
void svg_rect(double x, double y, double width, double height, string stroke, string fill);
void svg_text(double left, double baseline, string text);
double sred_visota(vector<size_t> bins, size_t bin_count);
void show_histogram_svg(const vector<size_t>& bins, size_t bin_count);


#endif // SVG_H_INCLUDED
