#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> A(n+m+1);
    for (int i=0; i<=n+m; i++) cin >> A[i];
    vector<int> B(n+m+1);
    for (int i=0; i<=n+m; i++) cin >> B[i];
    long long base = 0;
    int countA = 0, countB = 0;
    for (int i=0; i<=n+m; i++) {
      if (A[i] > B[i]) {
        countA += 1;
        if (countA <= n) {
          base += A[i];
        } else {
          base += B[i];
        }
      } else {
        countB += 1;
        if (countB <= m) {
          base += B[i];
        } else {
          base += A[i];
        }
      }
    }
    vector<long long> ans(n+m+1);
    if (countA > n) {
      int firstExcess = 0, count = n;
      for (int i=0; i<=n+m; i++) {
        if (A[i] > B[i]) {
          if (count == 0) {
            firstExcess = i;
            break;
          }
          count -= 1;
        }
      }
      // too many programmers
      // if removing a tester, no change
      // if removing a programmer and before first-excess then the first-excess switches
      for (int i=0; i<=n+m; i++) {
        if (A[i] > B[i]) {
          if (i <= firstExcess) {
            ans[i] = base - A[i] - B[firstExcess] + A[firstExcess];
          } else {
            ans[i] = base - B[i];
          }
        } else {
          ans[i] = base - B[i];
        }
      }
    } else {
      int firstExcess = 0, count = m;
      for (int i=0; i<=n+m; i++) {
        if (A[i] < B[i]) {
          if (count == 0) {
            firstExcess = i;
            break;
          }
          count -= 1;
        }
      }
      for (int i=0; i<=n+m; i++) {
        if (A[i] < B[i]) {
          if (i <= firstExcess) {
            ans[i] = base - B[i] - A[firstExcess] + B[firstExcess];
          } else {
            ans[i] = base - A[i];
          }
        } else {
          ans[i] = base - A[i];
        }
      }
    }
    for (int i=0; i<=n+m; i++) {
      cout << ans[i] << " \n"[i == n+m];
    }

  }
  return 0;
}