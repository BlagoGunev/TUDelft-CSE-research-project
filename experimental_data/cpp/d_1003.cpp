#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#define ri register int

using namespace std;

inline char gch()
{
	static char buf[100010], *h = buf, *t = buf;
	return h == t && (t = (h = buf) + fread(buf, 1, 100000, stdin), h == t) ? EOF : *h ++;
}

typedef long long lo;

inline void re(lo &x)
{
	x = 0;
	char a; bool b = 0;
	while(!isdigit(a = getchar()))
		b = a == '-';
	while(isdigit(a))
		x = (x << 1) + (x << 3) + a - '0', a = getchar();
	if(b == 1)
		x *= -1;
}

lo n, q, a[200020], lx[35], ly[35], lz;

int main()
{
	re(n), re(q);
	for(ri i = 1; i <= n; i ++)
		re(a[i]);
	sort(a + 1, a + 1 + n);
	lo t = 1, ci = 0;
	for(ri i = 1; i <= n; i ++)
	{
		while(t < a[i])
			t <<= 1, ci ++;
		lx[ci] ++;
	}
	/*for(ri i = 0; i <= ci; i ++)
		printf("%I64d ", lx[i]);*/
	for(ri i = 1; i <= q; i ++)
	{
		lo ans = 0, ne = 0, c = 0; re(lz);
		while((1 << c) < lz)
			c ++;
		bool f = 0;
		for(ri j = c; j >= 0 && lz > 0; j --)
		{
			lo t = (1 << j) & lz; ne <<= 1;
			if(t > 0)
				ne ++;
			if(lx[j] <= ne)
				ans += lx[j], ne -= lx[j], lz -= lx[j] * (1 << j);
			else
				ans += ne, ne = 0, lz -= (1 << j) * ne;
		}
		if(ne > 0)
			printf("-1\n");
		else
			printf("%I64d\n", ans);
	}
}