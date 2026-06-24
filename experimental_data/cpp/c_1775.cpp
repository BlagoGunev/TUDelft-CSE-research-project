#include <bits/stdc++.h>

using namespace std;

#define int int64_t

#define all(arr) arr.begin(), arr.end()

#define forn(i, n) for (int i = 0; i < n; i++)

#define print(arr) forn(i, arr.size()) cout << arr[i] << " "

#define scan(arr) forn(i, arr.size()) cin >> arr[i]

void __print(int x) { cerr << x; }

void __print(unsigned x) { cerr << x; }

void __print(float x) { cerr << x; }

void __print(double x) { cerr << x; }

void __print(long double x) { cerr << x; }

void __print(char x) { cerr << '\'' << x << '\''; }

void __print(const char *x) { cerr << '\"' << x << '\"'; }

void __print(const string &x) { cerr << '\"' << x << '\"'; }

void __print(bool x) { cerr << (x ? "true" : "false"); }



template <typename T, typename V>

void __print(const pair<T, V> &x) {

    cerr << '{';

    __print(x.first);

    cerr << ',';

    __print(x.second);

    cerr << '}';

}

template <typename T>

void __print(const T &x) {

    int f = 0;

    cerr << '{';

    for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);

    cerr << "}";

}

void _print() { cerr << "]\n"; }

template <typename T, typename... V>

void _print(T t, V... v) {

    __print(t);

    if (sizeof...(v)) cerr << ", ";

    _print(v...);

}

#ifndef ONLINE_JUDGE

#define debug(x...)               \

    cerr << "[" << #x << "] = ["; \

    _print(x)

#else

#define debug(x...)

#endif

vector<int> setbits(int n) {

    vector<int> a(64, 0);

    int p = 1, j = 0;

    while (p <= n) {

        if ((p & n) > 0) a[j] = 1;

        j++;

        p *= 2;

    }

    return a;

}

void solve() {

    int n, x;

    cin >> n >> x;

    if (n < x)

        cout << -1;

    else {

        int p = 2, ans = n, temp = n;

        if (n == x)

            cout << n;

        else {

            if (n & 1)

                temp--;

            else

                ans++;

            while (p <= n) {

                if ((p & n) == 0) {

                    if (temp == x) {

                        cout << ans + 1;

                        return;

                    }

                    ans += p;

                } else

                    temp -= p;

                p <<= 1;

            }

            if (x > 0)

                cout << -1;

            else

                cout << p;

        }

    }

}

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int t;

    cin >> t;

    forn(i, t) {

        // cout << "Case #" << i + 1 << ": ";

        solve();

        cout << "\n";

    }

    return 0;

}