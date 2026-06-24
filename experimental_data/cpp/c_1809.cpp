#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, int k) {
  if (n == 0)
    return {};
  vector<int> arr(n, -1);
  if (k < n) {
    if (k > 0)
      arr[k - 1] = 200;
    arr[k] = -400;
    return arr;
  }

  arr = solve(n - 1, k - n);
  arr.push_back(1000);
  return arr;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr = solve(n, k);
    for (int n : arr)
      cout << n << " ";
    cout << endl;
  }
}