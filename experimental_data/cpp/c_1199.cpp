#include <bits/stdc++.h>
#define rep(a, b, c) for(int a = (b); a <= (c); ++ a)
#define per(a, b, c) for(int a = (b); a >= (c); -- a)
using namespace std;
template <class T> void rd(T &x){
  x = 0; int f = 1; char ch = getchar();
  while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
  while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}

const int maxn = 4e5 + 5;
int n, m, t = 1;
int a[maxn], b[maxn];

int main(){
  rd(n), rd(m);
  m = min(20, m * 8 / n);
  rep(i, 1, m) t *= 2;
  rep(i, 1, n) rd(a[i]);
  sort(a + 1, a + n + 1);
  int cnt = 0;
  b[cnt = 1] = 1;
  rep(i, 2, n){
    if(a[i] != a[i - 1]){
      b[++ cnt] = 1;
    }
    else b[cnt] ++;
  }
  if(t >= cnt) return (puts("0")), 0;
  int tot = 0, ans = n;
  per(i, cnt, t + 1) tot += b[i];
  rep(i, 1, cnt - t + 1){
    ans = min(ans, tot);
    tot += b[i] - b[i + t];
  }
  printf("%d\n", ans);
  return 0;
}