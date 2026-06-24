#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[100010],k,r;
double p,ans;
inline int read()
{
	int num=0,flag=1;
	char c=getchar();
	for (;c<'0'||c>'9';c=getchar())
	if (c=='-') flag=-1;
	for (;c>='0'&&c<='9';c=getchar())
	num=(num<<3)+(num<<1)+c-48;
	return num*flag;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	t=read();
	for (int i=1;i<=t;++i)
	{
		n=read();
		m=read();
		for (int j=1;j<=n;++j)
		a[j]=read();
		k=0;
		for (int j=n;j>=1;--j)
		if (a[j]!=j)
		{
			k=j;
			break;
		}
		ans=1;
		for (int j=1;j<=m;++j)
		{
			r=read();
			scanf("%lf",&p);
			if (r>=k) ans*=1-p;
		}
		if (!k) printf("1.000000\n");
		else printf("%.6lf\n",1-ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}