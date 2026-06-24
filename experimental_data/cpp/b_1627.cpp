#include <bits/stdc++.h>

/*
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
*/
using namespace std;

typedef long long ll;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>
#define dbg(var) cerr << "[" << #var << " : " << var << "]\n"
ll mod = 1000000007;
#define int64_t uint64_t

template<typename T>
void rv(vector<T> &a) {
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
}

const int EPS = 9;
const int eMXN = 2e5;

void print(vector<int> a) {
    for (auto c : a) {
        cout << c << " ";
    }
    cout << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans.push_back(max(n - i - 1, i) + max(m - j - 1, j));
            }
        }
        sort(all(ans));
        for (int c : ans) {
            cout << c << " ";
        }
        cout << "\n";
    }
    //cerr << "\nTime elapsed: " << 1.000 * clock() / CLOCKS_PER_SEC << " ms. \n";
    return 0;
}