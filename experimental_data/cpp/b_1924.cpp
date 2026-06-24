///////////////////////////////    _LeMur_
#define _CRT_SECURE_NO_WARNINGS
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <complex>
#include <chrono>
#include <random>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <tuple>
#include <queue>
#include <ctime>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

const int N = 300005;
const int inf = 1000 * 1000 * 1000;
const int mod = 998244353;
// mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937 myrand(373);

int n, m, q;
int x[N], v[N];

long long t[N];

void update(int pos, long long delta) {
  for (; pos <= n; pos += pos & -pos) {
    t[pos] += delta;
  }
}

long long get(int pos) {
  long long answ = 0;
  for (; pos > 0; pos -= pos & -pos) {
    answ += t[pos];
  }
  return answ;
}

long long get(int l, int r) {
  return get(r) - get(l - 1);
}

long long calc(int x, int next_x) {
  int len = next_x - x - 1;
  return len * 1ll * v[x] * (len + 1) / 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> q;

  set <int> points;

  for (int i = 1; i <= m; i++) {
    cin >> x[i];
    points.insert(x[i]);
  }
  for (int i = 1; i <= m; i++) {
    int val;
    cin >> val;
    v[x[i]] = val;
  }

  sort(x + 1, x + m + 1);

  for (int i = 1; i < m; i++) {
    update(x[i], calc(x[i], x[i + 1]));
  }

  while (q--) {
    int tp;
    cin >> tp;

    if (tp == 1) {
      int x, val;
      cin >> x >> val;
      v[x] = val;

      points.insert(x);

      auto it = points.find(x);
      --it;

      update(*it, -get(*it, *it));
      update(*it, calc(*it, x));

      ++it;
      ++it;

      update(x, calc(x, *it));
    } else {
      int l, r;
      cin >> l >> r;

      long long answ = 0;
      auto it_l = points.lower_bound(l);
      auto it_r = points.upper_bound(r);
      --it_r;

      int L = *it_l;
      int R = *it_r;

      if (L > R) {
        int len = L - R - 1;
        int first = len - (l - R - 1);
        int second = len - (r - R - 1);
        answ += v[R] * 1ll * (first + second) * 1ll * (r - l + 1) / 2;
      } else {
        answ += get(L, R - 1);

        int len = L - l;
        --it_l;
        answ += v[*it_l] * 1ll * len * (len + 1) / 2;
        
        ++it_r;
        int first = *it_r - R - 1;
        int cnt = r - R;
        answ += cnt * 1ll * v[R] * (first + first - cnt + 1) / 2;
      }

      cout << answ << endl;
    }
  }
  return 0;
}