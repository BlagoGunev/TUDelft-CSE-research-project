#include        <set>
#include        <map>
#include      <queue>
#include      <stack>
#include      <cmath>
#include     <cstdio>
#include     <time.h>
#include     <vector>
#include    <cstring>
#include   <stdlib.h>
#include   <iostream>
#include  <algorithm>
#define LL long long 
#define lowbit(x) x &(-x)
#define fi first
#define se second
using namespace std;
const LL inf=1e9;
const LL N=200010;
namespace FastIO
{
	template<typename tp> inline void read(tp &x)
	{
		x=0; char c=getchar(); bool f=0;
		for(;c<'0'||c>'9';f|=(c=='-'),c = getchar());
		for(;c>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0',c = getchar());
		if(f) x=-x;
	}
	template<typename tp> inline void write(tp x)
	{
		if (x==0) return (void) (putchar('0'));
		if (x<0) putchar('-'),x=-x;
		LL pr[20]; LL cnt=0;
		for (;x;x/=10) pr[++cnt]=x%10;
		while (cnt) putchar(pr[cnt--]+'0');
	}
	template<typename tp> inline void writeln(tp x)
	{
		write(x);
		putchar('\n');
	}
}
using namespace FastIO;
int n, h;
int x[N], y[N];
int solve()
{
	int r = 1, hi = h, ans = 0;
	for (int l = 1; l <= n; l++)
	{
		if (l != 1) hi += x[l] - y[l - 1];
		while (r < n && hi > (x[r + 1] - y[r])) hi -= x[r + 1] - y[r], r++;
		ans = max(ans, y[r] - x[l] + hi);
	}
	return ans;
}
main()
{
	read(n),read(h);
	for (int i = 1; i <= n; i++)
		read(x[i]),read(y[i]);
	writeln(solve());
	return 0;
}