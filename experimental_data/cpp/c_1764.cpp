#include <bits/stdc++.h>

#define all(c) (c).begin(),(c).end()

#define srt(c) sort(all(c))

#define srtrev(c) sort(all(c)); reverse(all(c))

using namespace std;

using ll=long long;

using i128 = __int128_t;

using pi=pair<int, int>;

using pll=pair<ll, ll>;

using ti=tuple<int, int, int>;

using tll=tuple<ll, ll, ll>;

template <class T> using pq = priority_queue<T>;

template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

void no() { cout << "No" << '\n'; }

void yes() { cout << "Yes" << '\n'; }



void solve(int CASE) {

    int n;

    cin >> n;

    vector<int> v(n);

    for (int i=0; i<n; i++) {

        cin >> v[i];

    }

    sort(v.begin(), v.end());

    ll ans = n/2;

    for (int i=1; i<n; i++) {

        if (v[i] != v[i-1]) ans = max(ans, (ll)i * (n-i));

    }

    cout << ans << '\n';

}



signed main() {

    ios::sync_with_stdio(false);

    cin.tie(0);



    int T = 1;

    cin >> T;

    for (int t=1; t<=T; t++) {

        solve(t);

    }

}