#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 1000005;
const int maxp = 200005; // about maxn/log(maxn)
struct Factor{ // factor as p^num
  int p, num;
};
struct DeComposer {
  DeComposer() { gen_primes(); }
  bool vis[maxn+5];
  int pn, prime[maxp];
  void sieve() {
    int m = (int)sqrt(maxn+0.5);
    memset(vis,0,sizeof(vis));
    for(int i=2;i<=m;++i)if(!vis[i])
      for(int j=i*i;j<=maxn;j+=i)vis[j]=1;
  }
  void gen_primes() {
    sieve();
    pn = 0;
    for (int i = 2; i <= maxn; ++ i) {
      if (!vis[i]) prime[pn++] = i;
    }
  }
  int fcn;
  Factor fc[64]; // x = p1^a1 * p2^a2 * ...
  int fn, factor[maxp]; // all y satisify y|x
  void decompose2(int x,int d, int lim){
    if(d==fcn){
	  if (x <= lim) factor[fn++] = x;
    } else {
      for(int i = 0; i <= fc[d].num; ++ i) {
        decompose2(x, d+1, lim);
        x *= fc[d].p;
      }
    }
  }
  void decompose1(int x, int lim) {
    fcn = 0;
    for(int i = 0; i < pn && prime[i] * prime[i] <= x; ++ i) if (x % prime[i] == 0) {
      fc[fcn].p = prime[i];
      fc[fcn].num = 0;
      while(x % prime[i] == 0) {
        fc[fcn].num ++;
        x /= prime[i];
      }
      if (prime[i] <= lim) fcn ++;
    }
    if (x > 1 && x <= lim) {
      fc[fcn].p = x;
      fc[fcn].num = 1;
      fcn ++;
    }
  }
  void decompose(int x, int lim){
    decompose1(x,lim);
    fn = 0;
    decompose2(1,0,lim);
    sort(factor, factor+fn);
  }
} dc_solver;

int n, a[100005];
int p[100005];
const int MOD = 1000000007;
int main() {
	dc_solver.gen_primes();
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}
	memset(p, 0, sizeof p);
	p[0] = 1;
	for (int i = 1; i <= n; ++ i) {
		dc_solver.decompose(a[i], i);
		for (int j = dc_solver.fn-1; j >= 0; -- j) {
			int x = dc_solver.factor[j];
			if (p[x-1] != 0) {
				p[x] += p[x-1];
				p[x] %= MOD;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++ i) {
		ans += p[i];
		ans %= MOD;
	}
	printf("%d\n", ans);
}