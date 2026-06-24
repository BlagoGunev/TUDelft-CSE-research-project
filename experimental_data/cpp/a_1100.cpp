/*
 * Author: MKuchum
 *
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long
//#define double long double
#define FOR(N) for (int i = 0; i < N; ++i)
#define FOR1(N) for (int i = 1; i <= N; ++i)
#define FORJ(N) for (int j = 0; j < N; ++j)
#define pb push_back
#define mp make_pair
#define vint vector<int>
#define pii pair<int, int>
#define vii vector<pii >
#define all(N) N.begin(), N.end()
#define endl "\n"

const int MAXN = 100;

int n, k;
int e, s;
int E, S;
int a[MAXN];
int ans = -1;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    FOR(n) cin >> a[i];
    FOR(n) if (a[i] == 1) E++; else S++;
    FOR(k) {
        e = E;
        s = S;
        int index = i;
        while (index < n) {
            if (a[index] == 1) --e;
            else --s;
            index += k;
        }
        ans = max(ans, abs(e - s));
    }
    cout << ans;

    return 0;
}