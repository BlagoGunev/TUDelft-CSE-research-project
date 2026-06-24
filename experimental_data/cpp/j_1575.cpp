#include "bits/stdc++.h"
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  const int LEFT = 3, RIGHT = 1, DOWN = 2;
  int n,m,k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n,vector<int>(m));
  for (int i =0; i < n; i++)
    for (int j =0; j < m; j++)
      cin >> a[i][j];

  vector<int> c(k);
  for (auto& x : c) cin >> x,x--;
  vector<int> col_start(m);
  for (int i =0; i < k; i++) {
    if (col_start[c[i]] == n) {
      cout << c[i]+1 << ' ';
      continue;
    }
    while(col_start[c[i]] < n && a[col_start[c[i]]][c[i]] == DOWN) col_start[c[i]]++;
    int x = col_start[c[i]], y = c[i];
    while(x != n) {
      if (a[x][y]==LEFT) {
        a[x][y] = DOWN;
        y--;
      }
      else if (a[x][y] == RIGHT) {
        a[x][y] = DOWN;
        y++;
      }
      else {
        x++;
      }
    }
    cout << y+1 << ' ';
  }
  cout << '\n';
}
// 1 right, 2 down, 3 left