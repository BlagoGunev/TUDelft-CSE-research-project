#include<stdio.h>
#define lint long long
lint n, m, a, Q, p;
lint inv[1001234];
lint comb[1001234];
lint ans[1001234];
lint mod[1001234];
int main()
{
	int i, j;
	lint tmp;
	scanf("%lld%lld%lld%lld", &n, &m, &a, &Q);
	a %= Q;
	tmp = a;
	mod[0] = 1;
	for(p=1; p<=Q; ++p)
	{
		mod[p] = tmp;
		if(tmp==1) break;
		tmp *= a;
		tmp %= Q;
	}
	inv[1] = 1;
	for(i=2; i<p; ++i)
	{
		inv[i] = ((p/i)*inv[p%i])%p;
		inv[i] = (-inv[i] + p)%p;
	}
	comb[0]=1; comb[1] = m%p;
	for(i=2; i<=m; ++i) comb[i] = (((comb[i-1]*(m-i+1))%p)*inv[i])%p;
	ans[n] = 1;
	int c=0;
	for(i=n-1; i>=1; --i)
	{
		++c;
		if(c<m+1)
		{
			ans[i] = ans[i+1]+comb[c];
			ans[i] %= p;
		}
		else ans[i]=ans[i+1];
	}
	for(i=1; i<=n; ++i) ans[i] = mod[ans[i]];
	for(i=1; i<=n; ++i) printf("%lld ", ans[i]);
}