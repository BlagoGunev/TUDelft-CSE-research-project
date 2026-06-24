#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], mx, l[N], r[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    mx = max(mx, a[i]);
  }
  stack <int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.top()] <= a[i]) {
      st.pop();
    }
    if (st.empty()) {
      l[i] = 0;
    } else {
      l[i] = st.top() + 1;
    }
    st.push(i);
  }
  st = stack <int> ();
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && a[st.top()] <= a[i]) {
      st.pop();
    }
    if (st.empty()) {
      r[i] = n - 1;
    } else {
      r[i] = st.top() - 1;
    }
    st.push(i);
  }
  int amount;
  for (int i = 0; i < n; i++) {
    if (a[i] == mx) {
      continue;
    }
    amount = r[i] - l[i] + 1;
    if (amount % 2 == 1) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}