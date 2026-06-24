#include <bits/stdc++.h>
using namespace std;

int seive[26];

int main() {
    int n, k, ans = 0, i = 0; cin >> n >> k;
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        seive[s[i] - 'a']++;
    }
    while (i < 26 && k) {
        if (seive[i]) {
            ans += i + 1;
            i += 2;
            k--;
        } else {
            i++;
        }
    }
    if (!k) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}