#include <bits/stdc++.h>



using namespace std;



typedef long long ll;

typedef unsigned long long ull;



const ll INF = 1e18;

const ll MAXN = 1e6;

const ll MINN = -5e5;

const ll MOD = 1e9 + 7;

const int C = 1000;



void solve() {

    int t, n, ans;

    cin >> t;

    vector<ll> v;

    vector<bool> used;

    map<ll, int> indexes;



    while (t--) {

        cin >> n;

        v.resize(n);

        used.resize(n);

        indexes.clear();

        for (int i = 0; i < n; ++i) cin >> v[i];

        std::sort(v.begin(), v.end());

        for (int i = 0; i < n; ++i) {

            ++indexes[v[i]];

        }

        ans = 0;

        for (int i = 0; i < n; ++i) {

            if (indexes[v[i] + 1] == 0) {

                ++ans;

            } else {

                --indexes[v[i] + 1];

            }

        }

        cout << ans << '\n';

    }

}



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);



    solve();



    return 0;

}