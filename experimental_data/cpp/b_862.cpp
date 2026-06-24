#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define lowbit(x) x&(-x)
#define PA pair<int, int>
#define MK make_pair
using namespace std;
typedef long long LL;
inline LL read()
{
	LL l = 0, f = 1;
	char a = getchar();
	for (; a < '0' || a > '9'; a = getchar())
		if (a == '-') f = -1;
	for (; a >= '0' && a <= '9'; a = getchar())
		l = l*10+a-48;
	return l*f;
}
const LL N = 100005;
struct Edge
{
	LL v, next;
}e[N<<1];
LL n, num, ans, h[N], dep[N];
void insert(LL u, LL v)
{
	e[++num].v = v, e[num].next = h[u], h[u] = num;
	e[++num].v = u, e[num].next = h[v], h[v] = num;
}
void dfs(LL x, LL f)
{
	for (LL i = h[x]; i; i = e[i].next)
	{
		LL v = e[i].v;
		if (v == f) continue;
		dep[v] = dep[x]+1;
		dfs(v, x);
	}
}
int main(int argc, char const *argv[])
{
	n = read();
	for (LL i = 1; i < n; ++i)
	{
		LL u = read(), v = read();
		insert(u, v);
	}
	dfs(1, 0);
	for (LL i = 1; i <= n; ++i) if (dep[i]&1) ans++;
	ans = ans*(n-ans)-n+1;
	printf("%I64d\n", ans);
	return 0;
}