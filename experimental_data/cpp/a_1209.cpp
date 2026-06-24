#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1);
const int maxn = 2e2+10, maxm = 1e6+5, maxc = 26;
const char bs = 'a';
const LL mod = 1e9+7;
inline LL qpow(LL a, int n, LL MOD) { LL ans = 1; while (n) { if (n & 1)	ans = ans*a % MOD; a = a*a % MOD, n >>= 1; } return ans; }

int a[maxn], n;
bool f[maxn];
bool xxx(int k) {
	for (int i = 0; i < k; i++)
		if (a[k] % a[i] == 0) {
			f[i] = 1;
			return 0;
		}
	return 1;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &a[i]);
	sort(a, a + n);
	f[0] = 1;
	for (int i = 1; i < n; i++)
		if (xxx(i))	f[i] = 1;
	int cnt = 0;
	for (int i = 0; i < n; i++)	cnt += f[i];
	printf("%d\n", cnt);
	return 0;
}