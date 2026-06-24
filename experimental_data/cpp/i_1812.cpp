// Author: Klay Thompson
// Problem: I. Mountain Climber
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
using ll = long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

template<class T>inline void chkmn(T &x, T y) { if (y < x) x = y; }
template<class T>inline void chkmx(T &x, T y) { if (y > x) x = y; }

using namespace std;

int a[] = {0, 1, 0, 1, 0, 1, -1, 1, 0, -1, 1, 1, 0, 0, 0, -1, -1, 0, 0, 1, 0, 0, 0, 0, -1, 0};

void work() {
  string str;
  cin >> str;
  int sum = 0, mn = 0;
  for (auto ch : str) {
    sum += a[ch - 'a'], chkmn(mn, sum);
  }
  cout << ((sum == 0 && mn == 0) ? "YES" : "NO") << '\n';
}

int main() {
  cin.tie(nullptr) -> ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) work();
}