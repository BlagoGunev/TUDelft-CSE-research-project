#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#define Rep(i, x, y) for (int i = x; i <= y; i ++)
#define Dwn(i, x, y) for (int i = x; i >= y; i --)
#define RepE(i, x) for (int i = pos[x]; i; i = g[i].nex)
#define v g[i].y
using namespace std;
typedef long long ll;
typedef double db;
const int N = 105;
const ll inf = 1ll << 60;
int n, c[N], m, d, a[N][N];
ll ans = inf, f[N][N][N];
int main()
{
	scanf ("%d%d%d", &n, &m, &d);
	Rep(i, 1, n) scanf ("%d", &c[i]);
	Rep(i, 0, n) Rep(j, 0, d) Rep(k, 0, m) f[i][j][k] = inf;
	f[0][0][0] = 0;
	Rep(i, 1, n) {
		Rep(j, 1, m) scanf ("%d", &a[i][j]);
		a[i][ c[i] ] = 0;
		Rep(j, 1, d){
			ll m1 = inf, m2 = inf;
			Rep(k, 0, m) {
				ll z = f[i - 1][j - 1][k];
				if (z < m1) m2 = m1, m1 = z;
				else m2 = min(m2, z);
			}
			Rep(k, 1, m) if (!c[i] || c[i] == k)  {
				f[i][j][k] = m1 == f[i - 1][j - 1][k] ? m2 : m1;
				f[i][j][k] = min(f[i][j][k], f[i - 1][j][k]);
				f[i][j][k] += a[i][k];
				// cout << i <<" "<<j<<" "<<k<<" "<<f[i][j][k]<< endl;
			}
		}
	}
	Rep(k, 1, m) ans = min(ans, f[n][d][k]);
	if (ans == inf) puts("-1");
	else printf("%I64d\n", ans);
	return 0;
}