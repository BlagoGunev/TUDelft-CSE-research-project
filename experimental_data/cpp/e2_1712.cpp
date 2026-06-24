#include <iostream>

#include <cstring>

#include <algorithm>

#include <vector>



using namespace std;



const int N = 200010;



typedef long long LL;



inline int read() {

    char c = getchar(); int x = 0, s = 1;

    while (c < '0' || c > '9') { if (c == '-') s = -1; c = getchar();}

    while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}

    return x * s;

}



struct QWQ {

    LL l, r, ans, id;

}q[N];

struct QWQWQ {

    LL x, y, cnt;

}L[N * 50];



int n, t;

vector<int> facts[N];

LL bit[N], ans[N];

int sz[N];



LL lowbit(LL x) {

    return x & -x;

}



void init() {

    for (int i = 3; i < N - 5; i ++ )

        for (int j = 1; j * j <= i; j ++ )

            if (!(i % j)) {

                facts[i].push_back(j);

                sz[i] ++ ;

                if (j * j != i && j != 1) {

                    facts[i].push_back(i / j);

                    sz[i] ++ ;

                }

            }

    for (int i = 3; i < N - 5; i ++ ) sort(facts[i].begin(), facts[i].end());

}



void pre_work() {

    for (int i = 2; i < N - 5; i ++ )

        for (int j = 0; j < sz[i] - 1; j ++ ) {

            L[ ++ t].x = facts[i][j];

            L[t].y = i;

            L[t].cnt = sz[i] - j - 1;

        }

}



int cmp(QWQ a, QWQ b) {

    return a.r == b.r ? a.l < b.l : a.r < b.r;

}



void add(LL pos, LL val) {

    while (pos < N - 5) {

        bit[pos] += val;

        pos += lowbit(pos);

    }

}



LL query(LL pos) {

    LL res = 0;

    while (pos) {

        res += bit[pos];

        pos -= lowbit(pos);

    }

    return res;

}



int main() {

    init();

    

    int T;

    T = read();

    for (int i = 1; i <= T; i ++ ) {

        scanf("%lld%lld", &q[i].l, &q[i].r);

        q[i].ans = (q[i].r - q[i].l + 1) * (q[i].r - q[i].l) / 2 * (q[i].r - q[i].l - 1) / 3

                   - max((LL)0, q[i].r / 6 - (q[i].l - 1) / 3)

                   - max((LL)0, q[i].r / 15 - (q[i].l - 1) / 6);

        q[i].id = i;

    }

    

    pre_work();

    sort(q + 1, q + T + 1, cmp);

    

    int cnt = 1;

    memset(bit, 0, sizeof bit);

    for (int i = 1; i <= T; i ++ ) {

        while (cnt <= t && L[cnt].y <= q[i].r) {

            add(L[cnt].x, L[cnt].cnt);

            cnt ++ ;

        }

        q[i].ans -= query(q[i].r) - query(q[i].l - 1);

    }

    

    for (int i = 1; i <= T; i ++ ) ans[q[i].id] = q[i].ans;

    for (int i = 1; i <= T; i ++ ) printf("%lld\n", ans[i]);

    

    return 0;

}