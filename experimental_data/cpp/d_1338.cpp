// LUOGU_RID: 93544350
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=1e5+10,M=N<<1;
int head[N],ver[M],nxt[M],tot=0;
void add(int x,int y)
{
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int f[N][2],ans=0;
void dfs(int x,int fa)
{
	int cnt=0,mx0=-1,mx1=-1;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];if(y==fa)continue;
		dfs(y,x),cnt++;

	}
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];if(y==fa)continue;
		if(~mx0)
		{
//			printf("x=%d, y=%d\n",x,y);
			ans=max(ans,mx0+f[y][0]+1);
			ans=max(ans,max(mx0,mx1)+max(f[y][1],f[y][0])+cnt-2+!!fa);
		}
		mx0=max(mx0,f[y][0]);
		mx1=max(mx1,f[y][1]);
		f[x][1]=max(f[x][1],f[y][0]+1);
		f[x][0]=max(f[x][0],max(f[y][0],f[y][1])+cnt-1);
	}
//	printf("f[%d]=(%d, %d)\n",x,f[x][0],f[x][1]);
	if(!cnt)f[x][1]=1;
	ans=max(ans,max(f[x][0],f[x][1]));
}
int main()
{
	int n=read();
	for(int i=1;i<n;i++){int u=read(),v=read();add(u,v),add(v,u);}
	dfs(1,0);printf("%d\n",ans);
	return 0;
}