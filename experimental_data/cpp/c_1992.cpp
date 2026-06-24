/*
Mayoeba Yabureru
*/
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> ans;
    for (int i = n; i >= k; i --) ans.push_back(i);
    for (int i = k - 1; i > m; i --) ans.push_back(i);
    for (int i = 1; i <= m; i ++) ans.push_back(i);

    for (auto x : ans) cout << x << ' ';
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int I = 0; I < T; I ++){
        solve();
    }
}