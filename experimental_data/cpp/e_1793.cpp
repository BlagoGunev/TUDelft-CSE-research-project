#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n; cin >> n;
    vector a(n, 0), max_books(n + 1, 0), best(n + 1, 0);
    for (auto& x : a) cin >> x;

    std::sort(a.begin(), a.end());

    max_books[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (i + 1 - a[i] >= 0) {
            max_books[i + 1] = 1 + max_books[i + 1 - a[i]];
            int total_books = max_books[i + 1] + n - i - 1;
            best[total_books] = std::max(best[total_books], i + 1);
        } else {
            int total_books = n - a[i] + 1;
            best[total_books] = std::max(best[total_books], i + 1);
        }
        max_books[i + 1] = std::max(max_books[i + 1], max_books[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        best[i] = std::max(best[i], best[i + 1]);
    }
    int q; cin >> q;
    while (q--) {
        int k; cin >> k;
        cout << best[k] << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}