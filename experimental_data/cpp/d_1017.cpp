#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define gc getchar()
#define lint long long
#define debug(x) cerr<<#x<<"="<<x
#define sp <<" "
#define ln endl
#define S 10010
using namespace std;
inline int inn()
{
	int x,ch;while((ch=gc)<'0'||ch>'9');
	x=ch^'0';while((ch=gc)>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+(ch^'0');return x;
}
int cnt[S],ans[S],val[S][110],w[100];
int main()
{
	int n=inn(),m=inn(),q=inn();
	for(int i=1;i<=n;i++) w[i]=inn();
	for(int i=1;i<=m;i++)
	{
		int v=0;
		for(int j=0;j<n;j++)
		{
			int x;while((x=gc)!='0'&&x!='1');
			v|=(x-'0')<<j;
		}
		cnt[v]++;
	}
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
			if(!((i>>j)&1)) ans[i]+=w[j+1];
		ans[i]=min(ans[i],101);
	}
	for(int i=0;i<(1<<n);i++)
		for(int j=0;j<(1<<n);j++)
			val[i][ans[i^j]]+=cnt[j];
	for(int i=0;i<(1<<n);i++)
		for(int j=1;j<=100;j++)
			val[i][j]+=val[i][j-1];
	while(q--)
	{
		int v=0;
		for(int j=0;j<n;j++)
		{
			int x;while((x=gc)!='0'&&x!='1');
			v|=(x-'0')<<j;
		}
		int k=inn();printf("%d\n",val[v][k]);
	}
	return 0;
}