#include <bits/stdc++.h>

using namespace std;



#ifdef LOCAL

    #include "debug.h" 

#endif



#define int long long int

const int mod = 1e9 + 7, inf = 1e18;



vector<pair<int, int>> ops;

vector<int> a;

 

void rec(int n, int coeff) {

    if (n <= 2) {

        for (int i = 1; i <= n; i++)

            a.emplace_back(i * coeff);

        return;

    }

 

    int p = 1;

    while (p * 2 <= n) p *= 2;

 

    if (p == n) {

        a.emplace_back(n * coeff);

        n--, p /= 2;

    }

 

    a.emplace_back(p * coeff);

    for (int i = p + 1; i <= n; i++) {

        a.emplace_back(2 * p * coeff);

        ops.emplace_back(i * coeff, (2 * p - i) * coeff);

    }

 

    rec(2 * p - n - 1, coeff);

    rec(n - p, coeff * 2);

    

    return;

}

 

void solve() {

    int n; cin >> n;

    if (n == 2) { cout << "-1\n"; return; }

 

    ops.clear(); a.clear();

    rec(n, 1);

    sort(a.begin(), a.end());

 

    int answer = 1;

    while (answer < n)  answer *= 2;

 

    for (int i = 0;; i++)

        if (a[i] == a[i + 1]) {

            assert(a[i] != answer);

            ops.emplace_back(a[i], a[i]);

            a[i + 1] *= 2;

            a.erase(a.begin() + i);

            break;

        }

 

    for (auto x : a)

        while (x != answer) {

            ops.emplace_back(0, x);

            ops.emplace_back(x, x);

            x *= 2;

        }

 

    ops.emplace_back(0, answer);

    cout << ops.size() << '\n';

    for (auto &[x, y] : ops) 

        cout << x << ' ' << y << '\n';

        

    return;

}

 

signed main(){

    ios_base::sync_with_stdio(false); 

    cin.tie(nullptr);



    int t; cin >> t;

    while(t--)  solve();

}