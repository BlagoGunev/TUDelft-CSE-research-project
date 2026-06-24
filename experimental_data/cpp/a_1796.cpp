#include "iostream"
#include "vector"
#include "set"
#include "map"
#include "string"
#include "fstream"
#include "stack"
#include "sstream"
#include "algorithm"
#include "unordered_set"
#include "unordered_map"
#include "deque"
#include "numeric"
#include "iomanip"
#include "fstream"
#include "random"

using namespace std;

#define int long long

pair<int, int> operator+(pair<int, int> &a, pair<int, int> &b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

int bin_pow(int a, int b, int mod) {
    if (b == 1) return a % mod;
    if (b % 2 == 0) {
        int t = bin_pow(a, b / 2, mod);
        return (t * t) % mod;
    }
    return (a * bin_pow(a, b - 1, mod)) % mod;
}

int fact(int n, int mod) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
        res %= mod;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = "";
    for (int i  = 1; i<= 1000; i++) {
        if (i % 3  ==0) {
            t += 'F';
        }
        if (i % 5 == 0) {
            t+= 'B';
        }
    }
    for (int i = 0; i < t.size() - n; i++) {
        string p = "";
        for (int j = i; j < i + n; j++) {
            p += t[j];
        }
        if (p == s) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

void sf() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

signed main() {
    sf();
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
}