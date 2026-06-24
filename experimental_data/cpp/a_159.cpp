#include <iostream>
#include <string.h>

struct line_t {
    char from[21], to[21];
    int t;
};

struct result_line_t {
    char *from, *to;
};

int main()
{
    int n, d;
    line_t lines[1000];
    result_line_t result_lines[1000];
    int results_count = 0;
    std::cin >> n >> d;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> lines[i].from >> lines[i].to >> lines[i].t;
        int j;
//        std::cout << "++ " << lines[i].from << ' ' << lines[i].to << '\n';
        for (j = 0; j < results_count; ++j)
        {
//            std::cout << result_lines[j].from << ' ' << result_lines[j].to << '\n';
            if ((strcmp(lines[i].from, result_lines[j].to) == 0 && strcmp(lines[i].to, result_lines[j].from) == 0) ||
                (strcmp(lines[i].from, result_lines[j].from) == 0 && strcmp(lines[i].to, result_lines[j].to) == 0))
            {
//                std::cout << "BREAK\n";
                break;
            }
        }
//        std::cout << "==========\n";
        if (j == results_count)
        {
            for (j = i - 1; (j >= 0) && ((lines[i].t - lines[j].t) <= d); --j)
            {
                if ((lines[i].t - lines[j].t) == 0)
                    continue;
                if ((strcmp(lines[i].from, lines[j].to) == 0 && strcmp(lines[i].to, lines[j].from) == 0))
                {
                    result_lines[results_count].from = lines[i].from;
                    result_lines[results_count].to = lines[i].to;
                    ++results_count;
                    break;
                }
            }
        }
    }
    std::cout << results_count << '\n';
    for (int i = 0; i < results_count; ++i)
        std::cout << result_lines[i].from << " " << result_lines[i].to << '\n';

    return 0;
}