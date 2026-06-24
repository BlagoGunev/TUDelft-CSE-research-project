#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
inline int read()
{
	register char c=getchar();
	register long long x=0,f=1;
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return x*f;
}
int a[maxn],p[110];
int main()
{
	int t; 
	cin>>t;
	while(t--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			p[a[i]]++;
		}
		int mn=0x3f3f3f3f;
		if(n==0)
			mn=0;
		for(int i=1;i<=100;i++)
		{
			int s=0;
			for(int j=1;j<=n;j++)
			{
				if(a[j]!=i)
					j+=k-1,s++;
			}
			mn=min(mn,s);
		}
		printf("%d\n",mn);
	}
}