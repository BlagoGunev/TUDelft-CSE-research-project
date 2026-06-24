#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = (int)5e5 + 7;

int n;
LL m, c, c0;

struct Friend {
    LL t, a, b;
    void read() {
        scanf("%lld%lld%lld", &t, &a, &b);
    }
    bool operator < (const Friend &rhs) const {
        return t < rhs.t;
    }
} f[N];

LL go() {
    LL cost = 0; LL have = 0;
    map<LL, LL> M;
    for(int i = 1; i < n; i++) {
        LL t = f[i].t, a = f[i].a, b = f[i].b;
        if(have < c && a) {
            LL add = min(a, c - have);
            M[b] += add;
            have += add;
            a -= add;
        }
        while(a && M.size() && M.rbegin()->first > b) {
            auto it = --M.end();
            LL add = min(a, it->second);
            it->second -= add;
            a -= add;
            if(it->second == 0) M.erase(it);
            M[b] += add;
        }
        LL dis = f[i + 1].t - f[i].t;
        while(dis && M.size()) {
            auto it = M.begin();
            LL need = min(dis, it->second);
            dis -= need;
            it->second -= need;
            have -= need;
            cost += 1LL * it->first * need;
            if(it->second == 0) M.erase(it);
        }
        if(dis) return -1;
    }
    return cost;
}
int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%lld%lld%lld", &n, &m, &c, &c0);
        for(int i = 1; i <= n; i++) {
            f[i].read();
        }
        f[++n] = Friend{0, c0, 0};
        f[++n] = Friend{m, 0, 0};
        sort(f + 1, f + 1 + n);
        printf("%lld\n", go());
    }
    return 0;
}

/*
*/