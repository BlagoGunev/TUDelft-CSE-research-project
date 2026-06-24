#include <cstdio>
#include <set>

using namespace std;

static inline int gi() {
    register int c = getchar();
    int x = 0;
    int neg = 0;

    while ((c<48 || c>57) && c != '-')
        c = getchar();

    if (c=='-') {
        neg = 1; c = getchar();
    }

    for (; c>47 && c<58; c = getchar())
        x = (x<<1) + (x<<3) + c - 48;

    if(neg)
        x = -x;

    return x;
}

int
main()
{
    int n = gi(), k = gi();
    set<int> p; p.insert(0);
    set<int> s; s.insert(0);
    for (int i = 0; i < n; ++i) {
        int x = gi();
        int c1 = -*p.lower_bound(-x);
        int c2 = -*s.lower_bound(-x);
        int r;
        //printf("%d %d %d\n", x, c1, c2);
        if (x - c1 < k) {
            r = c1;
        } else if (x - c2 < k) {
            r = c2 + 1;
            p.insert(-r);
        } else {
            r = x - k + 1;
            p.insert(-r);
        }
        s.insert(-x);
        printf("%d ", r);
    }
    printf("\n");
    return 0;
}