#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 5010;
long long f[N][N];
bool valid[N][N];
int x[N], a[N], b[N], c[N], d[N];
int n, s, e;
void update(long long &x, long long y, bool &z)
{
	if(!z)
	{
		z = 1;
		x = y;
		return;
	}
	x = min(x, y);
}
int main()
{
	scanf("%d%d%d", &n, &s, &e);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &x[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &b[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &c[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &d[i]);
	valid[0][0] = 1;
	int delta = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(i == min(s, e))
			delta = s < e ? 1 : -1;
		else if(i == max(s, e))
			delta = 0;
		if(i != s && i != e)
			for(int j = 0; j <= i && j <= n - i; ++j)
			{
				if(j && valid[i - 1][j - 1])
					update(f[i][j], f[i - 1][j - 1] + b[i] + d[i] - x[i] * 2, valid[i][j]);
				if((j || i == n) && valid[i - 1][j + 1])
					update(f[i][j], f[i - 1][j + 1] + a[i] + c[i] + x[i] * 2, valid[i][j]);
				if(j && valid[i - 1][j])
				{
					if(j > 1 || !delta)
						update(f[i][j], f[i - 1][j] + min(a[i] + d[i], b[i] + c[i]), valid[i][j]);
					else if(delta == 1)
						update(f[i][j], f[i - 1][j] + a[i] + d[i], valid[i][j]);
					else
						update(f[i][j], f[i - 1][j] + b[i] + c[i], valid[i][j]);
				}
			}
		else if(i == s)
			for(int j = 0; j <= i && j <= n - i; ++j)
			{
				if(s < e && j && valid[i - 1][j - 1])
					update(f[i][j], f[i - 1][j - 1] + d[i] - x[i], valid[i][j]);
				if(s < e && j && valid[i - 1][j])
					update(f[i][j], f[i - 1][j] + c[i] + x[i], valid[i][j]);
				if(s > e && (j || i == n) && valid[i - 1][j + 1])
					update(f[i][j], f[i - 1][j + 1] + c[i] + x[i], valid[i][j]);
				if(s > e && j && valid[i - 1][j])
					update(f[i][j], f[i - 1][j] + d[i] - x[i], valid[i][j]);
			}
		else
			for(int j = 0; j <= i && j <= n - i; ++j)
			{
				if(s < e && (j || i == n) && valid[i - 1][j + 1])
					update(f[i][j], f[i - 1][j + 1] + a[i] + x[i], valid[i][j]);
				if(s < e && j && valid[i - 1][j])
					update(f[i][j], f[i - 1][j] + b[i] - x[i], valid[i][j]);
				if(s > e && j && valid[i - 1][j - 1])
					update(f[i][j], f[i - 1][j - 1] + b[i] - x[i], valid[i][j]);
				if(s > e && j && valid[i - 1][j])
					update(f[i][j], f[i - 1][j] + a[i] + x[i], valid[i][j]);
			}
	}
	printf("%lld\n", f[n][0]);
	return 0;
}