#include<bits/stdc++.h>

#define ll long long

#define ld long double

#define fi first

#define se second

#define pii pair<int, int>

#define pll pair<long long, long long>

using namespace std;



void solve() {

    int n;

    cin >> n;

    vector<int> v(n);

    vector<pii> sol;

    for (int i = 0; i < n; i++) cin >> v[i];



    if (n >= 2) sol.push_back({0, n - 1});



    for (int i = 1; i < n - 1; i++) {

        if (v[0] % 2 != v[i] % 2) sol.push_back({0, i});

        else sol.push_back({i, n - 1});

    }



    cout << sol.size() << "\n";

    for (auto e : sol) cout << e.fi + 1 << " " << e.se  + 1 << "\n";



    return;

}



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int tt;

    cin >> tt;

    while(tt--) {

        solve();

    }



    return 0;

}