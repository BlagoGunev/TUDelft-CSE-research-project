#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 3e5 + 5;

int t;
int n;
int dep[N], lp[N], mx_dep[N], ans[N];
vector<int> v[N];

int dfs(int p, int x) {
  dep[x] = dep[p] + 1;
  mx_dep[x] = dep[x];
  lp[x] = 0;
  int mx = 0, mx2 = 0;
  for(auto u : v[x]) {
    if(u != p) {
      int res = dfs(x, u);
      if(res > mx) {
        mx2 = mx;
        mx = res;
      }
      else if(res > mx2) {
        mx2 = res;
      }
      mx_dep[x] = max(mx_dep[x], mx_dep[u]);
      lp[x] = max(lp[x], lp[u]);
    }
  }
  lp[x] = max(lp[x], mx + mx2);
  return mx + 1;
}

void calc(int p, int x, int mx_oth) {
  vector<int> pre(v[x].size(), 0);
  vector<int> suf(v[x].size(), 0);

  for(int i = 0; i < v[x].size(); i++) {
    if(i) {
      pre[i] = max(pre[i], pre[i - 1]);
    }
    auto u = v[x][i];
    if(u != p) {
      pre[i] = max(pre[i], mx_dep[u]);
    }
  }
  for(int i = (int) v[x].size() - 1; i >= 0; i--) {
    if(i + 1 < (int) v[x].size()) {
      suf[i] = max(suf[i], suf[i + 1]);
    }
    auto u = v[x][i];
    if(u != p) {
      suf[i] = max(suf[i], mx_dep[u]);
    }
  }

  auto get_max = [&](int i){
    int res = dep[x];
    if(i) {
      res = max(res, pre[i - 1]);
    }
    if(i + 1 < v[x].size()) {
      res = max(res, suf[i + 1]);
    }
    return res;
  };

  for(int i = 0; i < v[x].size(); i++) {
    auto u = v[x][i];
    if(u == p) {
      continue;
    }
    calc(x, u, max(mx_oth, get_max(i)));
  }
  
  int cost_here = (lp[x] + 1) / 2;
  // printf("x = %d cost_here = %d mx_oth = %d\n", x, cost_here, mx_oth);
  if(cost_here <= mx_oth) {
    // printf("assign ans[%d] = %d\n", mx_oth - cost_here, mx_oth);
    ans[mx_oth - cost_here] = min(ans[mx_oth - cost_here], mx_oth);
  }
  else {
    // printf("ans[0] = %d\n", cost_here);
    ans[0] = min(ans[0], cost_here);
  }
}

/*

1
7
1 2
1 3
3 4
3 5
3 6
5 7

*/


void solve() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    v[i].clear();
  }
  for(int i = 1; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(0, 1);
  for(int i = 0; i <= n; i++) {
    ans[i] = mx_dep[1];
  }
  // printf("ans0 = %d ans1 = %d\n", ans[0], ans[1]);
  calc(0, 1, 0);
  for(int tt = 0; tt < 3; tt++) {
    for(int i = 1; i <= n; i++) {
      ans[i] = min(ans[i], ans[i - 1] + 1);
    }
    for(int i = n - 1; i >= 1; i--) {
      ans[i] = min(ans[i], ans[i + 1]);
    }
  }
  for(int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  puts("");
}

int main() {

  dep[0] = -1;

  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}