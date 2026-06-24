#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int h1, a1, c1;
    int h2, a2;
    int d, h, m, i, heals, strikes;

    scanf("%d%d%d", &h1, &a1, &c1);
    scanf("%d%d", &h2, &a2);
    d = 0; h = 1000000;
    while(d < h){
        m = (d + h) / 2;
        if(ceil((h1 + m * (c1 - a2)) * 1.0 / a2) >= ceil(h2 * 1.0 / a1))
            h = m;
        else
            d = m + 1;
    }
    
    heals = d;
    strikes = ceil(h2 * 1.0 / a1);
    printf("%d\n", heals + strikes);
    for(i = 0; i < d; ++i)
        printf("HEAL\n");
    for(i = 0; i < ceil(h2 * 1.0 / a1); ++i)
        printf("STRIKE\n");

    return 0;
}