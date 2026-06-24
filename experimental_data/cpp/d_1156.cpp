#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int gi()
{
	char c; int x=0,f=1;
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+c-'0';
	return x*f;
}
const int N=200005;
int f[2][N],s[2][N];
int findset(int u, int w)
{
	if(f[w][u]==u) return u;
	return f[w][u]=findset(f[w][u],w);
}
void unionset(int u, int v, int w)
{
	int fu=findset(u,w),fv=findset(v,w);
	s[w][fu]+=s[w][fv];
	f[w][fv]=fu;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("d.in","r",stdin);
#endif
	int n=gi();
	for(int i=0;i<2;++i)
		for(int j=1;j<=n;++j) f[i][j]=j,s[i][j]=1;
	for(int i=1;i<n;++i)
	{
		int u=gi(),v=gi(),w=gi();
		unionset(u,v,w);
	}
	long long ans=0;
	for(int i=1;i<=n;++i)
		ans+=1ll*s[0][findset(i,0)]*s[1][findset(i,1)];
	printf("%I64d",ans-n);
}