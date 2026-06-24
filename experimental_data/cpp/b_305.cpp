#include <bits/stdc++.h>

using namespace std;

#include <cstdio>
typedef long long LL;

LL GCD(LL a, LL b)
{
	LL mod;
	while (mod = a % b)
	{
		a = b;
		b = mod;
	}
	return b;
}
struct Fra
{
	LL de, nu;
	void reduce()
	{
		LL gcd = GCD(de,nu);
		de /= gcd;
		nu /= gcd;
	}
	bool sub(LL x)
	{
		nu -= de*x;
		if (nu == 0) return 0;
		reduce();
		return 1;
	}
	void trans()
	{
		LL t = de;
		de = nu;
		nu = t;
	}
	bool operator < (const int &x) const
	{
		if (nu < de) return 1;
		return nu < de*x;
	}
} f;
LL p, q;
int n;
LL a[100];
bool judge()
{
	for (int i = 0; i < n-1; ++ i)
	{
		if (f < a[i]) return 0;
		if (!f.sub(a[i])) return 0;
		//printf("%lld/%lld\n", f.nu, f.de);
		f.trans();
	}
	return (f.de == 1 && f.nu == a[n-1]);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while (scanf("%lld%lld",&p,&q) != EOF)
	{
		f.de = q;
		f.nu = p;
		f.reduce();
		scanf("%d",&n);
		for (int i = 0; i < n; ++ i)
		{
			scanf("%lld",&a[i]);
		}
		printf("%s\n", judge()?"YES":"NO");
	}
}