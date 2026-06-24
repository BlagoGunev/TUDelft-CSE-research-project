#include <bits/stdc++.h>
using namespace std;

#define         ll          long long
#define         fo(i, n)    for(int i = 0; i < n; i++)

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll c1 = 0, c2 = 0, mx_ones = INT_MIN, mx_zeroes = INT_MIN;
    ll max_ones = 0, max_zeroes = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') {
            c1++;
            max_ones++;
            mx_ones = max(mx_ones, max_ones);
            max_zeroes = 0;
        }
        else {
            max_ones = 0;
            c2++;
            max_zeroes++;
            mx_zeroes = max(mx_zeroes, max_zeroes);
        }
    }
    if(c1 > 0 && c2 > 0)
        cout << max(mx_ones * mx_ones, max(mx_zeroes * mx_zeroes, c1 * c2)) << "\n";
    else if(c1 > 0) cout << mx_ones * mx_ones << "\n";
    else cout << mx_zeroes * mx_zeroes << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int TC;
    cin >> TC;
    while(TC--) {
        solve();
    }
}