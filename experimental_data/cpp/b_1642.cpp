// Speedforces Practice Kachow



#include <bits/stdc++.h>



using ll = long long;

const ll MOD = 1e9 + 7;



void solve() {

    int n;

    std::cin >> n;

    std::set<int> v;

    for (int i = 0; i < n; i++) {

        int x;

        std::cin >> x;

        v.insert(x);

    }



    for (int i = 1; i <= n; i++) {

        std::cout << std::max(i, (int)v.size()) << " \n"[i == n];

    }

}



int main() {

    std::ios::sync_with_stdio(false);

    std::cin.tie(nullptr);

    int t;

    std::cin >> t;

    while (t--) {

        solve();

    }

}