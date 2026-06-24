#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, k, s;
    cin >> n >> k >> s;
    ll max_d = 1ll* (n-1) * k;
    if (max_d < s) cout << "NO" << endl;
    else if (k > s) cout << "NO" << endl;
    else {
        if (n == 2) {
            cout << "YES" << endl;
            for (ll i = 0; i < k; ++i) {
                cout << 2 - (i&1) << " ";
            }
            cout << endl;
        }
        else {
            cout << "YES" << endl;
            ll times = (s-k)/ (n-2);
            ll mo = (s - k) % (n-2);
            ll lo = 0;
            for (ll i = 0; i < times; ++i) {
                if (i&1) cout << 1 << " ", lo = 1;
                else cout << n << " ", lo = n;
            }
            if (k - times == 0) {
                cout << endl;
            }
            else if (lo == n) {
                lo = n - mo - 1;
                cout << lo << " ";
                for (ll i = 1; i < k-times; ++i) {
                    if (i&1) cout << lo+1 << " ";
                    else cout << lo << " ";
                }
                cout << endl;
            }
            else {
                lo = 1 + mo + 1;
                cout << lo << " ";
                for (ll i = 1; i < k-times; ++i) {
                    if (i & 1) cout << lo-1 << " ";
                    else cout << lo << " ";
                }
                cout << endl;
            }
        }
    }
    
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}