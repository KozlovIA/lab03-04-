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
    int checker = 0;
    int checker_http = -1;
    if(argc > 1)
    {
        for(int i=0; i<argc; i++)
        {
            if(*argv[i] == '-')
            {
                string check_parametr = argv[i];
                if(check_parametr == "-verbose")
                {
                    checker = 1;


                }
                else {
                    cout << "Error: you must input '-verbose' for continue!" << endl;
                    exit(1);
                }
            }
        for(int i=0; i<argc; i++)
        {
            if(*argv[i] == 'h')
            {
                checker_http = i;
            }
        }
        }
    }

        if(checker==1)
        {
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
    // Ввод данных
    if(checker_http > -1)
            {
            inp = download(argv[checker_http]);
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
