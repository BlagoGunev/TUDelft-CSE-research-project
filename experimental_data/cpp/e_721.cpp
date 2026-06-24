#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e5 + 10;
int qdist[Maxn], qans[Maxn];
int l, n, p, t;
void update(int x, int y, int &tdist, int &tans, int d, int a) {
    int cnt = (y - max(x, d + t)) / p;
    a += cnt;
    d = max(x, d + t) + cnt * p;
    if(a > tans || (a == tans && d < tdist))
    {
        tans = a;
        tdist = d;
    }
}
#define QAQ main
int QAQ() {
    scanf("%d%d%d%d", &l, &n, &p, &t);
    int front = 0, tail = 0, ans = 0;
    qdist[tail] = -t;
    qans[tail] = 0;
    ++tail;
    int x, y, tdist, tans;
    while(n--) {
        scanf("%d%d", &x, &y);
        tdist = y;
        tans = 0;
        front = max(front - 1, 0);
        while(front < tail) {
            if(qdist[front] + t + p > y)
                break;
            update(x, y, tdist, tans, qdist[front], qans[front]);
            ++front;
        }
        if(ans < tans) {
            ans = tans;
            qdist[tail] = tdist;
            qans[tail] = tans;
            ++tail;
        }
     }
     printf("%d\n", ans);
}