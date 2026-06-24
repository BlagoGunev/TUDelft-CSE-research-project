#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define N 5005
using namespace std;
inline int read()
{
    register int x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int a[N],sum[N];
int main()
{
	int n=read();
	for(register int i=1;i<=n;++i)
		a[i]=read(),sum[i]=sum[i-1]+a[i];
	for(register int i=n;i;--i)
	{
		for(register int j=i;j<=n;++j)
		{
			int x=sum[j]-sum[j-i];
			if(x>i*100)
			{
				printf("%d",i);
				return 0;
			}
		}
	}
	puts("0");
	return 0;
}