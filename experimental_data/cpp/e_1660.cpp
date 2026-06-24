#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <algorithm>

#include <cmath>

#include <vector>

#include <set>

#include <map>

#include <unordered_set>

#include <unordered_map>

#include <queue>

#include <ctime>

#include <cassert>

#include <complex>

#include <string>

#include <cstring>

#include <chrono>

#include <random>

#include <bitset>

 

#define pb push_back

#define int long long

#define all(x) x.begin(), (x).end()

#define rall(x) x.rbegin(), (x).rend()

#define ld long double

using namespace std;

 

void solve() {

  int n;

  cin >> n;

  vector<string> f(n);

  for (int i = 0; i < n; i++) {

    cin >> f[i];

  }

  vector<int> cnt(n);

  for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++) {

      cnt[(n + i - j) % n] += (f[i][j] - '0');

    }

  }

  sort(all(cnt));

  int ans = 0;

  for (int i = 0; i < n - 1; i++) {

    ans += cnt[i];

  }

  ans += n - cnt[n - 1];

  cout << ans << '\n';

}

 

 

signed main() {

  ios::sync_with_stdio(false);

  cin.tie(nullptr);

  cout.tie(nullptr);

  int t;

  cin >> t;

  while (t--) {

    solve();

  }

}