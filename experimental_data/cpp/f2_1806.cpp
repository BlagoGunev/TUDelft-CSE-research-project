// LUOGU_RID: 171009671
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cassert>

using namespace std;

#define int __int128
// #define int long long
#define PII pair<int,int>
#define x first
#define y second
#define For(i, l, r) for(int i = l; i <= r; i ++)
#define Rep(i, l, r) for(int i = l; i >= r; i --)

bool START;

void in(int &x)
{
	char c = getchar(); int op = 1;
	while(c > '9' || c < '0') op *= (c == '-' ? -1 : 1), c = getchar();
	for(x = 0; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0'; x *= op;
}

void Out(int x)
{
	if(x < 10) {putchar('0' + x); return ;}
	Out(x / 10); putchar('0' + x % 10);
}

const int N = 1e6 + 50, oo = 9e18 + 40;

int Tst, n, m, a[N], mn[N], K, cnt, b[N], sum[N], all;

int gcd(int x, int y)
{
	return !y ? x : gcd(y, x % y);
}

typedef long long LL;

bool ENDPOS = 0;
signed main()
{
	in(Tst);
	while(Tst --)
	{
		int num;
		in(num); in(m); in(K);
		map<int, int> mp; cnt = 0;
		all = 0; n = 0;
		while(num --)
		{
			int x; in(x); all += x;
			if(mp.count(x)) b[++ cnt] = x;
			else mp[x] = 1, a[++ n] = x;
		}
		sort(a + 1, a + n + 1);
		sort(b + 1, b + cnt + 1);
		For(i, 1, cnt) sum[i] = sum[i - 1] + b[i];
		int ans = 0;
		if(cnt >= K) ans = all - sum[K];
		int g = 0;
		For(i, 1, n - 1)
		{
			if(i > K) break;
			all -= a[i];
			int lg = g;
			g = gcd(g, a[i]);
			if(g != lg)
			{
				Rep(j, n, 1)
				{
					mn[j] = a[j] - gcd(a[j], g);
					if(j < n) mn[j] = min(mn[j], mn[j + 1]);
				} 
			}
			if(K - i <= cnt) ans = max(ans, all - mn[i + 1] - sum[K - i]);
		}
		Out(ans); puts("");
	}
	return 0;
}