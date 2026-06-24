#include<cstring>
#include<iostream>
#include<cctype>
#include<cstdio>
#include<algorithm>
#define writ(x,c) write(x),putchar(c);
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
    char c;int x=0;bool f=0;
    for(;!isdigit(c);c=nc()) if(c=='-') f=1;
    for(;isdigit(c);c=nc()) x=(x<<1)+(x<<3)+c-48;
    return (f ? -x : x);
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int N=2e5+5;
struct edge
{
	int v,next;
}e[N<<1];
int head[N],tot,n;
int stk[N],tail;
bool vis[N];
void add(int u,int v)
{
	e[++tot].v=v,e[tot].next=head[u],head[u]=tot;
}
void dfs(int u)
{
	vis[u]=1;stk[++tail]=u;
	if(u==n)
	{
		for(int i=1;i<=tail;i++)
			writ(stk[i],' ');
	}
	for(int i=head[u];i;i=e[i].next)
	{
		if(!vis[e[i].v])
		{
			dfs(e[i].v);
			tail--;
		}
	}
}
int main()
{
	n=read();
	for(int i=2;i<=n;i++)
	{
		int v=read();add(i,v),add(v,i);
	}
	dfs(1);
}