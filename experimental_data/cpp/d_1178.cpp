// qdd on Jul 21, 2019

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool isprime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int get(int n) {
    int rt = n;
    while (!isprime(rt)) ++rt;
    return rt;
}

int d[1007], tot;

void add(int u, int v) {
    d[u]++, d[v]++, tot++;
    cout << u << ' ' << v << '\n';
}
int main() {
    int n;
    cin >> n;
    int ecnt = get(n);
    cout << ecnt << '\n';
    for (int i = 1; i < n; i++) {
        add(i, i + 1);
    }
    add(1, n);
    for (int i = 1; i + 2 <= n; i++) {
        if (tot == ecnt) break;
        if (d[i] == 2 && d[i + 2] == 2) add(i, i + 2);
    }
    return 0;
}