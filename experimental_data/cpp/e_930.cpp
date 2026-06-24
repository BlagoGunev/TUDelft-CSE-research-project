#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define LL long long
using namespace std;
const LL Maxn = 100010;
const LL Mod = 1e9+7;
LL b[Maxn<<2], bl;
LL f1[Maxn], f2[Maxn], f[Maxn<<2];
struct lnode {
 LL l, r;
 bool operator<(const lnode &A) const { return l == A.l ? r > A.r : l < A.l; }
}l1[Maxn], l2[Maxn]; LL n, m, K;
LL qpow(LL x, LL k) {
 LL ret = 1;
 while(k){
  if(k&1) ret = ret*x%Mod;
  x = x*x%Mod;
  k >>= 1;
 }
 return ret;
}
void up(LL &x, LL y) { x = (x + y) % Mod; }
int main() {
 LL i, j, k;
 scanf("%I64d%I64d%I64d", &K, &n, &m);
 for(i = 1; i <= n; i++) scanf("%I64d%I64d", &l1[i].l, &l1[i].r);
 sort(l1+1, l1+n+1);
 LL tmp = 0;
 for(i = 1; i <= n; i++){
  while(tmp > 0 && l1[i].r <= l1[tmp].r) tmp--;
  l1[++tmp] = l1[i];
 }
 n = tmp;
 for(i = 1; i <= m; i++) scanf("%I64d%I64d", &l2[i].l, &l2[i].r);
 sort(l2+1, l2+m+1);
 tmp = 0;
 for(i = 1; i <= m; i++){
  while(tmp > 0 && l2[i].r <= l2[tmp].r) tmp--;
  l2[++tmp] = l2[i];
 }
 m = tmp;
 for(i = 1; i <= n; i++) b[++bl] = l1[i].l-1, b[++bl] = l1[i].r;
 for(i = 1; i <= m; i++) b[++bl] = l2[i].l-1, b[++bl] = l2[i].r;
 b[++bl] = K;
 sort(b+1, b+bl+1);
 bl = unique(b+1, b+bl+1) - (b+1);
 LL j1 = 1, k1 = 1, s1 = 0, j2 = 1, k2 = 1, s2 = 0;
 f[0] = 1;
 for(i = 1; i <= bl; i++){
  if(k1 <= n && l1[k1].r == b[i]){
   while(j1 < k1 && l1[j1].r < l1[k1].l) s1 = (s1-f1[j1++]+Mod)%Mod;
   tmp = (s1+f[lower_bound(b+1, b+bl+1, l1[k1].l)-b-1])%Mod;
   up(f1[k1], Mod-tmp);
   up(f[i], Mod-tmp);
   up(s1, Mod-tmp);
   k1++;
  }
  if(k2 <= m && l2[k2].r == b[i]){
   while(j2 < k2 && l2[j2].r < l2[k2].l) s2 = (s2-f2[j2++]+Mod)%Mod;
   tmp = (s2+f[lower_bound(b+1, b+bl+1, l2[k2].l)-b-1])%Mod;
   up(f2[k2], Mod-tmp);
   up(f[i], Mod-tmp);
   up(s2, Mod-tmp);
   k2++;
  }
  up(f[i], f[i-1]*qpow(2, b[i]-b[i-1]));
 }
 printf("%I64d\n", f[bl]);
 return 0;
}