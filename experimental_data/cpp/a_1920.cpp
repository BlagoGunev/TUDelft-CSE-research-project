#include<iostream>
#include <bits/stdc++.h>

#define ld long double
#define ll long long
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 3e5 + 9, MOD = 998244353;

void doWork() {
    int n, L = -1e9, R = 1e9;
    cin >> n;
    set<int> st;
    while (n--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            L = max(L, x);
        } else if (t == 2) {
            R = min(R, x);
        } else {
            st.insert(x);
        }
    }
    int ans = max(0, R - L + 1);
    for (auto i: st) {
        if (i >= L && i <= R) {
            ans--;
        }
    }
    cout << ans << "\n";
}

int main() {
    IO
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        //  cout << "Case #" << i << ": ";
        doWork();
    }
}