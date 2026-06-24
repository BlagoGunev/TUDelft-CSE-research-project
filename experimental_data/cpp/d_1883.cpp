#include<bits/stdc++.h>
#define int long long
#define iosbase ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

struct Node {
    int s, z, w;
};

struct Q {
    char c;
    int a, b;
};

const int N = 2e6 + 6;

int n = N, q;
Node smt[N << 2];
set<int> ss;

void down(int k) {
    int z = smt[k].z;

    smt[k * 2].s += z;
    smt[k * 2].z += z;
    
    smt[k * 2 + 1].s += z;
    smt[k * 2 + 1].z += z;

    smt[k].z = 0;
}

void lazy(int x, int y, int l, int r, int z, int k) {
    if (r < x || y < l) return;
    if (l <= x && y <= r) {
        smt[k].s += z;
        smt[k].z += z;
        return;
    }

    int m = (x + y) >> 1;
    down(k);

    lazy(x, m, l, r, z, k * 2);
    lazy(m + 1, y, l, r, z, k * 2 + 1);

    smt[k].s = max(smt[k * 2].s, smt[k * 2 + 1].s);
}

int query(int x, int y, int l, int r, int k) {  
    if (r < x || y < l) return 0;
    if (l <= x && y <= r) 
        return smt[k].s;

    int m = (x + y) >> 1;
    down(k);
    
    return max(query(x, m, l, r, k * 2), 
            query(m + 1, y, l, r, k * 2 + 1));
}

vector<Q> queries;
unordered_map<int, int> cpr;

signed main() {
    iosbase;
    cin >> q;

    int cnt = 0;

    while (q--) {
        char c; int l, r;
        cin >> c >> l >> r;
        queries.push_back({c, l, r});
        ss.insert(l);
        ss.insert(r);
    }

    int c = 0;
    for (auto it : ss)
        cpr[it] = c++;

    for (auto qr : queries) {
        char c = qr.c; int l = qr.a, r = qr.b;
        l = cpr[l], r = cpr[r];
        if (c == '+') {
            lazy(0, n - 1, l, r, 1, 1);
            cnt++;
        } else {
            lazy(0, n - 1, l, r, -1, 1);
            cnt--;
        }
        int intersect = query(0, n - 1, 0, n - 1, 1);
        cout << (cnt == intersect ? "NO" : "YES") << '\n';
    }
}