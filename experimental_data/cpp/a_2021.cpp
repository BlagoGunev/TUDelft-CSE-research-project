#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int DIM = 2e5 + 1;
const int INF = 2e9;

int v[DIM];

void solve_test() {
  int n, res;

  cin >> n;
  for ( int i = 1; i <= n; ++i ) {
    cin >> v[i];
  }
  sort(v + 1, v + n + 1);
  int lst = v[1];
  for ( int i = 2; i <= n; ++i ) {
    lst = (lst + v[i]) / 2; 
  }
  cout << lst << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;

  cin >> t;
  while ( t-- ) {
    solve_test();
  }
  return 0;
}