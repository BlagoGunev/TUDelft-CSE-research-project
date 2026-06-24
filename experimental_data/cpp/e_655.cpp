#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MOD = 1e9 + 7;

int addmod(int x, int y) {
    int res = x + y;
    while (res >= MOD) {
        res -= MOD;
    }
    return res;
}

int submod(int x, int y) {
    return addmod(x, MOD - y);
}

int main() {
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    string t;
    cin >> t;
    int m = t.size();
    int pr = 1;
    vector<int> prs(k, 0);
    vector<int> ans(k, 0);
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int c = t[i] - 'a';
        int nsum = addmod(sum, addmod(sum, addmod(1, MOD - ans[c])));
        ans[c] = addmod(sum, 1);
        sum = nsum;
        //cerr << c << " " << ans[c] << " " << sum << endl;
        prs[c] = pr++;
    }
    vector<pair<int, int> > tmp;
    for (int i = 0; i < prs.size(); i++) {
        tmp.pb(mp(prs[i], i));
    }
    sort(tmp.begin(), tmp.end());
    vector<int> order;
    for (int i = 0; i < k; i++) order.pb(tmp[i].S);
    int it = 0;
    for (int i = 0; i < n; i++) {
        int c = order[it++];
        if (it == order.size()) it = 0;
        int nsum = addmod(sum, addmod(sum, addmod(1, MOD - ans[c])));
        ans[c] = addmod(sum, 1);
        sum = nsum;
    }
    sum = addmod(sum, 1);
    cout << sum << endl;
    return 0;
}