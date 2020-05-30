#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <sstream>
#include "histogram.h"
using namespace std;


void
svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}
void
svg_end() {
    cout << "</svg>\n";
}
void svg_rect(double x, double y, double width, double height, string stroke, string fill) {
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << stroke << "' fill='" << fill << "' />";
}
void
svg_text(double left, double baseline, string text) {
     cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>";

}
double sred_visota(vector<size_t> bins, size_t bin_count)                // изменения к Д/З вариваент 7. Добавлена функция sred_visota
{
    double sred_visota;
    for(int i=0; i < bin_count; i++){
        sred_visota=sred_visota+bins[i];
    }
    return sred_visota/bin_count;
}
void
show_histogram_svg(const vector<size_t>& bins, size_t bin_count)
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top=0;
    for (size_t i=0; i < bin_count; i++)
    {
        const double bin_width = BLOCK_WIDTH * bins[i];
        svg_text(TEXT_LEFT, top+TEXT_BASELINE, to_string(bins[i]));
        cout << endl;
        if (bins[i] > sred_visota(bins, bin_count))                                          // изменения к Д/З вариваент 7. добавлено if
        {
            svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "black", "red");
            cout << endl;
        }
        else
        {
            svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "black", "green");
            cout << endl;
        }

        top+=BIN_HEIGHT;
    }
    svg_end();
}

string
make_info_text()
{
    stringstream buffer;


    return buffer.str();
}
