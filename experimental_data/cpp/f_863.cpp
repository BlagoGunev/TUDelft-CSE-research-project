#include <bits/stdc++.h>

using namespace std;
vector<int> ed[2000];
int n, q, tt;
int mar[2000], pr[2000];
int lb[2000], rb[200];
int dl[200];
int cnt[200];
bool kun(int x) {
    if (mar[x] == tt) return false;
    mar[x] = tt;
    for (int j = 0; j < ed[x].size(); j++) {
        int to = ed[x][j];
        if (pr[to] == 0) {
            pr[to] = x;
            return true;
        }
        else
        if (mar[pr[to]] != tt && kun(pr[to])) {
            pr[to] = x;
            return true;
        }
    }
    return false;
}
int main()  {
  //  freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) lb[i] = 1, rb[i] = n;
    for (int i = 1; i <= q; i++) {
        int t, l, r, y;
        cin >> t >> l >> r >> y;
        for (int j = l; j <= r; j++) {
            if (t == 1) lb[j] = max(lb[j], y);
            else rb[j] = min(rb[j], y);
        }
    }
    for (int i = 1; i <= n; i++)
        if (lb[i] > rb[i]) {
            cout << "-1\n";
            return 0;
        }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (lb[j] <= i && i <= rb[j]) ed[i].push_back(j);
    }
    for (int ii = 1; ii <= n; ii++)
    for (int i = 1; i <= n; i++)
        if (dl[i] == 0) {
            tt++;
            bool f = kun(i);
            if (f == false) dl[i] = 1;
        }
    int ans = 0;

    for (int i = 1; i <= n; i++) cnt[pr[i]]++;
    for (int i = 1; i <= n; i++) ans += cnt[i] * cnt[i];
    cout << ans << "\n";
    return 0;
}