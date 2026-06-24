#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  read(tt);
  while (tt--) {
    int n, l, r;
    read(n),read(l),read(r);
    vector<int> a(n);
    for (int i = 0; i < n; i++) read(a[i]);
    long long ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) {
      int L = -1, R = -1,ll = i + 1, rr = n - 1;
      while (ll <= rr) {
        int j = ll + rr >> 1;
        if (a[i] + a[j] >= l) 
          L = j,rr = j - 1;
         else ll = j + 1;      
      }
      ll = i + 1, rr = n - 1;
      while (ll <= rr) {
        int j = ll + rr >> 1;
        if (a[i] + a[j] <= r) {
          R = j,ll = j + 1;
        } else   rr = j - 1;
      }
      if (L != -1 && R != -1 && L <= R) ans += (R - L + 1);
      
    }
    print(ans,'\n');
  }
  return 0;
}