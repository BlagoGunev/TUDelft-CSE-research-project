// {{{ template
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef vector<pii> vpii;
// }}}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<pii, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first.first >> a[i].first.second;
    a[i].second = i;
  }
  int m;
  cin >> m;
  vector<pair<pii, pii>> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i].first.first >> b[i].first.second >> b[i].second.first;
    b[i].second.second = i;
  }
  sort(begin(a), end(a));
  sort(begin(b), end(b));
  vi to(m);
  for (int i = 0; i < m; i++) {
    to[b[i].second.second] = i;
  }
  vi ans(n, -1);
  bool can = true;
  set<pii> pq;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < m && b[j].first.first <= a[i].first.first) {
      pq.insert({b[j].first.second, b[j].second.second});
      j++;
    }
    auto itr = pq.lower_bound(make_pair(a[i].first.second, -1));
    if (itr == pq.end()) {
      can = false;
      break;
    } else {
      ans[a[i].second] = itr->second;
      auto cur = *itr;
      pq.erase(itr);
      b[to[cur.second]].second.first--;
      if (b[to[cur.second]].second.first > 0) {
        pq.insert({b[to[cur.second]].first.second, cur.second});
      }
    }
  }
  if (can) {
    cout << "YES" << endl;
    for (int i : ans) {
      cout << i + 1 << " ";
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}