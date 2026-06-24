#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

char x0, y0, x1, y1, i;

int main() {
    x0 = getchar();
    y0 = getchar();
    getchar();
    x1 = getchar();
    y1 = getchar();
    printf("%d\n", max(abs(x0 - x1),abs(y0 - y1)));
    while(x0 != x1 || y0 != y1) {
        if(x0 != x1) {
            if(x1 - x0 > 0) { putchar('R'); } else { putchar('L'); }
            x0 += (x1 - x0) / abs(x1 - x0); }
        if(y0 != y1) {
            if(y1 - y0 > 0) { putchar('U'); } else { putchar('D'); }
            y0 += (y1 - y0) / abs(y1 - y0); }
        putchar('\n'); }
    return 0; }