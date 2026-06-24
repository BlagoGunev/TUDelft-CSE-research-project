#include<bits/stdc++.h>
using namespace std;
#define L long long
#define MIN(x, v) x = min(x, v)
#define CASES int __cases; cin >> __cases; while (__cases--)
template <class T=L>
vector<T> pullN(int n) {
  vector<T> res(n);
  for (T&v:res) cin >> v;
  return res;
}
#define COUT cout <<
#define END << "\n";

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  CASES {
    L n;
    cin >> n;
    auto nums = pullN(n);
    map<L, int> occ;
    for (L v : nums) {
      occ[v]++;
    }
    n = occ.size();
    vector<vector<L>> dp(n+1, vector<L>(n+1, INT_MAX));
    dp[1][1] = 1;
    int i = 0;
    for (auto v = occ.begin(); v != occ.end(); v++) {
      for (int j = n-1; j >= 0; j--) {
        if (j >= v->second) {
          MIN(dp[i+1][j-v->second], dp[i][j]);
        }
        MIN(dp[i+1][j+1], dp[i][j]+1);
      }
      i++;
    }
    L res = INT_MAX;
    for (int j = 0; j <= n; j++) {
      // cout << dp[n][j] << "\t";
      MIN(res, dp[n][j]);
    }
    // COUT "\n";
    COUT res END
  }
}

/*
1
3
1 1 1


*/