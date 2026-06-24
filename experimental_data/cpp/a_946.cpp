#include<bits/stdc++.h>
#include<fstream>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1000055;
const int INF = 0x3f3f3f3f;
const double eps = 1e9;
typedef long long LL;
#define ls o<<1
#define rs o<<1|1
#define m(o) (q[o].l+((q[o].r-q[o].l)>>1))

int B, C;
int main() {
 int n, t;
 scanf("%d", &n);
 for (int i = 0; i < n; i++) {
  scanf("%d", &t);
  if (t >= 0)B += t;
  else C += t;
 }
 printf("%d\n", B - C);
 return 0;
}