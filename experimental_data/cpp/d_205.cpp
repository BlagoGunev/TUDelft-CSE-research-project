#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

pair<int, int> colors[2 * 100005];
int best = 1000000001;
int main() {
    int d;
    scanf("%d", &d);
    int goal = (d + 1) / 2;
    for (int i=0; i<d; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == b) b = 1000000001;
        colors[2*i] = make_pair(a, 0);
        colors[2*i + 1] = make_pair(b, 1);
    }
    sort(colors, colors + 2*d);
    colors[2*d] = make_pair(-1, -1);

    for (int i=0; i<2*d; ++i) {
        int end = i;
        int nf = 0, nb = 0;
        if (colors[i].first >= 1000000001) continue;
        while (colors[end].first == colors[i].first) {
            if (colors[end].second == 0) nf++;
            else nb++;
            end++;
        }
        if (nf + nb >= goal) {
            best = min(best, max(0, goal - nf));
        }
        i = end-1;
    }
    if (best == 1000000001) {
        printf("-1\n");
    }
    else {    
        printf("%d\n", best);
    }

    return 0;
}