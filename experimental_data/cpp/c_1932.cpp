#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k,l,t,ans[200010],a[200010];
char s[200010];
void dfs(int x,int l,int r)
{
	if(x==n)
	{
		ans[x]=1;
		return;
	}
	int t;
	if(s[x]=='L') t=a[l++];
	else t=a[r--];
	dfs(x+1,l,r);
	ans[x]=ans[x+1]*t%m;
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	scanf(" %s",s);
	dfs(0,0,n-1);
	for(int i=0;i<n;++i) printf("%d ",ans[i]);
	putchar('\n');
}
int main()
{
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}