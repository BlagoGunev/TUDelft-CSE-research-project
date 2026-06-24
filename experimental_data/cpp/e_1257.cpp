# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cmath>
# include <string>
# include <cstring>
# include <iomanip>
# include <functional>
# include <numeric>
# include <map>
# include <cstdlib>
# include <queue>
# include <cctype>
using namespace std;
template <class code>inline code read(const code &a)
{
    code x=0;short w=0;char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return w?-x:x;
}
const int N=2e5+5;
const int M=1<<30;
int a[N];
int k[5];
int f[N],g[N];
int res[N];
int main ()
{
	for (int i=1;i<=3;i++)
	    k[i]=read (k[i]);
	int n=k[1]+k[2]+k[3];
	for (int i=1;i<=3;i++)
	{
		for (int j=1;j<=k[i];j++)
		{
			int x=read (x);
			a[x]=i;
		}
	}
	for (int i=1;i<=n;i++)
		f[i]=f[i-1]+(a[i]!=1);
	for (int i=n;i>=1;i--)
	    g[i]=g[i+1]+(a[i]!=3);
	for (int i=n;i>=1;i--)
		res[i]=min (min (g[i],g[i+1]+(a[i]!=2)),res[i+1]+(a[i]!=2));
	int ans=M;
	for (int i=0;i<=n;i++)
		ans=min (ans,f[i]+res[i+1]);
	printf ("%d\n",ans);
	return 0;
}