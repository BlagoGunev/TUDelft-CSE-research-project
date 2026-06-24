#include <bits/stdc++.h>
#define N 200010 
using namespace std;
typedef long long ll;
ll f[N];
int size[N];
char *p1,*p2,buf[100000];
#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int rd() {int x=0,f=1; char c=nc(); while(c<48) {if(c=='-') f=-1; c=nc();} while(c>47) x=(((x<<2)+x)<<1)+(c^48),c=nc(); return x*f;}
int num[N],to[N<<1],nxt[N<<1],head[N],tot;
inline void add(int x,int y) {to[++tot]=y; nxt[tot]=head[x]; head[x]=tot;}
void dfs(int p,int fa)
{
	size[p]=1;
	for(int i=head[p];i;i=nxt[i]) if(to[i]!=fa)
	{
		dfs(to[i],p);
		size[p] += size[to[i]];
		f[p] += f[to[i]];
	}
	f[p] += size[p];
}
ll ans=0;
int n;
void dfs2(int p,int fa)
{
	ans=max(ans,f[p]);
	for(int i=head[p];i;i=nxt[i]) if(to[i]!=fa)
	{
		ll f_p=f[p]-size[to[i]]-f[to[i]];
		f[to[i]] = f[to[i]] - size[to[i]] + n + f_p;
		dfs2(to[i],p);
	}
}
int main()
{
	n=rd();
	for(int i=1;i<n;i++) {int x=rd(),y=rd(); add(x,y),add(y,x);}
	dfs(1,1);
	dfs2(1,1);
	cout << ans << endl ;
	return 0;
}