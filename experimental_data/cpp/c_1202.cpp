#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define file freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
signed main() {
    fast;
    srand(time(0));
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        map<char, int>cnt;
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i]]++;
        }
        int n = s.size();
        pair<int, int> aa[n + 1];
        aa[0] = {0, 0};
        int nowx = 0, nowy = 0, miny = 0, minx = 0, maxy = 0, maxx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'W') nowy++;
            if (s[i] == 'S') nowy--;
            if (s[i] == 'A') nowx--;
            if (s[i] == 'D') nowx++;
            aa[i + 1] = {nowx, nowy};
            miny = min(miny, nowy);
            minx = min(minx, nowx);
            maxy = max(maxy, nowy);
            maxx = max(maxx, nowx);
        }
        int x = maxx - minx + 1, y = maxy - miny + 1;
        int ans = x * y;
        if (maxx != minx) {
            int pos1, pos2;
            for (int i = n; i >= 0; i--) {
                if (minx == aa[i].F) {
                    pos1 = i;
                    break;
                }
            }
            for (int i = 0; i <= n; i++) {
                if (maxx == aa[i].F) {
                    pos2 = i;
                    break;
                }
            }
            pos1++;
            if (pos1 < pos2) {
                ans = min(ans, x * y - y);
            }
            for (int i = n; i >= 0; i--) {
                if (maxx == aa[i].F) {
                    pos1 = i;
                    break;
                }
            }
            for (int i = 0; i <= n; i++) {
                if (minx == aa[i].F) {
                    pos2 = i;
                    break;
                }
            }
            pos1++;
            if (pos1 < pos2) {
                ans = min(ans, x * y - y);
            }
        }
        if (maxy != miny) {
            int pos1, pos2;
            for (int i = n; i >= 0; i--) {
                if (miny == aa[i].S) {
                    pos1 = i;
                    break;
                }
            }
            for (int i = 0; i <= n; i++) {
                if (maxy == aa[i].S) {
                    pos2 = i;
                    break;
                }
            }
            pos1++;
            if (pos1 < pos2) {
                ans = min(ans, x * y - x);
            }
            for (int i = n; i >= 0; i--) {
                if (maxy == aa[i].S) {
                    pos1 = i;
                    break;
                }
            }
            for (int i = 0; i <= n; i++) {
                if (miny == aa[i].S) {
                    pos2 = i;
                    break;
                }
            }
            pos1++;
            if (pos1 < pos2) {
                ans = min(ans, x * y - x);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}