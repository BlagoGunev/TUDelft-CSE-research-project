#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve01(string s, int x, int y) {
    int now = 0, c0 = 0, c1 = 0;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            now += c1 * x;
            c0++;
        }
        else {
            now += c0 * y;
            c1++;
        }
    }

    int cl0 = 0, cl1 = 0;
    int cr0 = c0, cr1 = c1;
    int ans = now;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            cr1--;
            now -= cl0 * x; // 0 1
            now -= cr0 * y; //   1 0
            now += cl1 * y; // 1 0
            now += cr1 * x; //   0 1
            cl0++;
        }
        else if (s[i] == '0') {
            cl0++;
            cr0--;
        }
        else {
            cl1++;
            cr1--;
        }
        ans = min(ans, now);
    }

    cout << ans;
}

void solve10(string s, int x, int y) {
    int now = 0, c0 = 0, c1 = 0;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            now += c0 * y;
            c1++;
        }
        else {
            now += c1 * x;
            c0++;
        }
    }

    int cl0 = 0, cl1 = 0;
    int cr0 = c0, cr1 = c1;
    int ans = now;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            cr0--;
            now -= cl1 * y; // 1 0
            now -= cr1 * x; //   0 1
            now += cl0 * x; // 0 1
            now += cr0 * y; //   1 0
            cl1++;
        }
        else if (s[i] == '0') {
            cl0++;
            cr0--;
        }
        else {
            cl1++;
            cr1--;
        }
        ans = min(ans, now);
    }

    cout << ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(NULL));
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s; cin >> s;
    int x, y; cin >> x >> y;
    if (x < y)
        solve01(s, x, y);
    else
        solve10(s, x, y);

    return 0;
}

/*
0?1
2 3
-------
4

?????
13 37
-------------------
0


?10?
239 7
-------------------------
28


01101001
5 7
---------------------
96

*/