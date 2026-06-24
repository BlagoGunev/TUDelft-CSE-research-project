#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef int myint;
template<typename T1, typename T2> bool maxup(T1& h, const T2& g) {
  if (h < g) { h = g; return true; } return false;
}
template<typename T1, typename T2> bool minup(T1& h, const T2& g) {
  if (h > g) { h = g; return true; } return false;
}
char ibuf[1 << 23], *is = ibuf, *it = ibuf;
inline char getc() {
  if (is == it) it = (is = ibuf) + fread(ibuf, 1, 1 << 23, stdin);
  return is == it ? EOF : *is++;
}
inline myint getint() {
  myint res = 0; int neg = 0; char ch = getc();
  while (not(isdigit(ch) or ch == '-') and ch != EOF) ch = getc();
  if (ch == '-') neg = 1, ch = getc();
  while (isdigit(ch)) res = res * 10 + ch - 48, ch = getc();
  return neg ? -res : res;
}
const int N = 1e5 + 10, E = 5e5 + 10;
const LL INF = 1e9;

int a[N];
int n;
signed main() {
  int t = getint();
  while (t--) {
    n = getint();
    double p = -1e18, sum = 0;
    for (int i = 1; i <= n; ++i) {
      a[i] = getint();
      sum += a[i];
      maxup(p, a[i]);
    }
    double ans = p + (sum - p) / (n - 1);
    printf("%.12lf\n", ans);
  }
  return 0;
}