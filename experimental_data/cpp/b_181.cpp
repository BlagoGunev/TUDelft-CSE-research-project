#include <bits/stdc++.h>

#define pii pair<int,int>

#define mp make_pair

#define F first

#define S second

using namespace std;

pii a[3100];

int iabs(int x) {

    return max(x, -x);

}

int gcd(int a, int b) {

    return (b == 0) ? a : gcd(b, a % b);

}

bool m[2010][2010];

int main() {

    int n; cin >> n;

    int i, j;

    for (i = 0; i < n; i++) {

        cin >> a[i].F >> a[i].S;

        a[i].F += 1000, a[i].S += 1000;

        m[a[i].F][a[i].S] = true;

    }

    sort(a, a + n);

    int ans = 0, mx, my;

    for (i = 0; i < n - 1; i++) {

        for (j = i + 1; j < n; j++) {

            mx = (a[i].F + a[j].F), my = (a[i].S + a[j].S);

            if (mx % 2 || my % 2) continue;

            if (m[mx / 2][my / 2]) ans++;

        }

    }

    cout << ans << '\n';

    return 0;

}