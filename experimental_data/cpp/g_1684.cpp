#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x)
{
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
template <typename T,typename ...Args>void read(T &x,Args&...args){read(x),read(args...);}
template <typename T> void print(T x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) print(x/10);
	putchar(x%10+48);
}
template <typename T> void print(T x,char c){print(x); putchar(c);}
const int N=1007,inf=0x3f3f3f3f;
int n,s,t,cnt=1,h[N],d[N],now[N],maxflow,pos;
long long a[N],m;
struct edge{int to,nxt,w;}mp[N*N<<1];
void add(int x,int y,int z)
{
	cnt++;
	mp[cnt].nxt=h[x];
	mp[cnt].to=y;
	mp[cnt].w=z;
	h[x]=cnt;
}
queue<int>q;
bool BFS()//BFS对残量网络分层
{
	memset(d,0,sizeof d);// d 为节点在分层图中的深度
	while(q.size()) q.pop();
	q.push(s); d[s]=1; now[s]=h[s];// now 为当前弧优化数组
	while(q.size())//普通BFS
	{
		auto x=q.front(); q.pop();
		for(int i=h[x];i;i=mp[i].nxt)
			if(mp[i].w&&!d[mp[i].to])
			{
				q.push(mp[i].to); d[mp[i].to]=d[x]+1;
				now[mp[i].to]=h[mp[i].to];
				if(mp[i].to==t) return true;
			}
	}
	return false;
}
int dinic(int x,int flow)
{
	if(x==t) return flow;
	int res=flow,k,i;
	for(i=now[x];i&&res;i=mp[i].nxt)
	{
		now[x]=i;//当前弧优化,意思是我去过的点,我就不在去了
		//实现当前弧优化的办法很多,推荐写引用
		if(mp[i].w&&d[mp[i].to]==d[x]+1)
		{
			k=dinic(mp[i].to,min(res,mp[i].w));
			if(!k) d[mp[i].to]=0;//删除增广完毕的点
			mp[i].w-=k; mp[i^1].w+=k; res-=k;
		}
	}
	return flow-res;
}
void link(int x,int y,int z)
{
	add(x,y,z);
	add(y,x,0);
}
int main()
{
	read(n,m); s=n+1,t=n+2; pos=n;
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1); reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++) if(a[i]*3<=m){pos=i-1;break;}
	for(int i=1;i<=pos;i++) link(s,i,1);
	for(int i=pos+1;i<=n;i++) link(i,t,1);
	for(int i=1;i<=pos;i++)
		for(int j=pos+1;j<=n;j++)
		{
			if(a[i]*2+a[j]>m) continue;
			if(a[i]%a[j]==0) link(i,j,1);
		}
	int flow;
	while(BFS()) while(flow=dinic(s,inf)) maxflow+=flow;
	if(maxflow!=pos) return puts("-1"),0;
	print(n-pos,'\n');
	for(int i=2;i<=cnt;i+=2)
	{
		int x=mp[i^1].to,y=mp[i].to;
		if(x==s) continue;
		if(y==t)
		{
			if(mp[i].w)
				print(a[x]*3,' '),print(a[x]*2,'\n');
			continue;
		}
		if(!mp[i].w) print(a[x]*2+a[y],' '),print(a[x]+a[y],'\n');
	}
	return 0;
}
//slenbol