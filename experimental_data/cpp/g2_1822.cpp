#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define prec(x)    \
    cout << fixed; \
    cout.precision(x);
#define mp make_pair
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
#define For(i, j, k) for (int i = (int)(j); i <= (int)(k); i++)
#define Rep(i, j, k) for (int i = (int)(j); i >= (int)(k); i--)
#define debug1(x, y) cout << x << " :: " << y << " "
#define coutn cout << "\n"
#define INF 1987654321

vl a;
vector<pll> vt;
void SolveProblem() {
    int n;
    cin >> n;
    a.clear();
    vt.clear();
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        a.push_back(x);
    }
    a.push_back(1e9 + 1);
    sort(all(a));

    ll ans = 0;
    vt.push_back(pll(a[0], 1));
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1]) vt.back().second++;
        else
            vt.push_back(pll(a[i], 1));
    }
    for (int i = 0; i < vt.size(); i++) {
        ans += vt[i].second * (vt[i].second - 1) * (vt[i].second - 2);
        for (ll j = 2; j * j * vt[i].first <= 1e9;) {
            pll k = *lower_bound(all(vt), pll(vt[i].first * j, 0));
            pll kk = *lower_bound(all(vt), pll(vt[i].first * j * j, 0));
            if (k.first == vt[i].first * j && kk.first == vt[i].first * j * j) ans += vt[i].second * k.second * kk.second;
            if (k.first / vt[i].first == j) j++;
            else
                j = k.first / vt[i].first;
            // k = lower_bound(k, vt.end(), pll(vt[j].first * vt[j].first / vt[i].first, 0));
            // if (k->first == vt[j].first * vt[j].first / vt[i].first) ans += vt[i].second * vt[j].second * k->second;
        }
        // cout << "xxxx" << ans << endl;
    }
    cout <<  ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case = 1;
    cin >> test_case;
    for (int tc = 1; tc <= test_case; tc++) {
        // cout << "Case #" << tc << ": ";
        SolveProblem();
    }
}