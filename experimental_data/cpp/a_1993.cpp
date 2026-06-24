#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void testcase() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> cnt(4, n);
    int ans = 0;
    for (int i = 0; i < (4 * n); i++) {
        if (s[i] == '?') continue;
        cnt[s[i] - 'A']--;
        if (cnt[s[i] - 'A'] >= 0) ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        testcase();
    }
}