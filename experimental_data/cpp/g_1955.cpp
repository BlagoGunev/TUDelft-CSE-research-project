#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using ll = long long;

const int MX = 1000005;
int a[105][105], b[105][105], vis[105][105];
vector<int> divs[MX];

void pre() {
  int i, j;
  for (i = 2; i < MX; ++i) {
    for (j = i; j < MX; j += i) {
      divs[j].push_back(i);
    }
  }
  for (i = 0; i < MX; ++i) {
    sort(divs[i].rbegin(), divs[i].rend());
  }
}

void dfs(int r, int c) {
  vis[r][c] = 1;
  if ((r > 0) && (vis[r-1][c] == -1) && b[r-1][c]) dfs(r-1, c);
  if ((c > 0) && (vis[r][c-1] == -1) && b[r][c-1]) dfs(r, c-1);
}

int main() {
  FAST;
  pre();

  int tc = 1, ti;
  cin >> tc;

  for (ti = 1; ti <= tc; ++ti) {
    int n, m, i, j, x, ans;
    cin >> n >> m;

    for (i = 0; i < n; ++i) {
      for (j = 0; j < m; ++j) cin >> a[i][j];
    }

    x = gcd(a[0][0], a[n-1][m-1]);
    ans = 1;
    for (int z : divs[x]) {
      for (i = 0; i < n; ++i) for (j = 0; j < m; ++j) {
        b[i][j] = (a[i][j] % z == 0) ? 1 : 0;
        vis[i][j] = -1;
      }
      dfs(n-1, m-1);
      if (vis[0][0] == 1) {
        ans = z;
        break;
      }
    }

    cout << ans << "\n";
  }

  return 0;
}