#include <bits/stdc++.h>

#ifdef DEBUG

#include "debug.h"

#else

#define debug(...) 42

#define debugif(x,y...) 42

#endif

using namespace std;

#define FOR(i, a, b) for(int i = (a); i <= (int)(b); ++i)

#define _FOR(i, a, b) for(int i = (a); i >= (int)(b); --i)

#define INT_INF 0x3f3f3f3f

#define LLONG_INF 0x3f3f3f3f3f3f3f3f

typedef long long ll;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;



int main() {

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int tt;

  cin >> tt;

  FOR(t, 1, tt) {

    int n;

    cin >> n;

    vector<int> a(n);

    for(auto &e:a) cin >> e;

    unordered_map<int, int> cnt;

    for(auto e:a) cnt[e]++;

    vector<int> res;

    for(int i = 0; i < n; ) {

      debug(i);

      int mex = 0;

      while(cnt[mex] != 0) mex++;

      vector<bool> check(mex);

      int tmp = 0;

      while(i < n) {

        if(a[i] < mex && !check[a[i]]) {

          check[a[i]] = true;

          tmp++;

        }

        cnt[a[i]]--;

        i++;

        if(tmp == mex) break;

      }

      res.push_back(mex);

    }

    cout << res.size() << '\n';

    for(auto e:res) cout << e << ' ';

    cout << '\n';

  }

  return 0;

}