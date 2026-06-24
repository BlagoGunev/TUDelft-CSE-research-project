#include<iostream>
#include<cstdio>
#define N 10000000
using namespace std;
int read()
{
	char c=0;
	int sum=0;
	while (c<'0'||c>'9') c=getchar();
	while ('0'<=c&&c<='9') sum=sum*10+c-'0',c=getchar();
	return sum;
}
char readchar()
{
	char c=0;
	while (c<'a'||c>'z') c=getchar();
	return c;
}
int T,n,m,dque[N+1],l,r,dque2[N+1],l2,r2,z[N+1],h[N+1],h2[N+1];
char a[N+1],b[N+1],c[N+1];
void build()
{
	int l=0;
	z[1]=n+m;
    for (int i=2;i<=n+m;++i)
    {
		if (z[l]+l-i>0) z[i]=min(z[i-l+1],z[l]+l-i);
		else z[i]=0;
		while (i+z[i]<=n+m&&c[z[i]+1]==c[i+z[i]]) z[i]++;
		if (z[i]+i>z[l]+l) l=i;
    }
	return;
}
bool check(int x)
{
	for (int i=0;i<=m/n;++i)
		if ((m-n*i)%x==0||(m-n*i)%(n-x)==0)
			return 1;
	return 0;
}
int main()
{
	int top;
	bool op;
	T=read();
	while (T--)
	{
		n=read(),m=read(),op=1;
		for (int i=1;i<=n;++i) a[i]=readchar();
		for (int i=1;i<=m;++i) b[i]=readchar();
		for (int i=1;i<=n;++i) c[i]=a[i],op&=(a[i]==a[1]);
		for (int i=1;i<=m;++i) c[n+i]=b[i];
		build();
		for (int i=1;i<=m;++i) h[i]=z[n+i];
		for (int i=1;i<=n;++i) c[i]=a[n-i+1];
		for (int i=1;i<=m;++i) c[n+i]=b[m-i+1];
		build();
		for (int i=1;i<=m;++i) h2[i]=z[n+m-i+1];
		if (op)
		{
			for (int i=1;i<=m;++i) op&=(b[i]==a[1]);
			if (!op)
			{
				for (int i=1;i<=n-1;++i) printf("0");
				puts("");
			}
			else
			{
				for (int i=1;i<=n-1;++i) printf("%d",check(i));
				puts("");
			}
		}
		else
		{
			for (int i=1;i<=n-1;++i)
			{
				if (check(i))
				{
					dque[l=r=1]=op=0,l2=1,r2=0;
					while (l<=r||l2<=r2)
					{
						if (l<=r&&(l2>r2||dque[l]<dque2[l2])) top=dque[l++];
						else top=dque2[l2++];
						if (top==m)
						{
							op=1;
							break;
						}
						if (top+i<=m&&h[top+1]>=i&&dque[r]!=top+i) dque[++r]=top+i;
						if (top+n-i<=m&&h2[top+n-i]>=n-i&&dque2[r2]!=top+n-i) dque2[++r2]=top+n-i;
					}
					printf("%d",op);
				}
				else printf("0");
			}
			puts("");
		}
	}
	return 0;
}