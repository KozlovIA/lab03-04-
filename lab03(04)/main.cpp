#include <iostream>
#include <vector>
#include <string>
#include "histogram.h"
#include "svg.h"
#include <curl/curl.h>

using namespace std;

int main(int argc, char* argv[])
{
    input inp;
    //curl_global_init(CURL_GLOBAL_ALL);

    if(argc > 1)
    {
        if(*argv[1] == '-' || *argv[2] == '-')
        {
            string check_parametr1 = argv[1];
            string check_parametr2 = argv[2];
            if(check_parametr1 != "-verbose" && check_parametr2 != "-verbose")
         {

            cout << "Error: you must input '-verbose' for continue!" << endl;
            exit(1);
         }
        }
            inp = download(argv[2]);
            CURL *curl = curl_easy_init();
        if(curl)
        {
            CURLcode res;
            curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
            res = curl_easy_perform(curl);
            if(res!=0)
            {
                string error = curl_easy_strerror(res);
                cout << "ERROR: " << error;
                exit(1);
            }
            curl_easy_cleanup(curl);
        }
        }

    else
    {
        inp = read_input(cin, true);
    }
    // Вывод данных
    const auto bins = make_histogram(inp);
   // show_histogram_text(bins, numbers, number_count, bin_count);
    show_histogram_svg(bins, inp);

    return 0;
}
