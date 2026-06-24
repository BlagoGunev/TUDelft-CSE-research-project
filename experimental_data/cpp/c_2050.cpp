#include <bits/stdc++.h>

using namespace std;
#define Just_Zar3et_FegL ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define IO freopen("input.txt", "r", stdin); freopen("outputt.txt", "w", stdout);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int) (x).size()
#define ll long long

signed main() {
    Just_Zar3et_FegL
#ifdef Clion
    IO
#endif
    int t = 1;
     cin >> t;
    while (t--) {
        string n;
        cin >> n;
        ll S = 0;
        int cnt = 0, cnt1 = 0;
        for (auto c: n) {
            int d = c - '0';
            S += d;
            if (d == 2) cnt++;
            if (d == 3) cnt1++;
        }
        int trgt = (9 - (S % 9)) % 9;
        bool flag = false;
        int mx = min(cnt1, 9);
        for (int i = 0; i <= mx; i++) {
            int tmp = (trgt - (6 * i) % 9 + 9) % 9;
            int x = (tmp * 5) % 9;
            if (x <= cnt) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}