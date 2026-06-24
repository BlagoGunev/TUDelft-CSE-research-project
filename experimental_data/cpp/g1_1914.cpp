#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int a[2005];
pair<int, int> poz[2005];
int first[2005];
int last[2005];

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        first[i] = last[i] = -1;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        if (first[a[i]] == -1)
            first[a[i]] = i;
        last[a[i]] = i;
        poz[i].first = -1;
        poz[i].second = -1;
    }
    for (int i = 1; i <= 2 * n; i++) {
        if (first[a[i]] != i)
            continue;
        unordered_map<int, int> s, s2;
        s[a[i]] = 1;
        s2[a[i]] = 1;
        for (int j = i + 1; j <= 2 * n; j++) {
            if (s.find(a[j]) != s.end())
                s.erase(a[j]);
            else s[a[j]] = 1;
            s2[a[j]] = 1;
            if (s.size() == 0) {
                poz[i] = {j, s2.size()};
                break;
            }
        }
    }
    int P = 1;
    int Min = 0;
    int last = 0;
    int last2 = 0;
    int nr = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (i > last) {
            if (nr != 0)
                P = 1LL * P * nr % MOD * 2 % MOD;
            last = poz[i].first;
            Min++;
            last2 = i;
            nr = poz[i].second;
        }
        else {
            if (i > last2 && poz[i].first < last && poz[i].first != -1) {
                last2 = poz[i].first;
                nr -= poz[i].second;
            }       
        }
    }
    P = 1LL * P * nr % MOD * 2 % MOD;
    cout << Min << ' ' << P << '\n';
}

int main() {
    fast
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}