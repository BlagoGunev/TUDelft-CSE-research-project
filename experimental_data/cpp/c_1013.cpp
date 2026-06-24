#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define mp make_pair
#define pb push_back
using namespace std;

namespace Header_Template {
  typedef long long li;
  template<class T>inline void read(T &x) {
    x = 0;
    T tmp = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') tmp = -1, c = getchar();
    while (c >= '0' && c <= '9')
      x = (x << 1) + (x << 3) + c - '0', c = getchar();
    x *= tmp;
  }
  template<class T>inline void Max(T &x, T y) {
    if (y > x) x = y;
  }
  template<class T>inline void Min(T &x, T y) {
    if (y < x) x = y;
  }
}
using namespace Header_Template;

const int N = 2e5 + 10;
int n, a[N];

int main(void) {
  read(n);
  for (int i = 1; i <= n + n; ++i)
    read(a[i]);
  sort(a + 1, a + 1 + n + n);
  li ans = 1e18;
  for (int i = 1; i <= n; ++i) {
    int x = a[i + n - 1] - a[i];
    int y = (i == 1) ? (a[n + n] - a[n + 1]) : (a[n + n] - a[1]);
    ans = min(ans, 1LL * x * y);
  }
  printf("%lld\n", ans);

  return 0;
}