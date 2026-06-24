#include<bits/stdc++.h>
using namespace std;
#define L long long
#define CASES int __cases; cin >> __cases; while (__cases--)
template <class T=L>
vector<T> pullN(int n) {
  vector<T> res(n);
  for (T&v:res) cin >> v;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  CASES {
    int n;
    cin >> n;
    auto nums = pullN(n);
    L low = 0, high = 0;
    for (L v : nums) {
      L op1 = low + v;
      L op2 = high + v;
      L op3 = abs(low + v);
      L op4 = abs(high + v);
      low = min(min(op1, op2), min(op3, op4));
      high = max(max(op1, op2), max(op3, op4));
    }
    cout << high << '\n';
  }
}