#include<bits/stdc++.h>

using namespace std;



void solve() {

    int n;

    cin >> n;

    vector<int> odd, even;

    for (int i = 0; i < n; ++i) {

        int x;

        cin >> x;

        if (i & 1) odd.push_back(x);

        else even.push_back(x);

    }

    sort(odd.begin(), odd.end());

    sort(even.begin(), even.end());

    vector<int> a(n);

    int l = 0, r = 0;

    for (int i = 0; i < n; ++i) {

        if (i & 1) a[i] = odd[l++];

        else a[i] = even[r++];

    }

    cout << (is_sorted(a.begin(), a.end()) ? "YES\n" : "NO\n");

}

 

int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {

        solve();

    }

    return 0;

}