#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define all(v) (v).begin(), (v).end()

#define popcountll(x) __builtin_popcountll(x)

#define pb push_back

#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef Liucj_2022

#include "../Liucj_2022/debug.h"

#else

#define LOG(...)

#endif // Liucj_2022



void solve() {

    int n, ans = 0;  cin >> n;

    string s;   cin >> s;   s = "0" + s;

    vector<int> a(n);

    for (int i = 0; i < n; ++ i)  cin >> a[i];

    a.insert(a.begin(), 0);

    n ++;

    

    for (int i = 0; i < n; ++ i) {

        if (s[i] == '0') {

            int j = i + 1;

            vector<int> val(1, a[i]);

            while (j < n && s[j] == '1') {

                val.pb(a[j]);

                ++ j;

            }

            sort(all(val), greater<int>());

            LOG(val)

            ans += accumulate(all(val), 0) - val.back();

            i = j - 1;

        }

    } LOG(ans)

    cout << ans << endl;

}



signed main() {

    ios::sync_with_stdio(false), cin.tie(0);

    #ifdef Liucj_2022

freopen("sample.in", "r", stdin);	   freopen("sample.out", "w", stdout);

    #endif

    int tt = 1;

    cin >> tt;

    while (tt -- ) solve();

    return 0;

}